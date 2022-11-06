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

void UGlobalCustomVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
}

void UGlobalCustomVariable::Load()
{
	if (!UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		return;
	}

	const UGlobalCustomVariable* SavedData = Cast<UGlobalCustomVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	if (!SavedData)
	{
		return;
	}

	// StructData = SavedData->StructData;
}

void UGlobalCustomVariable::CleanBeforeStructChange()
{
	RowsSerializedWithTags.Reset();
	{
		class FRawStructWriter : public FObjectWriter
		{
			TSet<TObjectPtr<UObject>>& TemporarilyReferencedObjects;

		public:
			FRawStructWriter(TArray<uint8>& InBytes, TSet<TObjectPtr<UObject>>& InTemporarilyReferencedObjects)
				: FObjectWriter(InBytes), TemporarilyReferencedObjects(InTemporarilyReferencedObjects)
			{
			}
			virtual FArchive& operator<<(class UObject*& Res) override
			{
				FObjectWriter::operator<<(Res);
				TemporarilyReferencedObjects.Add(Res);
				return *this;
			}
		};

		FRawStructWriter MemoryWriter(RowsSerializedWithTags, TemporarilyReferencedObjects);
		SaveStructData(FStructuredArchiveFromArchive(MemoryWriter).GetSlot());
	}

	Modify();
}

void UGlobalCustomVariable::RestoreAfterStructChange()
{
	{
		class FRawStructReader : public FObjectReader
		{
		public:
			FRawStructReader(TArray<uint8>& InBytes) : FObjectReader(InBytes)
			{
			}
			virtual FArchive& operator<<(class UObject*& Res) override
			{
				UObject* Object = nullptr;
				FObjectReader::operator<<(Object);
				FWeakObjectPtr WeakObjectPtr = Object;
				Res = WeakObjectPtr.Get();
				return *this;
			}
		};

		FRawStructReader MemoryReader(RowsSerializedWithTags);
		LoadStructData(FStructuredArchiveFromArchive(MemoryReader).GetSlot());
	}
	TemporarilyReferencedObjects.Empty();
	RowsSerializedWithTags.Empty();
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

		// Load row data
		uint8* RowData = (uint8*) FMemory::Malloc(LoadUsingStruct->GetStructureSize());

		// And be sure to call DestroyScriptStruct later
		LoadUsingStruct->InitializeStruct(RowData);

		LoadUsingStruct->SerializeItem(RowRecord.EnterField(SA_FIELD_NAME(TEXT("Value"))), RowData, nullptr);

		StructDataPtr = RowData;
		// StructData = TArrayView<uint8>(RowData, static_cast<int32>(LoadUsingStruct->GetStructureSize()));
	}
}
