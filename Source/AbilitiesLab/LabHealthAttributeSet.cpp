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
	// DOREPLIFETIME：这是 Unreal Engine 提供的宏，
	// 用于标记某个类的成员变量需要在网络中进行终身复制（即在对象的整个生命周期内同步）。
	DOREPLIFETIME(ULabHealthAttributeSet, Health);
	DOREPLIFETIME(ULabHealthAttributeSet, MaxHealth);
}
