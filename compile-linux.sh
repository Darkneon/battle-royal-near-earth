gcc -o battle-royale-near-earth-linux -iquote source/Model/ -iquote source/Helper/ -iquote source/Logic/ -iquote include/ source/main.cpp source/Model/Model.cpp source/Model/Buildings/BaseModel.cpp source/Model/Buildings/FactoryModel.cpp source/Model/Player/AntennaModel.cpp source/Model/Player/PlayerModel.cpp source/Model/Robot/AntiGravModel.cpp source/Model/Robot/ElectronicsModel.cpp source/Model/Robot/PhaserModel.cpp source/Model/Robot/BipodModel.cpp source/Model/Robot/MissileLauncherModel.cpp source/Model/Robot/TracksModel.cpp source/Model/Robot/CannonModel.cpp source/Model/Robot/NuclearModel.cpp source/Model/Static/FenceModel.cpp source/Model/Static/GrassModel.cpp source/Model/Static/HalfHollowBlockModel.cpp source/Model/Static/HalfPlainBlockModel.cpp source/Model/Static/HillsModel.cpp source/Model/Static/HollowBlockModel.cpp source/Model/Static/LightRubbleModel.cpp source/Model/Static/PlainBlockModel.cpp source/Model/Static/MountainModel.cpp source/Model/Static/TeamNumberModel.cpp source/Model/Static/PitModel.cpp source/Model/Helper/GeoHelper.cpp source/Logic/Player.cpp source/Logic/Robot.cpp source/Logic/Base.cpp source/Logic/LevelRenderer.cpp source/Logic/Camera.cpp source/Logic/CommanderCamera.cpp source/Logic/FreeLookCamera.cpp source/Logic/PlayerInput.cpp source/Logic/Game.cpp source/Helper/AntTweakHelper.cpp -lglut -lGL -lGLU -lX11 -lm -lXt -lXext -lstdc++ ./library/libAntTweakBar.so

./battle-royale-near-earth-linux
