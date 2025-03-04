// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"

class APickUpItem; // forward declare the APickupItem class,
// since it will be "mentioned" in a member function

UCLASS()
class THEBEGINNING_API AAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAvatar();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector GunOffset;
	
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AFirstPersonProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FinishGameSound;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void OnFire();

	int itemCounter = 0;
	


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust);
	virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust);
	void StartCrouch();
	void StopCrouch();
	void MoveForward(float amount);
	void MoveBackward(float amount);
	void Yaw(float amount);
	void Pitch(float amount);
	void MoveRight(float amount);
	float Hp;
	float MaxHp;
	//void OnFire();
	// A map for the player's backpack
	TMap<FString, int> Backpack;
	// The icons for the items in the backpack, lookup by string
	TMap<FString, UTexture2D*> Icons;
	// A flag alerting us the UI is showing
	bool inventoryShowing;
	// member function for letting the avatar have an item
	void Pickup(APickUpItem *item);
	void ToggleInventory();
	void MouseClicked();
};
