
#include "CoreMinimal.h"
#include "MyAssetFactory.h"
#include "MyAsset.h"


bool UMyAssetFactory::CanCreateNew() const
{
	return true;
}

UObject * UMyAssetFactory::FactoryCreateNew(UClass * InClass, UObject * InParent, FName InName, EObjectFlags Flags, UObject * Context, FFeedbackContext * Warn)
{
	return NewObject<UMyAsset>(InParent,InClass, InName, Flags|RF_Transactional);
}

UMyAssetFactory::UMyAssetFactory(const FObjectInitializer& ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UMyAsset::StaticClass();
}


UMyAssetFactory::~UMyAssetFactory()
{
}
