#Path to all makefiles (excluding Template):
#./{,DataStructs/{,M{i,a}cro},Execution,Etc,Parsing/{,{flex,bison}cpp}}/makefile

#Execute each target using only 1 subshell per target
ifeq ($(MAKELEVEL),0)
SHELL		:= /bin/bash
.SHELLFLAGS	:= -e $(.SHELLFLAGS)
endif
.ONESHELL : $(SHELL)

#For compiling and linking the program
ifeq ($(DEBUG),true)
DBGFLAGS	:= -ggdb -DDEBUG=
else
DBGFLAGS	:= 
endif
COMPILER	:= g++
CFLAGS		:= -std=c++11 -Wall -Wpedantic
CPP		:= $(COMPILER) $(CFLAGS) $(DBGFLAGS)
COMP		:= $(CPP) -c -o
LINK		:= $(CPP) -o

define testDebug
	if [ "$(DEBUG)" != "true" ] #If the debugging flags haven't been set
	then
		echo "Target '$@' requires the \"DEBUG\" variable to be set to 'true'."
		exit 1
	fi
endef

#Set up some variable export rules
export					#Export all variables by default
export SHELL .SHELLFLAGS		#These require explicit exportion
unexport SUBFOLDERS HEADERS SOURCES	#Don't export site-specific variables

#Targets that aren't real files
.PHONY : listvars clean update

#Make the variable dump the default for safety purposes
.DEFAULT : listvars

listvars :
	@ #Silence make
	#TODO: Add something so that a path can be given along which all variables are listed
	echo "make invoked as \"$(MAKE)\""
	echo "SHELL       = $(SHELL)"
	echo ".SHELLFLAGS = $(.SHELLFLAGS)"
	echo "SUBFOLDERS  = $(SUBFOLDERS)"
	echo "HEADERS     = $(HEADERS)"
	echo "SOURCES     = $(SOURCES)"
	echo "DEBUG       = $(DEBUG)"
	echo "DBGFLAGS    = $(DBGFLAGS)"
	echo "COMPILER    = $(COMPILER)"
	echo "CFLAGS      = $(CFLAGS)"
	echo "CPP         = $(CPP)"
	echo "COMP        = $(COMP)"
	echo "LINK        = $(LINK)"

#TODO: Change the "*.o" here to "$(OBJECTS)" or something else in the future
clean :
	@ #Silence make
	rm -f *.o >/dev/null 2>&1 || return 0

#For updating timestamps recursively throughout the project

.PHONY : $(SUBFOLDERS)

update : $(SUBFOLDERS)
	@ #Silence make
	$(MAKE) up.hpp

$(SUBFOLDERS) :
	@ #Silence make
	echo "Checking directory $$PWD/$@ for updates..."
	$(MAKE) -C ./$@/ update

up.hpp : $(addsuffix /up.hpp,$(SUBFOLDERS)) local.hpp
	@ #Silence make
	echo "Updating $$PWD/up.hpp..."
	touch up.hpp

local.hpp : $(SOURCES) $(HEADERS)
	@ #Silence make
	echo "Updating $$PWD/local.hpp..."
	touch local.hpp
