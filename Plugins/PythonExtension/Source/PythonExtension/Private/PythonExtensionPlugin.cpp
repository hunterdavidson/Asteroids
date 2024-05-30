#include "PythonExtensionPlugin.h"
#include "IPythonScriptPlugin.h"
#include "Async/TaskGraphInterfaces.h"

void UPythonExtension::LaunchScriptOnGameThread(FString pythonCode)
{
    FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([pythonCode]()
        {
            IPythonScriptPlugin::Get()->ExecPythonCommand(*pythonCode);
        }, TStatId(), nullptr, ENamedThreads::GameThread);

    FTaskGraphInterface::Get().WaitUntilTaskCompletes(Task);
}
