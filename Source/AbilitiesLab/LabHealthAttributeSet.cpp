// Fill out your copyright notice in the Description page of Project Settings.


#include "LabHealthAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include <algorithm>


ULabHealthAttributeSet::ULabHealthAttributeSet()
{
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
}

void ULabHealthAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	UE_LOG(LogTemp, Warning, TEXT("PreChange: AttributeName '%s'"), *Attribute.AttributeName);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}

	Super::PreAttributeChange(Attribute, NewValue);
}

void ULabHealthAttributeSet::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// DOREPLIFETIME������ Unreal Engine �ṩ�ĺ꣬
	// ���ڱ��ĳ����ĳ�Ա������Ҫ�������н��������ƣ����ڶ������������������ͬ������
	DOREPLIFETIME(ULabHealthAttributeSet, Health);
	DOREPLIFETIME(ULabHealthAttributeSet, MaxHealth);
}
