// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "MenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICES_API AMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	/** 在游戏开始时调用。 */
	virtual void BeginPlay() override;

	/** 移除当前菜单控件，并且如果可能，从指定类中创建新控件。 */
	UFUNCTION(BlueprintCallable, Category = "UMG Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:

	/** 在游戏开始时我们将作为菜单使用的控件类。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	/** 用作为菜单的控件实例。 */
	UPROPERTY()
	UUserWidget* CurrentWidget;
	
};
