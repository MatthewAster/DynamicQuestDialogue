// Fill out your copyright notice in the Description page of Project Settings.

#include "cNPCQuestGiver.h"

AcNPCQuestGiver::AcNPCQuestGiver() {

}

UFUNCTION(BlueprintCallable)AcQuest* AcNPCQuestGiver::getQuestToGive()
{
	return questToGive;
}

UFUNCTION(BlueprintCallable)AcQuest* AcNPCQuestGiver::setQuestToGive(AcQuest* newQuestToGive)
{
	questToGive = newQuestToGive;
	return questToGive;
}

UFUNCTION(BlueprintCallable) bool AcNPCQuestGiver::getIsQuestTaken()
{
	return isQuestTaken;
}

UFUNCTION(BlueprintCallable) bool AcNPCQuestGiver::setIsQuestTaken(bool newIsQuestTaken)
{
	isQuestTaken = newIsQuestTaken;
	return isQuestTaken;
}

//Called when the player character interacts with the NPC
UFUNCTION(BlueprintCallable) void AcNPCQuestGiver::onInteract(AcQuest* playerQuest)
{

	if (questToGive == playerQuest) {

		if (playerQuest->cObjectives.IsValidIndex(objectiveIndex)) {

			if (playerQuest->cObjectives[objectiveIndex]->getIsActiveObjective()) {

				playerQuest->completeObjectiveAtIndex(objectiveIndex);

			}

		}

	}

}
