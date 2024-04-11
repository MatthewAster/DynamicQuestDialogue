// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "cObjective.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RPGQUESTPROJECT_API UcObjective : public UObject
{
	GENERATED_BODY()
public:
	UcObjective();

public:
	//Getters & Setters
	UFUNCTION(BlueprintCallable)FText getObjectiveText();
	UFUNCTION(BlueprintCallable)FText setObjectiveText(FText newObjectiveText);

	UFUNCTION(BlueprintCallable)bool getIsCompleted();
	UFUNCTION(BlueprintCallable)bool setIsCompleted(bool newIsCompleted);

	UFUNCTION(BlueprintCallable)bool getIsActiveObjective();
	UFUNCTION(BlueprintCallable)bool setIsActiveObjective(bool newIsActiveObjective);

	UFUNCTION(BlueprintCallable)int getObjectiveIndex();
	UFUNCTION(BlueprintCallable)int setObjectiveIndex(int newObjectiveIndex);

	UFUNCTION(BlueprintCallable)bool getHasSubObjectives();
	UFUNCTION(BlueprintCallable)bool setHasSubObjectives(bool newHasSubObjectives);

	UFUNCTION(BlueprintCallable) int getNumSubObjectivesToComplete();
	UFUNCTION(BlueprintCallable) int setNumSubObjectivesToComplete(int newNumSubObjectivesToComplete);


private:
	//Used to keep track of objectives
	UPROPERTY(VisibleAnywhere) bool isCompleted = false;

	//Used to keep track of objectives
	UPROPERTY(VisibleAnywhere) bool isActiveObjective = false;

	//Text displayed on the sidebar widget.
	UPROPERTY(EditAnywhere) FText objectiveText;

	//Index of the objective in parentQuest->objectives. Used to keep track of objectives.
	UPROPERTY(EditAnywhere) int objectiveIndex;

	UPROPERTY(VisibleAnywhere) bool hasSubObjectives = false;

	UPROPERTY(VisibleAnywhere) int numSubObjectivesToComplete;

};
