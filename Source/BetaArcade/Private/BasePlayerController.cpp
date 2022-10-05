// Author : Craig Palmer v8009358.

#include "BasePlayerController.h"
#include "BasePlayerCharacter.h"

ABasePlayerController::ABasePlayerController() :
	possessedCharacter(nullptr)
{
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	//TODO - Get possessed pawn and update member reference.
	possessedCharacter = Cast<ABasePlayerCharacter>(GetPawn());
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Setup gameplay input bindings

	//Movement
	InputComponent->BindAxis("MoveForward", this, &ABasePlayerController::CallMoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABasePlayerController::CallMoveRight);
	//Actions
	InputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayerController::CallJump);
}

void ABasePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasePlayerController::CallMoveRight(float _value)
{
	// Commented out log to avoid cluttering output log. Allow testing of this Call Action	
	//UE_LOG(LogTemp, Warning, TEXT("MoveRight called from Player Controller with value (%f)."), _value);

	//Call action on character
	if (possessedCharacter)
	{
		possessedCharacter->HorizontalMovement(_value);
	}
}

void ABasePlayerController::CallMoveForward(float _value)
{
	// Commented out log to avoid cluttering output log. Allow testing of this Call Action	
	//UE_LOG(LogTemp, Warning, TEXT("MoveForward called from Player Controller with value (%f)."), _value);

	//Call action on character
	if (possessedCharacter)
	{
		possessedCharacter->VerticalMovement(_value);
	}

}

void ABasePlayerController::CallJump()
{
	UE_LOG(LogTemp, Warning, TEXT("Jump called from Player Controller"));

	//Call action on character
	if (possessedCharacter)
	{
		//possessPawn->CallJump();
	}
}

