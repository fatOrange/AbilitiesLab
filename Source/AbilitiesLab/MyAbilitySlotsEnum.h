// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyAbilitySlotsEnum.generated.h"

UENUM(BlueprintType)
enum class EMyAbilitySlotsEnum : uint8
{
	PrimaryAbility,
	SecondaryAbility,
	UltimateAbility
};