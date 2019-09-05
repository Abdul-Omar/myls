#
# Makefile for CSE 30 -- PA4
# There is a section at the bottom where you may write in your own
# rules. Do not modify anything outside of that section.
#

HEADERS   = pa4.h 

C_SRCS    = buildFileTree.c main.c pa4Globals.c printFiles.c  \
            printPermissions.c isHidden.c getFileInfo.c freeFileTree.c

ASM_SRCS  = getFileCount.s nameCompare.s nameCompareRev.s timeCompare.s \
            timeCompareRev.s

C_OBJS    = buildFileTree.o main.o pa4Globals.o printFiles.o  \
            printPermissions.o isHidden.o getFileInfo.o freeFileTree.o

ASM_OBJS  = getFileCount.o nameCompare.o nameCompareRev.o timeCompare.o \
            timeCompareRev.o

OBJS      = ${C_OBJS} ${ASM_OBJS}
EC_OBJS   = $(subst main.o,mainEC.o,$(OBJS))

EXE       = myls 
EC_EXE    = mylsEC

#
# Relevant man pages:
#
# man gcc
# man as
# man lint
#

GCC       = gcc
ASM       = $(GCC)

GCC_FLAGS = -c -g -Wall -D__EXTENSIONS__ -std=c11
ASM_FLAGS = -c -g
LD_FLAGS  = -g -Wall

#
# Standard rules
#
.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#

$(EXE): $(OBJS)
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done. Generated executable: $(EXE)"

EC: $(EC_OBJS)
	@echo "Linking all object modules ..."
	$(GCC) -o $(EC_EXE) $(LD_FLAGS) $(EC_OBJS)
	@echo ""
	@echo "Done. Generated executable: $(EC_EXE)"

${C_OBJS}:      ${HEADERS}


clean:
	@echo "Cleaning up project directory ..."
	rm -f *.o $(EXE) *.ln core a.out testnameCompare testtimeCompare mylsEC
	@echo ""
	@echo "Clean."

testnameCompare: test.h pa4.h nameCompare.o testnameCompare.o
	@echo "Compiling testnameCompare.c"
	gcc -g -o testnameCompare testnameCompare.c nameCompare.s
	@echo "Done."

testtimeCompare: test.h pa4.h timeCompare.o testtimeCompare.o pa4Globals.c
	@echo "Compiling testtimeCompare.c"
	gcc -g -o testtimeCompare testtimeCompare.c timeCompare.s pa4Globals.c
	@echo "Done."

new:
	make clean
	make

#####################################################################
#        Beginning of student section. Add your rules below.        #
#####################################################################



#####################################################################
#           End of student section. Add your rules above.           #
#####################################################################
