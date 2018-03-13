#For recursion purposes
MAKEFILES	:= make.i
ifeq ($(MAKELEVEL),0)
MAKEBKP		:= $(MAKE)
endif
MAKE		:= $(MAKEBKP) MAKEFILES="../$(MAKEFILES)"

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

#Export all variables
export
#Explicitly export some tricky variables
export SHELL .SHELLFLAGS

#Targets that aren't real files
.PHONY : listvars

#Make the variable dump the default
.DEFAULT : listvars
listvars :
	@ #Silence make
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
