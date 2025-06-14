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
	// 构造函数声明
	ULabHealthAttributeSet();

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	FGameplayAttributeData Health;


	// Upper limit for health value
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	FGameplayAttributeData MaxHealth;


	// 使用 ATTRIBUTE_ACCESSORS_BASIC 生成访问器
	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, Health)
	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, MaxHealth)
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
