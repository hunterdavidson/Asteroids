import unreal

# Corrected path format
blueprint_path = "/Game/Developers/Hunter/Gamemodes/GS_AsteroidsClassic.GS_AsteroidsClassic"

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
editor_asset_lib = unreal.EditorAssetLibrary()

if editor_asset_lib.does_asset_exist(blueprint_path):
    blueprint = editor_asset_lib.load_asset(blueprint_path)
    asset_tools.open_editor_for_assets([blueprint])
else:
    unreal.log_warning("Blueprint not found: {}".format(blueprint_path))
