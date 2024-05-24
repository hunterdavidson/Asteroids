#include "CustomGameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineIdentityInterface.h"

bool UCustomGameInstance::IsPlayerConnectedToSteam()
{
    IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get(FName("STEAM"));
    if (OnlineSub)
    {
        IOnlineIdentityPtr IdentityInterface = OnlineSub->GetIdentityInterface();
        if (IdentityInterface.IsValid())
        {
            TSharedPtr<const FUniqueNetId> UserId = IdentityInterface->GetUniquePlayerId(0); // Assuming player index 0 for the local player
            if (UserId.IsValid() && UserId->IsValid())
            {
                return true;  // Player is connected to Steam
            }
        }
    }
    return false;  // Player is not connected to Steam
}