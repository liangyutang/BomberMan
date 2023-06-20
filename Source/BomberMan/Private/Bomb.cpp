// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"

#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(RootComponent);

	BomberSM = CreateDefaultSubobject<UStaticMeshComponent>("BomberSM");
	BomberSM->SetupAttachment(BoxCollision);

	SparkPar = CreateDefaultSubobject<UParticleSystemComponent>("SparkPar");
	SparkPar->SetupAttachment(BoxCollision);
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->SetCollisionResponseToAllChannels(ECR_Overlap);

	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ABomb::OnOverlapEnd);

	GetWorldTimerManager().SetTimer(TimerHandle_Detonate, this, &ABomb::Detonate, DetonateDelay, false);
}

void ABomb::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Error, TEXT("1"));
	if (OtherActor==GetOwner())
	{
		BoxCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	}
}

void ABomb::Detonate()
{
	Destroy();
}

FVector ABomb::LineTraceDirection(const FVector& Direction)
{
	TArray<FHitResult> Hits;

	const FVector Origin = GetActorLocation();
	FVector EndPos = Direction * 100 * BlastRange;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	GetWorld()->LineTraceMultiByChannel(Hits, Origin, EndPos,ECC_EngineTraceChannel1,Params);

	if (Hits.Num()>0)
	{
		EndPos=Hits.Last().ImpactPoint;
	}

	return EndPos;
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

