#Path to all makefiles (excluding Template):
#./{,DataStructs/{,M{i,a}cro},Execution,Etc,Parsing/{,bisoncpp{,/flexcpp}}}/makefile

#Important stuff for the rest of the makefile

#Execute each target using only 1 subshell per target
SHELL		:= /bin/bash
.SHELLFLAGS	:= -e $(.SHELLFLAGS)
.ONESHELL : $(SHELL)

#Make the variable dump the default action for safety purposes
.DEFAULT_GOAL	:= listvars

#Make 'make' be silent
.SILENT :

#Disable implicit rules
.SUFFIXES :

#Set up some variable export rules
export								#Export all variables by default
export SHELL .SHELLFLAGS					#These require explicit exportion
unexport ROOT SUBFOLDERS HEADERS SOURCES OBJECTS UPO UPH	#Don't export site-specific variables

#Targets that aren't real files
.PHONY : listvars clean squeaky link compile update force

#Compilation stuff

ifeq ($(DEBUG),true)
DBGFLAGS	:= $(DBGFLAGS) -ggdb -DDEBUG=
endif
COMPILER	:= g++
CFLAGS		:= -std=c++11 -Wall -Wextra -Wno-pedantic
EXTRAFLAGS	:= -Wno-unused-parameter -Wno-parentheses
CPP		:= $(COMPILER) $(CFLAGS) $(EXTRAFLAGS) $(DBGFLAGS)
COMP		:= $(CPP) -c -o
LINK		:= ld -r -o
OUT		:= $(CPP) -o

#Commonly used functions

define testdebug
	if [ "$($1)" != "true" ]
	then
		echo "Target '$@' requires the \"$1\" variable to be set to 'true'."
		exit 1
	fi
endef

define cleanup
	rm $1 &>/dev/null && echo "Removing $1..." || true
endef

define touche
	echo "Updating $$PWD/$@..."
	touch $@
endef

#Source file stuff

OBJECTS		:= $(patsubst %.cpp,%.o,$(SOURCES))
UPO		:= $(addsuffix /up.o,$(SUBFOLDERS))

link : up.o

up.o : $(OBJECTS) $(UPO)
	echo "Linking $$PWD/$@..."
	$(LINK) $@ $^

$(UPO) : force
	echo "Checking directory $$PWD/$(dir $@) for updates..."
	$(MAKE) -C ./$(dir $@)/ up.o

compile : $(OBJECTS)

$(OBJECTS) : %.o : %.cpp
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ $^

#Header file stuff

UPH		:= $(addsuffix /up.hpp,$(SUBFOLDERS))

update : up.hpp

up.hpp : local.hpp $(UPH)
	$(call touche)

$(UPH) : force
	echo "Checking directory $$PWD/$(dir $@) for updates..."
	$(MAKE) -C ./$(dir $@)/ up.hpp

local.hpp : $(HEADERS)
	$(call touche)

#Miscellaneous utilities

listvars ::
	echo "make invoked as \"$(MAKE)\""
	echo "ROOT        = $(ROOT)"
	echo "SHELL       = $(SHELL)"
	echo ".SHELLFLAGS = $(.SHELLFLAGS)"
	echo "SUBFOLDERS  = $(SUBFOLDERS)"
	echo "HEADERS     = $(HEADERS)"
	echo "SOURCES     = $(SOURCES)"
	echo "OBJECTS     = $(OBJECTS)"
	echo "UPO         = $(UPO)"
	echo "UPH         = $(UPH)"
	echo "DEBUG       = $(DEBUG)"
	echo "DBGFLAGS    = $(DBGFLAGS)"
	echo "COMPILER    = $(COMPILER)"
	echo "CFLAGS      = $(CFLAGS)"
	echo "EXTRAFLAGS  = $(EXTRAFLAGS)"
	echo "CPP         = $(CPP)"
	echo "COMP        = $(COMP)"
	echo "LINK        = $(LINK)"
	echo "OUT         = $(OUT)"

clean ::
	for INDEX in $(OBJECTS)
	do
		$(call cleanup,$$INDEX)
	done
	unset -v INDEX

clean ::
	$(call cleanup,up.o)

squeaky :: clean

squeaky ::
	$(call cleanup,testmain.o)
