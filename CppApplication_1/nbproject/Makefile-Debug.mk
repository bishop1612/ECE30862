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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/4def93d5/Base.o \
	${OBJECTDIR}/_ext/4def93d5/PrivDerived.o \
	${OBJECTDIR}/_ext/4def93d5/ProtDerived.o \
	${OBJECTDIR}/_ext/4def93d5/PublicDerived.o \
	${OBJECTDIR}/_ext/4def93d5/dPriv.o \
	${OBJECTDIR}/_ext/4def93d5/dProt.o \
	${OBJECTDIR}/_ext/4def93d5/dPublic.o \
	${OBJECTDIR}/_ext/4def93d5/main.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/4def93d5/Base.o: ../../Downloads/HW13/Base.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/Base.o ../../Downloads/HW13/Base.cpp

${OBJECTDIR}/_ext/4def93d5/PrivDerived.o: ../../Downloads/HW13/PrivDerived.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/PrivDerived.o ../../Downloads/HW13/PrivDerived.cpp

${OBJECTDIR}/_ext/4def93d5/ProtDerived.o: ../../Downloads/HW13/ProtDerived.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/ProtDerived.o ../../Downloads/HW13/ProtDerived.cpp

${OBJECTDIR}/_ext/4def93d5/PublicDerived.o: ../../Downloads/HW13/PublicDerived.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/PublicDerived.o ../../Downloads/HW13/PublicDerived.cpp

${OBJECTDIR}/_ext/4def93d5/dPriv.o: ../../Downloads/HW13/dPriv.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/dPriv.o ../../Downloads/HW13/dPriv.cpp

${OBJECTDIR}/_ext/4def93d5/dProt.o: ../../Downloads/HW13/dProt.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/dProt.o ../../Downloads/HW13/dProt.cpp

${OBJECTDIR}/_ext/4def93d5/dPublic.o: ../../Downloads/HW13/dPublic.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/dPublic.o ../../Downloads/HW13/dPublic.cpp

${OBJECTDIR}/_ext/4def93d5/main.o: ../../Downloads/HW13/main.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4def93d5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4def93d5/main.o ../../Downloads/HW13/main.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
