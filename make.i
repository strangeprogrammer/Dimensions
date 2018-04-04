#Path to all makefiles (excluding Template):
#./{,DataStructs/{,M{i,a}cro},Execution,Etc,Parsing/{,{flex,bison}cpp}}/makefile

#Execute each target using only 1 subshell per target
SHELL		:= /bin/bash
.SHELLFLAGS	:= -e $(.SHELLFLAGS)
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

#TODO: Implement compiled headers later
GCHEADERS	:= $(patsubst %.hpp,%.gchpp,$(HEADERS))
OBJECTS		:= $(patsubst %.cpp,%.o,$(SOURCES))

#Set up some variable export rules
export							#Export all variables by default
export SHELL .SHELLFLAGS				#These require explicit exportion
unexport SUBFOLDERS HEADERS SOURCES GCHEADERS OBJECTS	#Don't export site-specific variables

#Targets that aren't real files
.PHONY : listvars clean link compile update

#Make 'make' be silent
.SILENT :

#Make the variable dump the default for safety purposes
.DEFAULT : listvars

listvars :
	echo "make invoked as \"$(MAKE)\""
	echo "SHELL       = $(SHELL)"
	echo ".SHELLFLAGS = $(.SHELLFLAGS)"
	echo "SUBFOLDERS  = $(SUBFOLDERS)"
	echo "HEADERS     = $(HEADERS)"
	echo "SOURCES     = $(SOURCES)"
	echo "GCHEADERS   = $(GCHEADERS)"
	echo "OBJECTS     = $(OBJECTS)"
	echo "DEBUG       = $(DEBUG)"
	echo "DBGFLAGS    = $(DBGFLAGS)"
	echo "COMPILER    = $(COMPILER)"
	echo "CFLAGS      = $(CFLAGS)"
	echo "CPP         = $(CPP)"
	echo "COMP        = $(COMP)"
	echo "LINK        = $(LINK)"

#TODO: Expand upon this next part later

link : up.o

up.o : $(OBJECTS)
	echo "Linking $@..."
	$(LINK) $@ $^

compile : $(OBJECTS)

$(OBJECTS) : %.o : %.cpp
	echo "Compiling $@..."
	$(COMP) $@ $^

clean :
	echo "Removing all object files and compiled headers..."
	rm -f $(OBJECTS) $(GCHEADERS) >/dev/null 2>&1 || return true

#For updating timestamps recursively throughout the project

.PHONY : $(SUBFOLDERS)

update : $(SUBFOLDERS)
	$(MAKE) up.hpp

$(SUBFOLDERS) :
	echo "Checking directory $$PWD/$@ for updates..."
	$(MAKE) -C ./$@/ update

up.hpp : $(addsuffix /up.hpp,$(SUBFOLDERS)) local.hpp
	echo "Updating $$PWD/up.hpp..."
	touch up.hpp

local.hpp : $(SOURCES) $(HEADERS)
	echo "Updating $$PWD/local.hpp..."
	touch local.hpp
