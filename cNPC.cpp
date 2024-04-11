// Fill out your copyright notice in the Description page of Project Settings.


#include "cNPC.h"

// Sets default values
AcNPC::AcNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AcNPC::getName() {

	return name;

}

FString AcNPC::setName(FString newName) {

	name = newName;
	return name;

}

UFUNCTION(BlueprintCallable) bool AcNPC::getIsHostile()
{
	return isHostile;
}

UFUNCTION(BlueprintCallable) bool AcNPC::setIsHostile(bool newIsHostile)
{
	isHostile = newIsHostile;
	return isHostile;
}

UFUNCTION(BlueprintCallable) int AcNPC::getTargetObjectiveIndex()
{
	return targetObjectiveIndex;
}

UFUNCTION(BlueprintCallable) int AcNPC::setTargetObjectiveIndex(int newTargetObjectiveIndex)
{
	targetObjectiveIndex = newTargetObjectiveIndex;
	return targetObjectiveIndex;
}

UFUNCTION(BlueprintCallable) int AcNPC::getSubObjectiveIndex()
{
	return subObjectiveIndex;
}

UFUNCTION(BlueprintCallable) int AcNPC::setSubObjectiveIndex(int newSubObjectiveIndex)
{
	subObjectiveIndex = newSubObjectiveIndex;
	return subObjectiveIndex;
}

int AcNPC::getHealth()
{
	return health;
}

int AcNPC::setHealth(int newHealth)
{

	health = newHealth;
	return health;

}

void AcNPC::onInteractTemp() {
	
	if (isHostile) {
		health -= 25;

		if (health <= 0) {

			if (parentQuest->completeObjectiveAtIndex(targetObjectiveIndex)) {

				Destroy();

			}

		}

	}

}

AcQuest* AcNPC::getParentQuest() {

	return parentQuest;

}


