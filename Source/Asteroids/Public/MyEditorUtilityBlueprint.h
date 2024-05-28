#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityObject.h"
#include "MyEditorUtilityBlueprint.generated.h"

UCLASS()
class ASTEROIDS_API UMyEditorUtilityBlueprint : public UEditorUtilityObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Custom")
    void CheckKeyPresses();
};
