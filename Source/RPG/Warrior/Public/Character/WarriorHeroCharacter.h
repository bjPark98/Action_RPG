// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

/**
 * 
 */

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class RPG_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
public:
	AWarriorHeroCharacter();
protected:
	virtual void BeginPlay() override;

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAcess= "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAcess = "true"))
	UCameraComponent* FollowCamera;
	
};