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
	${OBJECTDIR}/source/main.o \
	${OBJECTDIR}/source/HalfHollowBlockModel.o \
	${OBJECTDIR}/source/PitModel.o \
	${OBJECTDIR}/source/BaseModel.o \
	${OBJECTDIR}/source/HillsModel.o \
	${OBJECTDIR}/source/PlainBlock.o \
	${OBJECTDIR}/source/MountainModel.o \
	${OBJECTDIR}/source/LightRubbleModel.o \
	${OBJECTDIR}/source/LevelRenderer.o \
	${OBJECTDIR}/source/Mountain.o \
	${OBJECTDIR}/source/Phaser.o \
	${OBJECTDIR}/source/Grass.o \
	${OBJECTDIR}/source/Fence.o \
	${OBJECTDIR}/source/NuclearModel.o \
	${OBJECTDIR}/source/PlayerModel.o \
	${OBJECTDIR}/source/AntennaModel.o \
	${OBJECTDIR}/source/Electronics.o \
	${OBJECTDIR}/source/CannonModel.o \
	${OBJECTDIR}/source/Player.o \
	${OBJECTDIR}/source/MissileLauncher.o \
	${OBJECTDIR}/source/PlainBlockModel.o \
	${OBJECTDIR}/source/Pit.o \
	${OBJECTDIR}/source/GrassModel.o \
	${OBJECTDIR}/source/ElectronicsModel.o \
	${OBJECTDIR}/source/PhaserModel.o \
	${OBJECTDIR}/source/Base.o \
	${OBJECTDIR}/source/FenceModel.o \
	${OBJECTDIR}/source/TeamNumberModel.o \
	${OBJECTDIR}/source/HalfHollowBlock.o \
	${OBJECTDIR}/source/HalfPlainBlockModel.o \
	${OBJECTDIR}/source/GeoHelper.o \
	${OBJECTDIR}/source/Cannon.o \
	${OBJECTDIR}/source/HollowBlockModel.o \
	${OBJECTDIR}/source/Robot.o \
	${OBJECTDIR}/source/Model.o \
	${OBJECTDIR}/source/HollowBlock.o \
	${OBJECTDIR}/source/MissileLauncherModel.o \
	${OBJECTDIR}/source/Nuclear.o \
	${OBJECTDIR}/source/HalfPlainBlock.o


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

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/main.o source/main.cpp

${OBJECTDIR}/source/HalfHollowBlockModel.o: source/HalfHollowBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/HalfHollowBlockModel.o source/HalfHollowBlockModel.cpp

${OBJECTDIR}/source/PitModel.o: source/PitModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/PitModel.o source/PitModel.cpp

${OBJECTDIR}/source/BaseModel.o: source/BaseModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/BaseModel.o source/BaseModel.cpp

${OBJECTDIR}/source/HillsModel.o: source/HillsModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/HillsModel.o source/HillsModel.cpp

${OBJECTDIR}/source/PlainBlock.o: source/PlainBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/PlainBlock.o source/PlainBlock.cpp

${OBJECTDIR}/source/MountainModel.o: source/MountainModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/MountainModel.o source/MountainModel.cpp

${OBJECTDIR}/source/LightRubbleModel.o: source/LightRubbleModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/LightRubbleModel.o source/LightRubbleModel.cpp

${OBJECTDIR}/source/LevelRenderer.o: source/LevelRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/LevelRenderer.o source/LevelRenderer.cpp

${OBJECTDIR}/source/Mountain.o: source/Mountain.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Mountain.o source/Mountain.cpp

${OBJECTDIR}/source/Phaser.o: source/Phaser.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Phaser.o source/Phaser.cpp

${OBJECTDIR}/source/Grass.o: source/Grass.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Grass.o source/Grass.cpp

${OBJECTDIR}/source/Fence.o: source/Fence.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Fence.o source/Fence.cpp

${OBJECTDIR}/source/NuclearModel.o: source/NuclearModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/NuclearModel.o source/NuclearModel.cpp

${OBJECTDIR}/source/PlayerModel.o: source/PlayerModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/PlayerModel.o source/PlayerModel.cpp

${OBJECTDIR}/source/AntennaModel.o: source/AntennaModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/AntennaModel.o source/AntennaModel.cpp

${OBJECTDIR}/source/Electronics.o: source/Electronics.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Electronics.o source/Electronics.cpp

${OBJECTDIR}/source/CannonModel.o: source/CannonModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/CannonModel.o source/CannonModel.cpp

${OBJECTDIR}/source/Player.o: source/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Player.o source/Player.cpp

${OBJECTDIR}/source/MissileLauncher.o: source/MissileLauncher.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/MissileLauncher.o source/MissileLauncher.cpp

${OBJECTDIR}/source/PlainBlockModel.o: source/PlainBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/PlainBlockModel.o source/PlainBlockModel.cpp

${OBJECTDIR}/source/Pit.o: source/Pit.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Pit.o source/Pit.cpp

${OBJECTDIR}/source/GrassModel.o: source/GrassModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/GrassModel.o source/GrassModel.cpp

${OBJECTDIR}/source/ElectronicsModel.o: source/ElectronicsModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/ElectronicsModel.o source/ElectronicsModel.cpp

${OBJECTDIR}/source/PhaserModel.o: source/PhaserModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/PhaserModel.o source/PhaserModel.cpp

${OBJECTDIR}/source/Base.o: source/Base.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Base.o source/Base.cpp

${OBJECTDIR}/source/FenceModel.o: source/FenceModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/FenceModel.o source/FenceModel.cpp

${OBJECTDIR}/source/TeamNumberModel.o: source/TeamNumberModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/TeamNumberModel.o source/TeamNumberModel.cpp

${OBJECTDIR}/source/HalfHollowBlock.o: source/HalfHollowBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/HalfHollowBlock.o source/HalfHollowBlock.cpp

${OBJECTDIR}/source/HalfPlainBlockModel.o: source/HalfPlainBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/HalfPlainBlockModel.o source/HalfPlainBlockModel.cpp

${OBJECTDIR}/source/GeoHelper.o: source/GeoHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/GeoHelper.o source/GeoHelper.cpp

${OBJECTDIR}/source/Cannon.o: source/Cannon.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Cannon.o source/Cannon.cpp

${OBJECTDIR}/source/HollowBlockModel.o: source/HollowBlockModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/HollowBlockModel.o source/HollowBlockModel.cpp

${OBJECTDIR}/source/Robot.o: source/Robot.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Robot.o source/Robot.cpp

${OBJECTDIR}/source/Model.o: source/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Model.o source/Model.cpp

${OBJECTDIR}/source/HollowBlock.o: source/HollowBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/HollowBlock.o source/HollowBlock.cpp

${OBJECTDIR}/source/MissileLauncherModel.o: source/MissileLauncherModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/MissileLauncherModel.o source/MissileLauncherModel.cpp

${OBJECTDIR}/source/Nuclear.o: source/Nuclear.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Nuclear.o source/Nuclear.cpp

${OBJECTDIR}/source/HalfPlainBlock.o: source/HalfPlainBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/HalfPlainBlock.o source/HalfPlainBlock.cpp

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
