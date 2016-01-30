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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/knapsack/knapsack_utility.o \
	${OBJECTDIR}/src/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/test/knapsack/test_knapsack.o \
	${TESTDIR}/test/knapsack/test_knapsack_id.o \
	${TESTDIR}/test/knapsack/test_knapsack_item.o \
	${TESTDIR}/test/knapsack/test_knapsack_utility.o \
	${TESTDIR}/test/utility/test_seed.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ea

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ea: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ea ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/knapsack/knapsack_utility.o: src/knapsack/knapsack_utility.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/knapsack
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/knapsack/knapsack_utility.o src/knapsack/knapsack_utility.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f2: ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/test/knapsack/test_knapsack.o ${TESTDIR}/test/knapsack/test_knapsack_id.o ${TESTDIR}/test/knapsack/test_knapsack_item.o ${TESTDIR}/test/knapsack/test_knapsack_utility.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/test/utility/test_seed.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/test/knapsack/test_knapsack.o: test/knapsack/test_knapsack.cpp 
	${MKDIR} -p ${TESTDIR}/test/knapsack
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/test/knapsack/test_knapsack.o test/knapsack/test_knapsack.cpp


${TESTDIR}/test/knapsack/test_knapsack_id.o: test/knapsack/test_knapsack_id.cpp 
	${MKDIR} -p ${TESTDIR}/test/knapsack
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/test/knapsack/test_knapsack_id.o test/knapsack/test_knapsack_id.cpp


${TESTDIR}/test/knapsack/test_knapsack_item.o: test/knapsack/test_knapsack_item.cpp 
	${MKDIR} -p ${TESTDIR}/test/knapsack
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/test/knapsack/test_knapsack_item.o test/knapsack/test_knapsack_item.cpp


${TESTDIR}/test/knapsack/test_knapsack_utility.o: test/knapsack/test_knapsack_utility.cpp 
	${MKDIR} -p ${TESTDIR}/test/knapsack
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/test/knapsack/test_knapsack_utility.o test/knapsack/test_knapsack_utility.cpp


${TESTDIR}/test/utility/test_seed.o: test/utility/test_seed.cpp 
	${MKDIR} -p ${TESTDIR}/test/utility
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/test/utility/test_seed.o test/utility/test_seed.cpp


${OBJECTDIR}/src/knapsack/knapsack_utility_nomain.o: ${OBJECTDIR}/src/knapsack/knapsack_utility.o src/knapsack/knapsack_utility.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/knapsack
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/knapsack/knapsack_utility.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/knapsack/knapsack_utility_nomain.o src/knapsack/knapsack_utility.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/knapsack/knapsack_utility.o ${OBJECTDIR}/src/knapsack/knapsack_utility_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main_nomain.o src/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ea

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
