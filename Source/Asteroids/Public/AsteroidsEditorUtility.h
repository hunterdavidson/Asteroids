#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "AsteroidsEditorUtility.generated.h"

UCLASS()
class ASTEROIDS_API UAsteroidsEditorUtility : public UEditorUtilityWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Editor Utility")
    void InitializeWidget();

    UFUNCTION(BlueprintCallable, Category = "Editor Utility")
    void CheckKeyPresses(bool& bCtrlAlt1Pressed, bool& bCtrlAlt2Pressed, bool& bCtrlAlt3Pressed, bool& bCtrlAlt4Pressed, bool& bCtrlAlt5Pressed, bool& bCtrlAlt6Pressed);

private:
    bool bWasCtrlAlt1Pressed;
    bool bWasCtrlAlt2Pressed;
    bool bWasCtrlAlt3Pressed;
    bool bWasCtrlAlt4Pressed;
    bool bWasCtrlAlt5Pressed;
    bool bWasCtrlAlt6Pressed;
};
