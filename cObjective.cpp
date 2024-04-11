// Fill out your copyright notice in the Description page of Project Settings.


#include "cObjective.h"

UcObjective::UcObjective() {

	isCompleted = false;
	isActiveObjective = false;

}

FText UcObjective::getObjectiveText()
{
	return objectiveText;
}

FText UcObjective::setObjectiveText(FText newObjectiveText)
{

	if (!newObjectiveText.IsEmpty()) {
			objectiveText = newObjectiveText;
			return objectiveText;
	}
	else {

			return objectiveText;

	}

		return newObjectiveText;

}

bool UcObjective::getIsCompleted()
{
	return isCompleted;
}

bool UcObjective::setIsCompleted(bool newIsCompleted)
{
	isCompleted = newIsCompleted;
	return isCompleted;
}

bool UcObjective::getIsActiveObjective()
{

	return isActiveObjective;

}

bool UcObjective::setIsActiveObjective(bool newIsActiveObjective)
{

		isActiveObjective = newIsActiveObjective;
		return isActiveObjective;

}

int UcObjective::getObjectiveIndex()
{
	return objectiveIndex;
}

int UcObjective::setObjectiveIndex(int newObjectiveIndex)
{
	objectiveIndex = newObjectiveIndex;
	return objectiveIndex;
}

UFUNCTION(BlueprintCallable) bool UcObjective::getHasSubObjectives()
{
	return hasSubObjectives;
}

UFUNCTION(BlueprintCallable) bool UcObjective::setHasSubObjectives(bool newHasSubObjectives)
{
	hasSubObjectives = newHasSubObjectives;
	return hasSubObjectives;
}

UFUNCTION(BlueprintCallable) int UcObjective::getNumSubObjectivesToComplete()
{
	return numSubObjectivesToComplete;
}

UFUNCTION(BlueprintCallable) int UcObjective::setNumSubObjectivesToComplete(int newNumSubObjectivesToComplete)
{
	numSubObjectivesToComplete = newNumSubObjectivesToComplete;
	return numSubObjectivesToComplete;
}
