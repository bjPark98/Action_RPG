// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorHeroAnimInstance.h"
#include "../../Character/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwingCharacter)
	{
		OwingHeroCharacter = Cast<AWarriorHeroCharacter>(OwingCharacter);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShoulEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShoulEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}

}
