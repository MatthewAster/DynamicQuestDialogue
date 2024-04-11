// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "cQuest.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "cNPC.generated.h"

UCLASS()
class RPGQUESTPROJECT_API AcNPC : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcNPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable) void onInteractTemp();

	UFUNCTION(BlueprintCallable) int getHealth();
	UFUNCTION(BlueprintCallable) int setHealth(int newHealth);

	UFUNCTION(BlueprintCallable) AcQuest* getParentQuest();

	UFUNCTION(BlueprintCallable) FString getName();
	UFUNCTION(BlueprintCallable) FString setName(FString newName);

	UFUNCTION(BlueprintCallable) bool getIsHostile();
	UFUNCTION(BlueprintCallable) bool setIsHostile(bool newIsHostile);

	UFUNCTION(BlueprintCallable) int getTargetObjectiveIndex();
	UFUNCTION(BlueprintCallable) int setTargetObjectiveIndex(int newTargetObjectiveIndex);

	UFUNCTION(BlueprintCallable) int getSubObjectiveIndex();
	UFUNCTION(BlueprintCallable) int setSubObjectiveIndex(int newSubObjectiveIndex);

	UPROPERTY(EditAnywhere) FString name;

	UPROPERTY(EditAnywhere) int health;

	UPROPERTY(EditAnywhere) AcQuest* parentQuest;

	//index of the objective to talk/kill/etc the npc
	UPROPERTY(EditAnywhere) int targetObjectiveIndex = 0;

	//if the npc gives you another objective of the quest to complete, the index of it in the quest objectives
	UPROPERTY(EditAnywhere) int subObjectiveIndex = 0;

	UPROPERTY(EditAnywhere) bool isHostile = false;

};
