// Fill out your copyright notice in the Description page of Project Settings.


#include "cQuestFetch.h"

void AcQuestFetch::onAcceptFetch() {

	Super::onAccept();

	for (int i = 0; i != target.Num(); i++) {

			//target defaults to not visible and has no collision, enabled once the fetch quest is accepted
			if (target[i]->staticMesh != nullptr) {

				target[i]->staticMesh->SetVisibility(1);
				target[i]->staticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

			}

		}

}