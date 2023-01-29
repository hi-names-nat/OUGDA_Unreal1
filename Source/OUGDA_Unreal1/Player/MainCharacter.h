// Made by Natalie Soltis for OUGDA. This project is licensed under a GPLv3 license.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class OUGDA_UNREAL1_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	//So here's 
private:
	//The camera that the player possessing this actor sees out of
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* CameraComponent;

	//The thing we use to handle 3rd person perspective
	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	float cameraSensitivity;

	UPROPERTY(EditAnywhere)
	float playerSpeed;

	//More might have to be added here...

	//Input functions

	void MoveForward(float value);
	void MoveRight(float value);
	void LookUp(float value);
	void LookRight(float value);
	void EquipItem(float value);

	
public:
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
