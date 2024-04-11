// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "Kismet/GameplayStatics.h"
#include "cObjective.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cQuest.generated.h"

UCLASS()
	class RPGQUESTPROJECT_API AcQuest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AcQuest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	Initializes objective objects on BeginPlay(). Any objectives that don't have objectiveText associated with them
	will be removed from objectives
	*/
	void constructObjectives();

	//Called when the quest is accepted from the dialogue tree
	UFUNCTION(BlueprintCallable) virtual void onAccept();

	/*Called when an objective condition has been completed, only completes if
	the objectiveToComplete is an active objective*/
	UFUNCTION(BlueprintCallable) bool completeObjective(UcObjective* objectiveToComplete);
	
	/*Called when an objective condition has been completed, only completes if
	the objective at objectiveToCompleteIndex is an active objective*/
	UFUNCTION(BlueprintCallable) bool completeObjectiveAtIndex(int objectiveToCompleteIndex);

	//Checks if the quest is complete, called in the startDialogue event of the NPC dialogue tree
	UFUNCTION(BlueprintCallable) bool checkCompletion();


public:
	//Getters  Setters
	UFUNCTION(BlueprintCallable) bool getresetSideBar();
	UFUNCTION(BlueprintCallable) bool setresetSideBar(bool newresetSideBar);

	AActor* getQuestGiver();
	AActor* setQuestGiver(AActor* newQuestGiver);

	UFUNCTION(BlueprintCallable) FString getName();
	UFUNCTION(BlueprintCallable) FString setName(FString newName);

	UFUNCTION(BlueprintCallable)FString getDetails();
	UFUNCTION(BlueprintCallable)FString setDetails(FString newDetails);

	UFUNCTION(BlueprintCallable)UcObjective* getActiveObjective();
	UFUNCTION(BlueprintCallable)TArray<UcObjective*> getObjectives();

	UFUNCTION(BlueprintCallable)bool getIsTaken();
	UFUNCTION(BlueprintCallable)bool setIsTaken(bool newIsTaken);

	UFUNCTION(BlueprintCallable)int getExperienceReward();
	UFUNCTION(BlueprintCallable)int setExperienceReward(int newExperienceReward);

	UFUNCTION(BlueprintCallable)int getGoldReward();
	UFUNCTION(BlueprintCallable)int setGoldReward(int newGoldReward);

	UFUNCTION(BlueprintCallable)int getObjectiveIndex();
	UFUNCTION(BlueprintCallable)int setObjectiveIndex(int newObjectiveIndex);
	
	UFUNCTION(BlueprintCallable)int getQuestIndex();
	UFUNCTION(BlueprintCallable)int setQuestIndex(int newQuestIndex);

	UFUNCTION(BlueprintCallable)bool getIsCompleted();
	UFUNCTION(BlueprintCallable)bool setIsCompleted(bool newIsCompleted);

	UFUNCTION(BlueprintCallable)bool getDisplayAllObjectives();
	UFUNCTION(BlueprintCallable)bool setDisplayAllObjectives(bool newDisplayAllObjectives);

	UFUNCTION(BlueprintCallable) TArray<FText> getObjectiveText();

	UFUNCTION(BlueprintCallable) TArray<int> getNumSubObjectives();

	UFUNCTION(BlueprintCallable) FText setMultiObjectiveText(FText initialText, int changingObjectiveValue, int totalNumberOfObjectives);

	UPROPERTY(VisibleAnywhere) TArray<UcObjective*> cObjectives;


private:
	//Which NPC is giving this quest?
	UPROPERTY(EditAnywhere) AActor* questGiver;

	/*Every objective needs to have an objectiveText at the corresponding index or they will be deleted. See contructObjectives().
	To create objectives, create text for it and call completeObjectiveAtIndex() with the index of the objectiveText
	wherever the completion conditions are met*/
	UPROPERTY(EditAnywhere) TArray<FText> objectiveText;

	//Number of sub objectives associated with the objective of the same index. If there are no sub objectives, set the corresponding array element to 0
	UPROPERTY(EditAnywhere) TArray<int> numSubObjectives;

	//Used by journal widget and sidebar widget
	UPROPERTY(EditAnywhere) FString name;
	//Used by journal widget and sidebar widget
	UPROPERTY(EditAnywhere) FString details;

	//Used by the dialogue tree to determine what dialogue to show
	UPROPERTY(VisibleAnywhere) bool isTaken = false;

	//Gold reward is displayed in dialogue of the quest giver. Experience reward not displayed anywhere.
	UPROPERTY(EditAnywhere) int experienceReward = 0;
	UPROPERTY(EditAnywhere) int goldReward = 0;

	//Index of this quest in the player's activeQuests, set in the giveQuest event of the NPC dialogue tree
	UPROPERTY(VisibleAnywhere) int questIndex = 0;
	//Index of the currently active objective, incremented in completeObjectiveAtIndex()
	UPROPERTY(VisibleAnywhere) int objectiveIndex = 0;
	UPROPERTY(VisibleAnywhere) bool isCompleted = false;

	//Called by the sideBar widget on a timer to determine if the widget should be updated. Set in completeObjectiveAtIndex()
	UPROPERTY(VisibleAnywhere) bool resetSideBar = false;

	//Displays objectives in a list on the side bar rather than one at a time
	UPROPERTY(EditAnywhere) bool displayAllObjectives = false;

};