#include "AsteroidsEditorUtility.h"
#include <Windows.h>

void UAsteroidsEditorUtility::InitializeWidget()
{
    bWasCtrlAlt1Pressed = false;
    bWasCtrlAlt2Pressed = false;
    bWasCtrlAlt3Pressed = false;
    bWasCtrlAlt4Pressed = false;
    bWasCtrlAlt5Pressed = false;
    bWasCtrlAlt6Pressed = false;
}

void UAsteroidsEditorUtility::CheckKeyPresses(bool& bCtrlAlt1Pressed, bool& bCtrlAlt2Pressed, bool& bCtrlAlt3Pressed, bool& bCtrlAlt4Pressed, bool& bCtrlAlt5Pressed, bool& bCtrlAlt6Pressed)
{
    bool bIsCtrlPressed = (GetAsyncKeyState(VK_CONTROL) & 0x8000) != 0;
    bool bIsAltPressed = (GetAsyncKeyState(VK_MENU) & 0x8000) != 0;
    bool bIs1Pressed = (GetAsyncKeyState('1') & 0x8000) != 0;
    bool bIs2Pressed = (GetAsyncKeyState('2') & 0x8000) != 0;
    bool bIs3Pressed = (GetAsyncKeyState('3') & 0x8000) != 0;
    bool bIs4Pressed = (GetAsyncKeyState('4') & 0x8000) != 0;
    bool bIs5Pressed = (GetAsyncKeyState('5') & 0x8000) != 0;
    bool bIs6Pressed = (GetAsyncKeyState('6') & 0x8000) != 0;

    bCtrlAlt1Pressed = bIsCtrlPressed && bIsAltPressed && bIs1Pressed && !bWasCtrlAlt1Pressed;
    bCtrlAlt2Pressed = bIsCtrlPressed && bIsAltPressed && bIs2Pressed && !bWasCtrlAlt2Pressed;
    bCtrlAlt3Pressed = bIsCtrlPressed && bIsAltPressed && bIs3Pressed && !bWasCtrlAlt3Pressed;
    bCtrlAlt4Pressed = bIsCtrlPressed && bIsAltPressed && bIs4Pressed && !bWasCtrlAlt4Pressed;
    bCtrlAlt5Pressed = bIsCtrlPressed && bIsAltPressed && bIs5Pressed && !bWasCtrlAlt5Pressed;
    bCtrlAlt6Pressed = bIsCtrlPressed && bIsAltPressed && bIs6Pressed && !bWasCtrlAlt6Pressed;

    bWasCtrlAlt1Pressed = bIsCtrlPressed && bIsAltPressed && bIs1Pressed;
    bWasCtrlAlt2Pressed = bIsCtrlPressed && bIsAltPressed && bIs2Pressed;
    bWasCtrlAlt3Pressed = bIsCtrlPressed && bIsAltPressed && bIs3Pressed;
    bWasCtrlAlt4Pressed = bIsCtrlPressed && bIsAltPressed && bIs4Pressed;
    bWasCtrlAlt5Pressed = bIsCtrlPressed && bIsAltPressed && bIs5Pressed;
    bWasCtrlAlt6Pressed = bIsCtrlPressed && bIsAltPressed && bIs6Pressed;
}
