// Fill out your copyright notice in the Description page of Project Settings.


#include "cFetchQuestTarget.h"

// Sets default values
AcFetchQuestTarget::AcFetchQuestTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcFetchQuestTarget::BeginPlay()
{
	Super::BeginPlay();

	if (staticMesh->IsValidLowLevel()) {

		NewObject<UStaticMeshComponent>(staticMesh, "StaticMesh", RF_NoFlags, staticMesh, false, nullptr);
		staticMesh->SetVisibility(0);
		staticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}
	
}

// Called every frame
void AcFetchQuestTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Called when player interacts with the actor
void AcFetchQuestTarget::onInteract()
{

	if (parentQuest->cObjectives[fetchObjectiveIndex]->getIsActiveObjective()) {

		staticMesh->SetVisibility(0);
		staticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		parentQuest->completeObjectiveAtIndex(fetchObjectiveIndex);

	}

}

