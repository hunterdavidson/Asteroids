#include "MyBlueprintFunctionLibrary.h"
#include "Engine/GameViewportClient.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SViewport.h"

bool UMyBlueprintFunctionLibrary::IsGameWindowFocused()
{
    if (GEngine && GEngine->GameViewport)
    {
        TSharedPtr<SViewport> ViewportWidget = GEngine->GameViewport->GetGameViewportWidget();
        if (ViewportWidget.IsValid())
        {
            TSharedPtr<SWidget> FocusedWidget = FSlateApplication::Get().GetUserFocusedWidget(0);
            return FocusedWidget == ViewportWidget;
        }
    }
    return false;
}
