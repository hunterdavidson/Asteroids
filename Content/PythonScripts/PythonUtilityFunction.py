import inspect
import unreal

def run_on_main_thread(function):
    """
    This will launch the input function on Unreal's main game thread.
    """
    func_lines = inspect.getsourcelines(function)[0][1:]

    code_in_string = ""

    # Remove blank spaces at start and end in every line
    for line in func_lines:
        code_in_string += line.strip() + "\n"

    unreal.PythonExtension.launch_script_on_game_thread(code_in_string)
