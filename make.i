#For recursion purposes
MAKEFILES	:= make.i
ifeq ($(MAKELEVEL),0)
MAKEBKP		:= $(MAKE)
endif
MAKE		:= $(MAKEBKP) MAKEFILES="../$(MAKEFILES)" -C

#Execute each target using only 1 subshell for the whole recipe
SHELL		:= /bin/bash
ifeq ($(MAKELEVEL),0)
.SHELLFLAGS	:= -e $(.SHELLFLAGS)
endif
.ONESHELL : $(SHELL)

#For compiling and linking the program
ifdef DEBUG
DBGFLAGS	:= -ggdb -DDEBUG=
else
DBGFLAGS	:= 
endif
COMPILER	:= g++
CFLAGS		:= -std=c++11 -Wall -Wpedantic
CPP		:= $(COMPILER) $(CFLAGS) $(DBGFLAGS)
COMP		:= $(CPP) -c -o
LINK		:= $(CPP) -o

#Set up some variable export rules
export #All variables
export SHELL .SHELLFLAGS

#Targets that aren't real files
.PHONY : listvars clean

#Make the variable dump the default
.DEFAULT : listvars

listvars :
	@ #Silence make
	#TODO: Add something so that a path can be given along which all variables are listed
	echo "make invoked as \"$(MAKEBKP)\""
	echo "sub-makefiles to be invoked as \"$(MAKE)\""
	echo "MAKEFILES   = $(MAKEFILES)"
	echo "SHELL       = $(SHELL)"
	echo ".SHELLFLAGS = $(.SHELLFLAGS)"
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

#Update timestamps throughout the project (requires some complex chaining for complex reasons)
unexport SUBFOLDERS
local.hpp : $(patsubst /,/up.gch,$(SUBFOLDERS))
	@ #Silence make
	for FOLDER in "$(^D)"
	do
		$(MAKE) ./$$FOLDER/ up.gch
	done
	touch local.hpp

up.hpp : local.hpp
	@ #Silence make
	touch up.hpp

up.gch : up.hpp
	@ #Silence make
	$(COMP) up.ghc up.hpp
