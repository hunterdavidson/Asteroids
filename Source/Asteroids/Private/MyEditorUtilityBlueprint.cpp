#include "MyEditorUtilityBlueprint.h"
#include <Windows.h>
#include "Misc/OutputDeviceDebug.h"

void UMyEditorUtilityBlueprint::CheckKeyPresses()
{
    // Example functionality: Check if the 'A' key is pressed
    if (GetAsyncKeyState('A') & 0x8000)
    {
        UE_LOG(LogTemp, Warning, TEXT("'A' key is pressed."));
    }

    // Example functionality: Check if the 'Escape' key is pressed
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        UE_LOG(LogTemp, Warning, TEXT("Escape key is pressed. Exiting..."));
        // Add any custom logic for exiting if needed
    }
}