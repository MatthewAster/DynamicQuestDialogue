// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "cFetchQuestTarget.h"
#include "CoreMinimal.h"
#include "cQuest.h"
#include "cQuestFetch.generated.h"

/**
 * 
 */
UCLASS()
class RPGQUESTPROJECT_API AcQuestFetch : public AcQuest
{
	GENERATED_BODY()

public:
	/* Called when the quest is accepted from dialogue with the quest giver.
	enables visibility and collision of the fetch target */
	UFUNCTION(BlueprintCallable) void onAcceptFetch();
	
public:
	//Object(s) of type FetchQuestTarget that player is asked to fetch
	UPROPERTY(EditAnywhere) TArray<AcFetchQuestTarget*> target;

};
