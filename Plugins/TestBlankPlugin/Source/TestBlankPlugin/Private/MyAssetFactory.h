#pragma once

#include "Classes/Factories/Factory.h"
#include "MyAssetFactory.generated.h"

UCLASS(hidecategories=Object)
class UMyAssetFactory :
	public UFactory
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = DataAsset)
	TSubclassOf<class UMyAsset> DataAssetClass;


	virtual bool CanCreateNew() const override;
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

public:
	UMyAssetFactory(const FObjectInitializer& ObjectInitializer);
	~UMyAssetFactory();
};

