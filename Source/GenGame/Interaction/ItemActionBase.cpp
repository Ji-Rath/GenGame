// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActionBase.h"

#include "PlayerEquip.h"

void UItemActionBase::EndAction()
{
	if (ActionPerformer->Implements<UPlayerEquip>())
	{
		IPlayerEquip::Execute_FinishUseItem(ActionPerformer);
	}
}
