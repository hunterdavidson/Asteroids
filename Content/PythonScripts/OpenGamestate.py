import unreal

# Function to open a Blueprint asset in the Blueprint editor
def open_blueprint_in_editor(asset_path):
    # Load the asset
    asset = unreal.EditorAssetLibrary.load_asset(asset_path)
    
    if asset:
        # Open the Blueprint asset in the editor
        asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
        asset_tools.open_editor_for_assets([asset])
        print(f"Blueprint {asset_path} opened in the editor.")
    else:
        print(f"Failed to load asset: {asset_path}")

# Example usage
asset_path = "/Game/Developers/Hunter/Gamemodes/GS_AsteroidsClassic.GS_AsteroidsClassic"  # Replace with your Blueprint asset's path
open_blueprint_in_editor(asset_path)
