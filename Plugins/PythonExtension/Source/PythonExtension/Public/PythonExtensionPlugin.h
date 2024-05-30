#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PythonExtensionPlugin.generated.h"

/**
 * Makes possible to run python script on the main thread from any other thread.
 * @param pythonCode - input python code in form of a string example: "print('Hello Unreal')", can be multiline.
 */
UCLASS()
class PYTHONEXTENSION_API UPythonExtension : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "PythonExtension")
    static void LaunchScriptOnGameThread(FString pythonCode);
};
