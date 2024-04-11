// Fill out your copyright notice in the Description page of Project Settings.


#include "cQuest.h"

// Sets default values
AcQuest::AcQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcQuest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcQuest::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

}

void AcQuest::constructObjectives()
{


	if (objectiveText.GetAllocatedSize() != 0) {

		for (int i = 0; i != objectiveText.Num(); i++) {

			cObjectives.Add(NewObject<UcObjective>(this));

			if (objectiveText[i].IsEmpty() && cObjectives.IsValidIndex(i)) {

				cObjectives.RemoveAt(i);

			}
			else if (cObjectives.IsValidIndex(i)) {

				cObjectives[i]->setObjectiveText(this->objectiveText[i]);

			}
			if (numSubObjectives.IsValidIndex(i) && cObjectives.IsValidIndex(i) && numSubObjectives[i] > 0) {

				cObjectives[i]->setNumSubObjectivesToComplete(numSubObjectives[i]);
				cObjectives[i]->setHasSubObjectives(true);
				cObjectives[i]->setObjectiveText(setMultiObjectiveText(cObjectives[i]->getObjectiveText(), cObjectives[i]->getNumSubObjectivesToComplete(), numSubObjectives[i]));

			}

		}

		cObjectives[0]->setIsActiveObjective(true);

	}


}

void AcQuest::onAccept()
{

	constructObjectives();

}

bool AcQuest::completeObjective(UcObjective* objectiveToComplete) {

	if (cObjectives[objectiveToComplete->getObjectiveIndex()]->getIsActiveObjective()){

		if(cObjectives[objectiveToComplete->getObjectiveIndex()]->getHasSubObjectives() &&
		cObjectives[objectiveToComplete->getObjectiveIndex()]->getNumSubObjectivesToComplete() > 0
		)
		{

		cObjectives[objectiveToComplete->getObjectiveIndex()]->setNumSubObjectivesToComplete
		((cObjectives[objectiveToComplete->getObjectiveIndex()]->getNumSubObjectivesToComplete() - 1));

		objectiveToComplete->setObjectiveText(setMultiObjectiveText(objectiveToComplete->getObjectiveText(),
			objectiveToComplete->getNumSubObjectivesToComplete(), numSubObjectives[objectiveToComplete->getObjectiveIndex()]));

		if (cObjectives[objectiveToComplete->getObjectiveIndex()]->getNumSubObjectivesToComplete() != 0) 
		{
			resetSideBar = true;

			return false;

		}

		}


		cObjectives[objectiveToComplete->getObjectiveIndex()]->setIsCompleted(true);
		cObjectives[objectiveIndex]->setIsActiveObjective(false);
		cObjectives[objectiveIndex]->setIsCompleted(true);
		objectiveIndex++;
		cObjectives[objectiveIndex]->setObjectiveIndex(objectiveIndex);

		resetSideBar = true;

		return true;

	}
	else {
	
		return false;
	
	}

}

bool AcQuest::completeObjectiveAtIndex(int objectiveToCompleteIndex)
{

	if (cObjectives[objectiveToCompleteIndex]->getIsActiveObjective()) {

		if (cObjectives[objectiveToCompleteIndex]->getHasSubObjectives() &&
			cObjectives[objectiveToCompleteIndex]->getNumSubObjectivesToComplete() > 0
			)
		{

			cObjectives[objectiveToCompleteIndex]->setNumSubObjectivesToComplete
			((cObjectives[objectiveToCompleteIndex]->getNumSubObjectivesToComplete() - 1));

			cObjectives[objectiveToCompleteIndex]->setObjectiveText(setMultiObjectiveText(cObjectives[objectiveToCompleteIndex]->getObjectiveText(),
				cObjectives[objectiveToCompleteIndex]->getNumSubObjectivesToComplete(), numSubObjectives[objectiveToCompleteIndex]));

			if (cObjectives[objectiveToCompleteIndex]->getNumSubObjectivesToComplete() != 0)
			{
				resetSideBar = true;

				return false;

			}

		}

		cObjectives[objectiveToCompleteIndex]->setIsCompleted(true);
		cObjectives[objectiveToCompleteIndex]->setIsActiveObjective(false);
		++objectiveIndex;
		if (cObjectives.IsValidIndex(objectiveIndex)) {

			cObjectives[objectiveIndex]->setObjectiveIndex(objectiveIndex);
			cObjectives[objectiveIndex]->setIsActiveObjective(true);
			resetSideBar = true;

		}
		else {

			setIsCompleted(true);
			resetSideBar = true;

		}

		return true;

	}
	else {

		return false;

	}

}

UFUNCTION(BlueprintCallable) bool AcQuest::checkCompletion()
{
	
	if (isCompleted) {

		return true;

	}
	else {

		if (cObjectives[0] != nullptr) {

			for (int i = 0; i != cObjectives.Num(); i++)
			{
				if (!(cObjectives[i]->getIsCompleted()))
				{

					return false;

				}else if (!cObjectives.IsValidIndex((i + 1)))
				{
					isCompleted = true;
					return true;

				}

			}

		}
		else {

					isCompleted = true;
					return true;

		}

	}

	return false;

}


UFUNCTION(BlueprintCallable) bool AcQuest::getresetSideBar()
{
	return resetSideBar;
}

UFUNCTION(BlueprintCallable) bool AcQuest::setresetSideBar(bool newresetSideBar)
{
	resetSideBar = newresetSideBar;
	return resetSideBar;
}

//Getters  Setters

AActor* AcQuest::getQuestGiver()
{
	return questGiver;
}

AActor* AcQuest::setQuestGiver(AActor* newQuestGiver)
{
	questGiver = newQuestGiver;
	return questGiver;
}

FString AcQuest::getName()
{
	return name;
}

FString AcQuest::setName(FString newName)
{
	name = newName;
	return name;
}

FString AcQuest::getDetails()
{
	return details;
}

FString AcQuest::setDetails(FString newDetails)
{
	details = newDetails;
	return details;
}


UcObjective* AcQuest::getActiveObjective()
{
	if (cObjectives.IsValidIndex(objectiveIndex)) {
		return cObjectives[objectiveIndex];
	}
	else {

		return cObjectives[0];

	}

}

UFUNCTION(BlueprintCallable)TArray<UcObjective*> AcQuest::getObjectives()
{
	return cObjectives;
}

bool AcQuest::getIsTaken()
{
	return isTaken;
}

bool AcQuest::setIsTaken(bool newIsTaken)
{
	isTaken = newIsTaken;
	return isTaken;
}

int AcQuest::getExperienceReward()
{
	return experienceReward;
}

int AcQuest::setExperienceReward(int newExperienceReward)
{
	experienceReward = newExperienceReward;
	return experienceReward;
}

int AcQuest::getGoldReward()
{
	return goldReward;
}

int AcQuest::setGoldReward(int newGoldReward)
{
	goldReward = newGoldReward;
	return goldReward;
}

int AcQuest::getObjectiveIndex()
{
	return objectiveIndex;
}

int AcQuest::setObjectiveIndex(int newObjectiveIndex)
{
	objectiveIndex = newObjectiveIndex;
	return objectiveIndex;
}

int AcQuest::getQuestIndex()
{
	return questIndex;
}

int AcQuest::setQuestIndex(int newQuestIndex)
{
	questIndex = newQuestIndex;
	return questIndex;
}

bool AcQuest::getIsCompleted()
{
	return isCompleted;
}

bool AcQuest::setIsCompleted(bool newIsCompleted)
{
	isCompleted = newIsCompleted;
	return isCompleted;
}

bool AcQuest::getDisplayAllObjectives()
{
	return displayAllObjectives;
}

bool AcQuest::setDisplayAllObjectives(bool newDisplayAllObjectives)
{
	displayAllObjectives = newDisplayAllObjectives;
	return displayAllObjectives;
}

TArray<FText> AcQuest::getObjectiveText()
{
	return objectiveText;
}

UFUNCTION(BlueprintCallable)TArray<int> AcQuest::getNumSubObjectives()
{
	return numSubObjectives;
}

UFUNCTION(BlueprintCallable)FText AcQuest::setMultiObjectiveText(FText initialText, int changingObjectiveValue, int totalNumberOfObjectives)
{

	FString tempString;
	FString tempStringLeft;
	FString tempStringRight;

	tempString = initialText.ToString();

	if (tempString.Contains(TEXT("["))) {

		tempString.LeftChopInline(tempString.Len() - tempString.Find(TEXT("[")));

	}
	tempString.AppendChar(CharCast<TCHAR, const char>('['));
	tempString.AppendInt(((changingObjectiveValue - totalNumberOfObjectives) * -1));
	tempString.AppendChar(CharCast<TCHAR, const char>('/'));
	tempString.AppendInt(totalNumberOfObjectives);
	tempString.AppendChar(CharCast<TCHAR, const char>(']'));

	return initialText.FromString(tempString);
}

