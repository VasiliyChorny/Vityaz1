// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()//говорить про те що клас €кий п≥д ним повз€зуетьс€ з анриалом та блюпринтами
class AMainCharacter : public ACharacter//спадкуванн€ в≥д ACharacter
{
	GENERATED_BODY()//регестрирует инофрмацию про класс и его компоненты добавл€€ их в блюпринты

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics")//добавл€ет возможность пользоватс€ Їтим проперти в блюпринта
		float HitPoints;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics")
		float DebuffDefance;

	UFUNCTION(BlueprintCallable, Category = "MainCharacter|Damage")
		//void TakeDamage(float Value);
		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
		
public://визов конструктора в блюпритни
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
