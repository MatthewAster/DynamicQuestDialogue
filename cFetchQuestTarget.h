// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "cQuest.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cFetchQuestTarget.generated.h"

UCLASS()
class RPGQUESTPROJECT_API AcFetchQuestTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcFetchQuestTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Called when player interacts with the actor, used to complete the fetch objective
	UFUNCTION(BlueprintCallable) void onInteract();

	//Quest that the target is a part of
	UPROPERTY(EditAnywhere) AcQuest* parentQuest;

	UPROPERTY(EditAnywhere) UStaticMeshComponent* staticMesh;

	//Index of the objective to interact with the target
	UPROPERTY(EditAnywhere) int fetchObjectiveIndex = 0;

};
