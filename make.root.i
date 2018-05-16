#Path to all makefiles (excluding Template):
#./{,DataStructs/{,M{i,a}cro},Execution,Etc,Parsing/{,bisoncpp{,/flexcpp}}}/makefile

#Important stuff for the rest of the makefile

#Execute each target using only 1 subshell per target
SHELL		:= /bin/bash
.SHELLFLAGS	:= -e $(.SHELLFLAGS)
.ONESHELL : $(SHELL)

#Make the variable dump the default action for safety purposes
.DEFAULT_GOAL	:= listvars

#Make 'make' be silent when debugging is disabled
ifneq ($(MAKE_DEBUG),true)
.SILENT :
endif

#Disable implicit rules
.SUFFIXES :

#Set up some variable export rules
export										#Export all variables by default
export SHELL .SHELLFLAGS							#These require explicit exportion
unexport ROOT SUBFOLDERS HEADERS SOURCES OBJECTS UPO EMPTYOBJ UPHPP ALLHPP	#Don't export site-specific variables

#Targets that aren't real files
.PHONY : listvars clean squeaky force

#Compilation stuff

ifeq ($(DEBUG),true)
DBGFLAGS	:= $(DBGFLAGS) -ggdb -DDEBUG=
else
ANTIFLAGS	:= -Wno-pedantic -Wno-unused-parameter -Wno-parentheses
endif
COMPILER	:= g++
CFLAGS		:= -std=c++11 -Wall -Wextra
CPP		:= $(COMPILER) $(CFLAGS) $(ANTIFLAGS) $(DBGFLAGS)
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

#Variable generation

OBJECTS		:= $(patsubst %.cpp,%.o,$(SOURCES))
UPO		:= $(addsuffix /up.o,$(SUBFOLDERS))
ifeq ($(OBJECTS),)
ifeq ($(UPO),)
EMPTYOBJ	:= $(ROOT)/empty.o

$(EMPTYOBJ) : $(ROOT)/empty.cpp
	echo "Compiling $@..."
	$(COMP) $@ $^
endif
endif
UPHPP		:= $(addsuffix /up.hpp,$(SUBFOLDERS))
ALLHPP		:= $(addsuffix /all.hpp,$(SUBFOLDERS))

#Object file stuff

up.o : $(OBJECTS) $(UPO) $(EMPTYOBJ)
	echo "Linking $$PWD/$@..."
	$(LINK) $@ $^

$(UPO) : force
	echo "Checking directory $$PWD/$(dir $@) for object updates..."
	$(MAKE) -C $(dir $@) up.o

$(OBJECTS) : %.o : %.cpp
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ $<

#Header file stuff

ifeq ($(ROOT),./)
all.root.hpp : up.hpp
	$(call touche)

all.hpp : all.root.hpp
	$(call touche)
else
../all.hpp : force
	$(MAKE) -C .. all.hpp

all.hpp : ../all.hpp
	$(call touche)
endif

up.hpp : local.hpp $(UPHPP)
	$(call touche)

$(UPHPP) : force
	echo "Checking directory $$PWD/$(dir $@) for header updates..."
	$(MAKE) -C $(dir $@) up.hpp

local.hpp : $(HEADERS)
	$(call touche)

#Miscellaneous utilities

listvars ::
	echo "make invoked as \"$(MAKE)\""
	echo "ROOT          = $(ROOT)"
	echo "SHELL         = $(SHELL)"
	echo ".SHELLFLAGS   = $(.SHELLFLAGS)"
	echo ".DEFAULT_GOAL = $(.DEFAULT_GOAL)"
	echo "SUBFOLDERS    = $(SUBFOLDERS)"
	echo "HEADERS       = $(HEADERS)"
	echo "SOURCES       = $(SOURCES)"
	echo "OBJECTS       = $(OBJECTS)"
	echo "UPO           = $(UPO)"
	echo "EMPTYOBJ      = $(EMPTYOBJ)"
	echo "UPHPP         = $(UPHPP)"
	echo "ALLHPP        = $(ALLHPP)"
	echo "DEBUG         = $(DEBUG)"
	echo "DBGFLAGS      = $(DBGFLAGS)"
	echo "COMPILER      = $(COMPILER)"
	echo "CFLAGS        = $(CFLAGS)"
	echo "ANTIFLAGS     = $(ANTIFLAGS)"
	echo "CPP           = $(CPP)"
	echo "COMP          = $(COMP)"
	echo "LINK          = $(LINK)"
	echo "OUT           = $(OUT)"

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
