#pragma once
#include "UObject/Interface.h"
#include "UObject/ObjectMacros.h"
#include "CharacterVitals.generated.h"

UINTERFACE()
class UCharacterVitals : public UInterface
{
    GENERATED_BODY()
};

class GENGAME_API ICharacterVitals
{
    GENERATED_BODY()
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetHealthPercent() const;
};