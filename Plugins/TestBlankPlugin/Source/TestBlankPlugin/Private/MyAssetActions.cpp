#include "CoreMinimal.h"
#include "MyAssetActions.h"
#include "MyAsset.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FMyAssetActions::FMyAssetActions(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{
}


FMyAssetActions::~FMyAssetActions()
{
}

FText FMyAssetActions::GetName() const
{
	return LOCTEXT("FMyAssetActionsName","MyAsset");
}

UClass * FMyAssetActions::GetSupportedClass() const
{
	return UMyAsset::StaticClass();
}

FColor FMyAssetActions::GetTypeColor() const
{
	return FColor(201,29,85);
}

uint32 FMyAssetActions::GetCategories()
{
	return MyAssetCategory/*EAssetTypeCategories::Gameplay*/;
}

void FMyAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{

}
