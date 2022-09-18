// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

float AMainCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	HitPoints = HitPoints - DamageAmount;
	//HitPoints = FMath::Clamp(HitPoints-DamageAmount, 0.f, HitPoints);
	//DAmage Calculation
	float CalculateDamage = DamageAmount * DebuffDefance;

	float NewHitPoints = FMath::Clamp(HitPoints - CalculateDamage, 0.f, HitPoints);
	//Calculation the amount of damage acctualy applied
	float ActualDamage = HitPoints - NewHitPoints;
	//apply damage
	HitPoints = NewHitPoints;
	return ActualDamage;
}

// Sets default values
AMainCharacter::AMainCharacter()//конструктор
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;//включение или виключени тикания

	HitPoints = 100.0f;
	DebuffDefance = 1.f;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()//викликаеться одразу после нажатия плей
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)//тіканя кожен проміжок часу.
{
	Super::Tick(DeltaTime);

}

// керування персонажем
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

