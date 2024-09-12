// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorCharacterAnimInstance.h"
#include "../Character/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	if (OwingCharacter)
	{
		OwingMovementComponent = OwingCharacter->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (OwingCharacter || !OwingMovementComponent)
	{
		return;
	}
	GroundSpeed = OwingCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwingMovementComponent->GetCurrentAcceleration().SizeSquared() > 0.f;
}
