#pragma once


#include "Developer/AssetTools/Public/AssetTypeActions_Base.h"


class FMyAssetActions :
	public FAssetTypeActions_Base
{

	EAssetTypeCategories::Type MyAssetCategory;

public:
	FMyAssetActions(EAssetTypeCategories::Type InAssetCategory);
	~FMyAssetActions();

	// Í¨¹ý FAssetTypeActions_Base ¼Ì³Ð
	virtual FText GetName() const override;
	virtual UClass * GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;

	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
};

