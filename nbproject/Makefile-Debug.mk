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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/source/main.o \
	${OBJECTDIR}/source/Model/Robot/MissileLauncherModel.o \
	${OBJECTDIR}/source/Model/Static/FenceModel.o \
	${OBJECTDIR}/source/Logic/Base.o \
	${OBJECTDIR}/source/Logic/Player.o \
	${OBJECTDIR}/source/Model/Robot/CannonModel.o \
	${OBJECTDIR}/source/Model/Static/HalfPlainBlockModel.o \
	${OBJECTDIR}/source/Model/Static/HollowBlockModel.o \
	${OBJECTDIR}/source/Model/Static/PlainBlockModel.o \
	${OBJECTDIR}/source/Model/Static/TeamNumberModel.o \
	${OBJECTDIR}/source/Model/Helper/GeoHelper.o \
	${OBJECTDIR}/source/Model/Robot/ElectronicsModel.o \
	${OBJECTDIR}/source/Model/Buildings/BaseModel.o \
	${OBJECTDIR}/source/Model/Buildings/FactoryModel.o \
	${OBJECTDIR}/source/Model/Player/AntennaModel.o \
	${OBJECTDIR}/source/Logic/LevelRenderer.o \
	${OBJECTDIR}/source/Model/Player/PlayerModel.o \
	${OBJECTDIR}/source/Model/Robot/PhaserModel.o \
	${OBJECTDIR}/source/Model/Model.o \
	${OBJECTDIR}/source/Model/Static/MountainModel.o \
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
	${OBJECTDIR}/source/Model/Static/HalfHollowBlockModel.o


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
LDLIBSOPTIONS=-Llibrary library/libAntTweakBar.dylib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth: library/libAntTweakBar.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -framework OpenGL -framework glut -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/battle-royal-near-earth ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/main.o source/main.cpp

${OBJECTDIR}/source/Model/Robot/MissileLauncherModel.o: source/Model/Robot/MissileLauncherModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/MissileLauncherModel.o source/Model/Robot/MissileLauncherModel.cpp

${OBJECTDIR}/source/Model/Static/FenceModel.o: source/Model/Static/FenceModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/FenceModel.o source/Model/Static/FenceModel.cpp

${OBJECTDIR}/source/Logic/Base.o: source/Logic/Base.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Base.o source/Logic/Base.cpp

${OBJECTDIR}/source/Logic/Player.o: source/Logic/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Player.o source/Logic/Player.cpp

${OBJECTDIR}/source/Model/Robot/CannonModel.o: source/Model/Robot/CannonModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/CannonModel.o source/Model/Robot/CannonModel.cpp

${OBJECTDIR}/source/Model/Static/HalfPlainBlockModel.o: source/Model/Static/HalfPlainBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HalfPlainBlockModel.o source/Model/Static/HalfPlainBlockModel.cpp

${OBJECTDIR}/source/Model/Static/HollowBlockModel.o: source/Model/Static/HollowBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HollowBlockModel.o source/Model/Static/HollowBlockModel.cpp

${OBJECTDIR}/source/Model/Static/PlainBlockModel.o: source/Model/Static/PlainBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/PlainBlockModel.o source/Model/Static/PlainBlockModel.cpp

${OBJECTDIR}/source/Model/Static/TeamNumberModel.o: source/Model/Static/TeamNumberModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/TeamNumberModel.o source/Model/Static/TeamNumberModel.cpp

${OBJECTDIR}/source/Model/Helper/GeoHelper.o: source/Model/Helper/GeoHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Helper
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Helper/GeoHelper.o source/Model/Helper/GeoHelper.cpp

${OBJECTDIR}/source/Model/Robot/ElectronicsModel.o: source/Model/Robot/ElectronicsModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/ElectronicsModel.o source/Model/Robot/ElectronicsModel.cpp

${OBJECTDIR}/source/Model/Buildings/BaseModel.o: source/Model/Buildings/BaseModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Buildings
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Buildings/BaseModel.o source/Model/Buildings/BaseModel.cpp

${OBJECTDIR}/source/Model/Buildings/FactoryModel.o: source/Model/Buildings/FactoryModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Buildings
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Buildings/FactoryModel.o source/Model/Buildings/FactoryModel.cpp

${OBJECTDIR}/source/Model/Player/AntennaModel.o: source/Model/Player/AntennaModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Player
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Player/AntennaModel.o source/Model/Player/AntennaModel.cpp

${OBJECTDIR}/source/Logic/LevelRenderer.o: source/Logic/LevelRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/LevelRenderer.o source/Logic/LevelRenderer.cpp

${OBJECTDIR}/source/Model/Player/PlayerModel.o: source/Model/Player/PlayerModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Player
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Player/PlayerModel.o source/Model/Player/PlayerModel.cpp

${OBJECTDIR}/source/Model/Robot/PhaserModel.o: source/Model/Robot/PhaserModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/PhaserModel.o source/Model/Robot/PhaserModel.cpp

${OBJECTDIR}/source/Model/Model.o: source/Model/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Model.o source/Model/Model.cpp

${OBJECTDIR}/source/Model/Static/MountainModel.o: source/Model/Static/MountainModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/MountainModel.o source/Model/Static/MountainModel.cpp

${OBJECTDIR}/source/Model/Static/HillsModel.o: source/Model/Static/HillsModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HillsModel.o source/Model/Static/HillsModel.cpp

${OBJECTDIR}/source/Model/Robot/NuclearModel.o: source/Model/Robot/NuclearModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/NuclearModel.o source/Model/Robot/NuclearModel.cpp

${OBJECTDIR}/source/Model/Static/LightRubbleModel.o: source/Model/Static/LightRubbleModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/LightRubbleModel.o source/Model/Static/LightRubbleModel.cpp

${OBJECTDIR}/source/Logic/Factory.o: source/Logic/Factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Factory.o source/Logic/Factory.cpp

${OBJECTDIR}/source/Logic/Robot.o: source/Logic/Robot.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Logic
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logic/Robot.o source/Logic/Robot.cpp

${OBJECTDIR}/source/Model/Static/PitModel.o: source/Model/Static/PitModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/PitModel.o source/Model/Static/PitModel.cpp

${OBJECTDIR}/source/Model/Robot/BipodModel.o: source/Model/Robot/BipodModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/BipodModel.o source/Model/Robot/BipodModel.cpp

${OBJECTDIR}/source/Model/Robot/AntiGravModel.o: source/Model/Robot/AntiGravModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/AntiGravModel.o source/Model/Robot/AntiGravModel.cpp

${OBJECTDIR}/source/Model/Robot/TracksModel.o: source/Model/Robot/TracksModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Robot
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Robot/TracksModel.o source/Model/Robot/TracksModel.cpp

${OBJECTDIR}/source/Model/Static/GrassModel.o: source/Model/Static/GrassModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/GrassModel.o source/Model/Static/GrassModel.cpp

${OBJECTDIR}/source/Model/Static/HalfHollowBlockModel.o: source/Model/Static/HalfHollowBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Model/Static
	${RM} $@.d
	$(COMPILE.cc) -g -Isource/Model -Isource/Logic -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model/Static/HalfHollowBlockModel.o source/Model/Static/HalfHollowBlockModel.cpp

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
