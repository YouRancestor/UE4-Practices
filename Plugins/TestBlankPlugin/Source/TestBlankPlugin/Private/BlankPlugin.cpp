// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "MyAssetActions.h"
#include "MyAsset.h"
#include "IBlankPlugin.h"


#define LOCTEXT_NAMESPACE "TestPlugin"


class FBlankPlugin : public IBlankPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


public:
	FBlankPlugin()
		: MyAssetCategoryBit(EAssetTypeCategories::Misc)
	{}

private:
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
	{
		AssetTools.RegisterAssetTypeActions(Action);
		CreatedAssetTypeActions.Add(Action);
	}

	EAssetTypeCategories::Type MyAssetCategoryBit;
	/** All created asset type actions.  Cached here so that we can unregister them during shutdown. */
	TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;

};

IMPLEMENT_MODULE( FBlankPlugin, BlankPlugin )



void FBlankPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	// Register asset types
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	MyAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("TestAsset")), LOCTEXT("MyAssetCategory", "TestAsset"));

	RegisterAssetTypeAction(AssetTools, MakeShareable(new FMyAssetActions(MyAssetCategoryBit)));

}


void FBlankPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	// Unregister all the asset types that we registered
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); ++Index)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();


}



#undef LOCTEXT_NAMESPACE
