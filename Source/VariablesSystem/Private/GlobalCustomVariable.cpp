// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#include "GlobalCustomVariable.h"

#include "Serialization/ObjectReader.h"
#include "Serialization/ObjectWriter.h"

#include <Kismet/GameplayStatics.h>

FString UGlobalCustomVariable::GetSaveLocation() const
{
	// TODO: Check if this is unique if we have 2 variables with the same name, but in different location
	return GetName();
}

void UGlobalCustomVariable::SetStructType(TObjectPtr<UScriptStruct> InStructType)
{
	StructType = InStructType;

	StructDataPtr = static_cast<uint8*>(FMemory::Malloc(StructType->GetStructureSize()));
	StructType->InitializeStruct(StructDataPtr);
}

TObjectPtr<UScriptStruct> UGlobalCustomVariable::GetStructType() const
{
	return StructType;
}

uint8* UGlobalCustomVariable::GetDataPtr() const
{
	return StructDataPtr;
}

void UGlobalCustomVariable::Save()
{
	const int32 StructSize = StructType->GetStructureSize();
	StructSavedData.SetNumZeroed(StructSize);
	FMemory::Memcpy(StructSavedData.GetData(), StructDataPtr, StructSize);

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	StructSavedData.Empty();
}

void UGlobalCustomVariable::Load()
{
	if (!UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		return;
	}

	const UGlobalCustomVariable* SavedData = Cast<UGlobalCustomVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	if (!SavedData || SavedData->StructSavedData.IsEmpty())
	{
		return;
	}

	// release any memory we are currently holding
	FMemory::Free(StructDataPtr);

	StructDataPtr = static_cast<uint8*>(FMemory::Malloc(StructType->GetStructureSize()));
	StructType->InitializeStruct(StructDataPtr);
	FMemory::Memcpy(StructDataPtr, SavedData->StructSavedData.GetData(), SavedData->StructSavedData.Num());
}

void UGlobalCustomVariable::CleanBeforeStructChange()
{
	Save();
}

void UGlobalCustomVariable::RestoreAfterStructChange()
{
	Load();
}

void UGlobalCustomVariable::SaveStructData(FStructuredArchiveSlot Slot)
{
	UScriptStruct* SaveUsingStruct = StructType;

	int32 NumRows = 1;
	FStructuredArchiveArray Array = Slot.EnterArray(NumRows);

	{
		// Save out name
		FName RowName = TEXT("MyName");
		FStructuredArchiveRecord Row = Array.EnterElement().EnterRecord();
		Row << SA_VALUE(TEXT("Name"), RowName);

		// Save out data
		uint8* RowData = StructDataPtr;

		SaveUsingStruct->SerializeItem(Row.EnterField(SA_FIELD_NAME(TEXT("Value"))), RowData, nullptr);
	}
}

void UGlobalCustomVariable::LoadStructData(FStructuredArchiveSlot Slot)
{
	UScriptStruct* LoadUsingStruct = StructType;

	int32 NumRows;
	FStructuredArchiveArray Array = Slot.EnterArray(NumRows);

	{
		FStructuredArchiveRecord RowRecord = Array.EnterElement().EnterRecord();

		// Load row name
		FName RowName;
		RowRecord << SA_VALUE(TEXT("Name"), RowName);

		uint8* RowData = (uint8*) FMemory::Malloc(LoadUsingStruct->GetStructureSize());
		LoadUsingStruct->InitializeStruct(RowData);
		LoadUsingStruct->SerializeItem(RowRecord.EnterField(SA_FIELD_NAME(TEXT("Value"))), RowData, nullptr);

		StructDataPtr = RowData;
	}
}
