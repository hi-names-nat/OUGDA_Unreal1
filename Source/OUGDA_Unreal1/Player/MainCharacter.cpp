// Made by Natalie Soltis for OUGDA. This project is licensed under a GPLv3 license.


#include "MainCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring"));
	SpringArm->SetupAttachment(GetRootComponent());
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArm);

	

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMainCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &AMainCharacter::StopJumping);

	PlayerInputComponent->BindAxis("LookX", this, &AMainCharacter::LookRight);
	PlayerInputComponent->BindAxis("LookY", this, &AMainCharacter::LookUp);
	PlayerInputComponent->BindAxis("MoveX", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveY", this, &AMainCharacter::MoveRight);

	
	PlayerInputComponent->BindAxis("Equip", this, &AMainCharacter::EquipItem);
}

void AMainCharacter::MoveForward(float value)
{
	auto deltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	AddMovementInput(GetActorForwardVector() * deltaSeconds * value * playerSpeed);
}

void AMainCharacter::MoveRight(float value)
{
	auto deltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	AddMovementInput(GetActorRightVector() * deltaSeconds * value * playerSpeed );
}

void AMainCharacter::LookUp(float value)
{
	auto deltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	SpringArm->AddLocalRotation(FRotator(value * deltaSeconds * cameraSensitivity, 0, 0), true);
}	

void AMainCharacter::LookRight(float value)
{
	auto deltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	AddControllerYawInput(value * deltaSeconds * cameraSensitivity);
}

void AMainCharacter::EquipItem(float value)
{

}

