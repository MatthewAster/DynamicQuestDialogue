// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "cQuest.h"
#include "CoreMinimal.h"
#include "cNPC.h"
#include "cNPCQuestGiver.generated.h"

/**
 * 
 */
UCLASS()
class RPGQUESTPROJECT_API AcNPCQuestGiver : public AcNPC
{
	GENERATED_BODY()
public:
	AcNPCQuestGiver();

public:
	//Getters & Setters

	UFUNCTION(BlueprintCallable) AcQuest* getQuestToGive();
	UFUNCTION(BlueprintCallable) AcQuest* setQuestToGive(AcQuest* newQuestToGive);

	UFUNCTION(BlueprintCallable) bool getIsQuestTaken();
	UFUNCTION(BlueprintCallable) bool setIsQuestTaken(bool newIsQuestTaken);

	//Called when the player character interacts with the NPC
	UFUNCTION(BlueprintCallable) void onInteract(AcQuest* playerQuest);

public:

	//Used by dialogue tree to determine what dialogue to use
	UPROPERTY(VisibleAnywhere) bool isQuestTaken;

	//If one of the objectives is to interact with the quest giver, this is the index of that objective EX: "Return to (questgiver)"
	UPROPERTY(EditAnywhere) int objectiveIndex = 0;

	UPROPERTY(EditAnywhere) AcQuest* questToGive;

};
