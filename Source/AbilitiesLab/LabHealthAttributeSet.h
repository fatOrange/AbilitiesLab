// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "LabHealthAttributeSet.generated.h"


/**
 * 
 */
UCLASS()
class ABILITIESLAB_API ULabHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	// ���캯������
	ULabHealthAttributeSet();

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	FGameplayAttributeData Health;


	// Upper limit for health value
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	FGameplayAttributeData MaxHealth;


	// ʹ�� ATTRIBUTE_ACCESSORS_BASIC ���ɷ�����
	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, Health)
	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, MaxHealth)
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
