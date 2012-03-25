#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/source/Model/Material/Material.o \
	${OBJECTDIR}/source/main.o \
	${OBJECTDIR}/source/Model/Robot/MissileLauncherModel.o \
	${OBJECTDIR}/source/Model/Skybox/CubicSkybox.o \
	${OBJECTDIR}/source/Model/Texture/TextureManager.o \
	${OBJECTDIR}/source/Model/Material/DefaultMaterial.o \
	${OBJECTDIR}/source/Helper/AntTweakHelper.o \
	${OBJECTDIR}/source/Model/Static/FenceModel.o \
	${OBJECTDIR}/source/Logic/Base.o \
	${OBJECTDIR}/source/Model/Robot/HeadlightModel.o \
	${OBJECTDIR}/source/Model/Material/RockMaterial.o \
	${OBJECTDIR}/source/Logic/Player.o \
	${OBJECTDIR}/source/Logic/SpotLight.o \
	${OBJECTDIR}/source/Model/Robot/CannonModel.o \
	${OBJECTDIR}/source/Logic/CommanderCamera.o \
	${OBJECTDIR}/source/Model/Static/HollowBlockModel.o \
	${OBJECTDIR}/source/Model/Static/HalfPlainBlockModel.o \
	${OBJECTDIR}/source/Logic/HumanPlayer.o \
	${OBJECTDIR}/source/Model/Static/PlainBlockModel.o \
	${OBJECTDIR}/source/Logic/LightCamera.o \
	${OBJECTDIR}/source/Model/Static/TeamNumberModel.o \
	${OBJECTDIR}/source/Logic/Game.o \
	${OBJECTDIR}/source/Model/Helper/GeoHelper.o \
	${OBJECTDIR}/source/Model/Robot/ElectronicsModel.o \
	${OBJECTDIR}/source/Model/Light/LightPost.o \
	${OBJECTDIR}/source/Model/Buildings/FactoryModel.o \
	${OBJECTDIR}/source/Model/Buildings/BaseModel.o \
	${OBJECTDIR}/source/Model/Player/AntennaModel.o \
	${OBJECTDIR}/source/Logic/LevelRenderer.o \
	${OBJECTDIR}/source/Model/Player/PlayerModel.o \
	${OBJECTDIR}/source/Model/Robot/PhaserModel.o \
	${OBJECTDIR}/source/Logic/CirclingCamera.o \
	${OBJECTDIR}/source/Model/Material/OrganicMaterial.o \
	${OBJECTDIR}/source/Model/Material/MetalMaterial.o \
	${OBJECTDIR}/source/Model/Model.o \
	${OBJECTDIR}/source/Helper/DirectoryManipHelper.o \
	${OBJECTDIR}/source/Model/Static/MountainModel.o \
	${OBJECTDIR}/source/Logic/PlayerInput.o \
	${OBJECTDIR}/source/Logic/RobotCamera.o \
	${OBJECTDIR}/source/Model/Static/HillsModel.o \
	${OBJECTDIR}/source/Model/Robot/NuclearModel.o \
	${OBJECTDIR}/source/Model/Static/LightRubbleModel.o \
	${OBJECTDIR}/source/Logic/Factory.o \
	${OBJECTDIR}/source/Logic/Robot.o \
	${OBJECTDIR}/source/Model/Static/PitModel.o \
	${OBJECTDIR}/source/Model/Robot/BipodModel.o \
	${OBJECTDIR}/source/Model/Robot/AntiGravModel.o \
	${OBJECTDIR}/source/Model/Robot/TracksModel.o \
	${OBJECTDIR}/source/Model/Static/GrassModel.o \
	${OBJECTDIR}/source/Model/Static/HalfHollowBlockModel.o \
	${OBJECTDIR}/source/Logic/FreeLookCamera.o \
	${OBJECTDIR}/source/Logic/Camera.o \
	${OBJECTDIR}/source/Model/Texture/imageloader.o \
	${OBJECTDIR}/source/Model/Skybox/SphericSkybox.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/source/Model/Material/Material.o: source/Model/Material/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Material/Material.o source/Model/Material/Material.cpp

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/main.o source/main.cpp

${OBJECTDIR}/source/Model/Robot/MissileLauncherModel.o: source/Model/Robot/MissileLauncherModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/MissileLauncherModel.o source/Model/Robot/MissileLauncherModel.cpp

${OBJECTDIR}/source/Model/Skybox/CubicSkybox.o: source/Model/Skybox/CubicSkybox.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Skybox
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Skybox/CubicSkybox.o source/Model/Skybox/CubicSkybox.cpp

${OBJECTDIR}/source/Model/Texture/TextureManager.o: source/Model/Texture/TextureManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Texture
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Texture/TextureManager.o source/Model/Texture/TextureManager.cpp

${OBJECTDIR}/source/Model/Material/DefaultMaterial.o: source/Model/Material/DefaultMaterial.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Material/DefaultMaterial.o source/Model/Material/DefaultMaterial.cpp

${OBJECTDIR}/source/Helper/AntTweakHelper.o: source/Helper/AntTweakHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Helper
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Helper/AntTweakHelper.o source/Helper/AntTweakHelper.cpp

${OBJECTDIR}/source/Model/Static/FenceModel.o: source/Model/Static/FenceModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/FenceModel.o source/Model/Static/FenceModel.cpp

${OBJECTDIR}/source/Logic/Base.o: source/Logic/Base.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Base.o source/Logic/Base.cpp

${OBJECTDIR}/source/Model/Robot/HeadlightModel.o: source/Model/Robot/HeadlightModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/HeadlightModel.o source/Model/Robot/HeadlightModel.cpp

${OBJECTDIR}/source/Model/Material/RockMaterial.o: source/Model/Material/RockMaterial.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Material/RockMaterial.o source/Model/Material/RockMaterial.cpp

${OBJECTDIR}/source/Logic/Player.o: source/Logic/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Player.o source/Logic/Player.cpp

${OBJECTDIR}/source/Logic/SpotLight.o: source/Logic/SpotLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/SpotLight.o source/Logic/SpotLight.cpp

${OBJECTDIR}/source/Model/Robot/CannonModel.o: source/Model/Robot/CannonModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/CannonModel.o source/Model/Robot/CannonModel.cpp

${OBJECTDIR}/source/Logic/CommanderCamera.o: source/Logic/CommanderCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/CommanderCamera.o source/Logic/CommanderCamera.cpp

${OBJECTDIR}/source/Model/Static/HollowBlockModel.o: source/Model/Static/HollowBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HollowBlockModel.o source/Model/Static/HollowBlockModel.cpp

${OBJECTDIR}/source/Model/Static/HalfPlainBlockModel.o: source/Model/Static/HalfPlainBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HalfPlainBlockModel.o source/Model/Static/HalfPlainBlockModel.cpp

${OBJECTDIR}/source/Logic/HumanPlayer.o: source/Logic/HumanPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/HumanPlayer.o source/Logic/HumanPlayer.cpp

${OBJECTDIR}/source/Model/Static/PlainBlockModel.o: source/Model/Static/PlainBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/PlainBlockModel.o source/Model/Static/PlainBlockModel.cpp

${OBJECTDIR}/source/Logic/LightCamera.o: source/Logic/LightCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/LightCamera.o source/Logic/LightCamera.cpp

${OBJECTDIR}/source/Model/Static/TeamNumberModel.o: source/Model/Static/TeamNumberModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/TeamNumberModel.o source/Model/Static/TeamNumberModel.cpp

${OBJECTDIR}/source/Logic/Game.o: source/Logic/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Game.o source/Logic/Game.cpp

${OBJECTDIR}/source/Model/Helper/GeoHelper.o: source/Model/Helper/GeoHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Helper
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Helper/GeoHelper.o source/Model/Helper/GeoHelper.cpp

${OBJECTDIR}/source/Model/Robot/ElectronicsModel.o: source/Model/Robot/ElectronicsModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/ElectronicsModel.o source/Model/Robot/ElectronicsModel.cpp

${OBJECTDIR}/source/Model/Light/LightPost.o: source/Model/Light/LightPost.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Light
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Light/LightPost.o source/Model/Light/LightPost.cpp

${OBJECTDIR}/source/Model/Buildings/FactoryModel.o: source/Model/Buildings/FactoryModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Buildings
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Buildings/FactoryModel.o source/Model/Buildings/FactoryModel.cpp

${OBJECTDIR}/source/Model/Buildings/BaseModel.o: source/Model/Buildings/BaseModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Buildings
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Buildings/BaseModel.o source/Model/Buildings/BaseModel.cpp

${OBJECTDIR}/source/Model/Player/AntennaModel.o: source/Model/Player/AntennaModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Player
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Player/AntennaModel.o source/Model/Player/AntennaModel.cpp

${OBJECTDIR}/source/Logic/LevelRenderer.o: source/Logic/LevelRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/LevelRenderer.o source/Logic/LevelRenderer.cpp

${OBJECTDIR}/source/Model/Player/PlayerModel.o: source/Model/Player/PlayerModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Player
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Player/PlayerModel.o source/Model/Player/PlayerModel.cpp

${OBJECTDIR}/source/Model/Robot/PhaserModel.o: source/Model/Robot/PhaserModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/PhaserModel.o source/Model/Robot/PhaserModel.cpp

${OBJECTDIR}/source/Logic/CirclingCamera.o: source/Logic/CirclingCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/CirclingCamera.o source/Logic/CirclingCamera.cpp

${OBJECTDIR}/source/Model/Material/OrganicMaterial.o: source/Model/Material/OrganicMaterial.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Material/OrganicMaterial.o source/Model/Material/OrganicMaterial.cpp

${OBJECTDIR}/source/Model/Material/MetalMaterial.o: source/Model/Material/MetalMaterial.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Material/MetalMaterial.o source/Model/Material/MetalMaterial.cpp

${OBJECTDIR}/source/Model/Model.o: source/Model/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Model.o source/Model/Model.cpp

${OBJECTDIR}/source/Helper/DirectoryManipHelper.o: source/Helper/DirectoryManipHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Helper
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Helper/DirectoryManipHelper.o source/Helper/DirectoryManipHelper.cpp

${OBJECTDIR}/source/Model/Static/MountainModel.o: source/Model/Static/MountainModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/MountainModel.o source/Model/Static/MountainModel.cpp

${OBJECTDIR}/source/Logic/PlayerInput.o: source/Logic/PlayerInput.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/PlayerInput.o source/Logic/PlayerInput.cpp

${OBJECTDIR}/source/Logic/RobotCamera.o: source/Logic/RobotCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/RobotCamera.o source/Logic/RobotCamera.cpp

${OBJECTDIR}/source/Model/Static/HillsModel.o: source/Model/Static/HillsModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HillsModel.o source/Model/Static/HillsModel.cpp

${OBJECTDIR}/source/Model/Robot/NuclearModel.o: source/Model/Robot/NuclearModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/NuclearModel.o source/Model/Robot/NuclearModel.cpp

${OBJECTDIR}/source/Model/Static/LightRubbleModel.o: source/Model/Static/LightRubbleModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/LightRubbleModel.o source/Model/Static/LightRubbleModel.cpp

${OBJECTDIR}/source/Logic/Factory.o: source/Logic/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Factory.o source/Logic/Factory.cpp

${OBJECTDIR}/source/Logic/Robot.o: source/Logic/Robot.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Robot.o source/Logic/Robot.cpp

${OBJECTDIR}/source/Model/Static/PitModel.o: source/Model/Static/PitModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/PitModel.o source/Model/Static/PitModel.cpp

${OBJECTDIR}/source/Model/Robot/BipodModel.o: source/Model/Robot/BipodModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/BipodModel.o source/Model/Robot/BipodModel.cpp

${OBJECTDIR}/source/Model/Robot/AntiGravModel.o: source/Model/Robot/AntiGravModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/AntiGravModel.o source/Model/Robot/AntiGravModel.cpp

${OBJECTDIR}/source/Model/Robot/TracksModel.o: source/Model/Robot/TracksModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/TracksModel.o source/Model/Robot/TracksModel.cpp

${OBJECTDIR}/source/Model/Static/GrassModel.o: source/Model/Static/GrassModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/GrassModel.o source/Model/Static/GrassModel.cpp

${OBJECTDIR}/source/Model/Static/HalfHollowBlockModel.o: source/Model/Static/HalfHollowBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HalfHollowBlockModel.o source/Model/Static/HalfHollowBlockModel.cpp

${OBJECTDIR}/source/Logic/FreeLookCamera.o: source/Logic/FreeLookCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/FreeLookCamera.o source/Logic/FreeLookCamera.cpp

${OBJECTDIR}/source/Logic/Camera.o: source/Logic/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Camera.o source/Logic/Camera.cpp

${OBJECTDIR}/source/Model/Texture/imageloader.o: source/Model/Texture/imageloader.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Texture
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Texture/imageloader.o source/Model/Texture/imageloader.cpp

${OBJECTDIR}/source/Model/Skybox/SphericSkybox.o: source/Model/Skybox/SphericSkybox.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Skybox
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Skybox/SphericSkybox.o source/Model/Skybox/SphericSkybox.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
