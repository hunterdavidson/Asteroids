from pynput.keyboard import Key, Listener, KeyCode
import socket
import threading
import unreal

# Define the utility function
def run_on_main_thread(code_string):
    """
    This will execute the provided code string on Unreal's main game thread.
    """
    unreal.log(f"Running on main thread: {code_string}")  # Debug log
    unreal.PythonExtension.launch_script_on_game_thread(code_string)

# Define the blueprint opening functions
def open_gamemode_blueprint_1():
    code_string = """
unreal.AssetToolsHelpers.get_asset_tools().open_editor_for_assets([unreal.EditorAssetLibrary.load_asset('/Game/Developers/Hunter/GameFramework/Gameplay/GM_Asteroids.GM_Asteroids')])
"""
    run_on_main_thread(code_string)

def open_gamemode_blueprint_2():
    code_string = """
unreal.AssetToolsHelpers.get_asset_tools().open_editor_for_assets([unreal.EditorAssetLibrary.load_asset('/Game/Developers/Hunter/GameFramework/Gameplay/GS_Asteroids.GS_Asteroids')])
"""
    run_on_main_thread(code_string)

def open_gamemode_blueprint_3():
    code_string = """
unreal.AssetToolsHelpers.get_asset_tools().open_editor_for_assets([unreal.EditorAssetLibrary.load_asset('/Game/Developers/Hunter/GameFramework/Gameplay/PC_Asteroids.PC_Asteroids')])
"""
    run_on_main_thread(code_string)

def open_gamemode_blueprint_4():
    code_string = """
unreal.AssetToolsHelpers.get_asset_tools().open_editor_for_assets([unreal.EditorAssetLibrary.load_asset('/Game/Developers/Hunter/GameFramework/Gameplay/PS_Asteroids.PS_Asteroids')])
"""
    run_on_main_thread(code_string)

def open_gamemode_blueprint_5():
    code_string = """
unreal.AssetToolsHelpers.get_asset_tools().open_editor_for_assets([unreal.EditorAssetLibrary.load_asset('/Game/Developers/Hunter/Blueprints/Entities/Entity.Entity')])
"""
    run_on_main_thread(code_string)

def open_gamemode_blueprint_6():
    code_string = """
unreal.AssetToolsHelpers.get_asset_tools().open_editor_for_assets([unreal.EditorAssetLibrary.load_asset('/Game/Developers/Hunter/Blueprints/Entities/Ships/BP_Ship.BP_Ship')])
"""
    run_on_main_thread(code_string)

class SingletonMeta(type):
    _instances = {}
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(SingletonMeta, cls).__call__(*args, **kwargs)
        return cls._instances[cls]

class KeyboardInputListener(metaclass=SingletonMeta):
    _instance = None

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def __init__(self, server_address):
        if not hasattr(self, 'initialized'):  # Ensure initialization happens only once
            self.server_address = server_address
            self.bindings = {
                '49': "open_gamemode_blueprint_1()",  # Key code for '1'
                '50': "open_gamemode_blueprint_2()",  # Key code for '2'
                '51': "open_gamemode_blueprint_3()",  # Key code for '3'
                '52': "open_gamemode_blueprint_4()",  # Key code for '4'
                '53': "open_gamemode_blueprint_5()",  # Key code for '5'
                '54': "open_gamemode_blueprint_6()"   # Key code for '6'
            }
            self.control_pressed = False
            self.alt_pressed = False
            self.listener = Listener(on_press=self.on_press, on_release=self.on_release)
            self.listener.start()
            self.initialized = True
            print("Listener started")

    def on_press(self, key):
        if key in {Key.ctrl_l, Key.ctrl_r}:
            self.control_pressed = True
        elif key in {Key.alt_l, Key.alt_r}:
            self.alt_pressed = True
        elif self.control_pressed and self.alt_pressed:
            try:
                key_code = key.vk
                key_str = str(key_code)
                if key_str in self.bindings:
                    self.send_command(self.bindings[key_str])
            except AttributeError:
                pass  # Ignore keys without virtual key codes

    def on_release(self, key):
        if key in {Key.ctrl_l, Key.ctrl_r}:
            self.control_pressed = False
        elif key in {Key.alt_l, Key.alt_r}:
            self.alt_pressed = False

    def send_command(self, command):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
                sock.connect(self.server_address)
                sock.sendall(command.encode('utf-8'))
                print(f"Sent command: {command}")
        except Exception as e:
            print(f"Failed to send command: {e}")

    def stop_listener(self):
        self.listener.stop()
        print("Listener stopped")

class UnrealSocketServer(metaclass=SingletonMeta):
    _instance = None

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def __init__(self, host='127.0.0.1', port=65432):
        if not hasattr(self, 'initialized'):  # Ensure initialization happens only once
            self.host = host
            self.port = port
            self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # Reuse the socket address
            self.server_socket.bind((self.host, self.port))
            self.server_socket.listen()
            self.stop_event = threading.Event()
            self.accept_thread = threading.Thread(target=self.accept_connections)
            self.accept_thread.start()
            self.initialized = True
            print(f"Server listening on {self.host}:{self.port}")

    def accept_connections(self):
        while not self.stop_event.is_set():
            try:
                self.server_socket.settimeout(1.0)
                client_socket, addr = self.server_socket.accept()
                print(f"Accepted connection from {addr}")
                client_thread = threading.Thread(target=self.handle_client, args=(client_socket,))
                client_thread.start()
            except socket.timeout:
                continue
            except OSError:
                break  # Exit the loop if the server socket is closed

    def handle_client(self, client_socket):
        with client_socket:
            while True:
                data = client_socket.recv(1024)
                if not data:
                    break
                command = data.decode('utf-8')
                print(f"Received command: {command}")
                self.execute_unreal_command(command)

    def execute_unreal_command(self, command):
        try:
            exec(command, globals())
        except Exception as e:
            unreal.log_error(f"Error executing command: {e}")

    def stop_server(self):
        self.stop_event.set()
        self.server_socket.close()
        self.accept_thread.join()  # Ensure the accept thread is terminated
        print("Server socket closed")

def start_listener():
    listener = KeyboardInputListener(('127.0.0.1', 65432))
    print("Listener started through widget")

def stop_listener():
    listener = KeyboardInputListener(('127.0.0.1', 65432))  # Access singleton instance
    listener.stop_listener()
    print("Listener stopped through widget")

def start_socket_server():
    server = UnrealSocketServer()
    print("Socket server started through widget")

def stop_socket_server():
    server = UnrealSocketServer()  # Access singleton instance
    if server:
        server.stop_server()
        print("Socket server stopped through widget")

# Ensure that this script is executed only when explicitly run
if __name__ == "__main__":
    start_listener()
    start_socket_server()
