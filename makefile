SUBFOLDERS	:= Etc Parsing DataStructs Execution
HEADERS		:= 
SOURCES		:= 
include make.i

#Targets that shouldn't be treated as real files
.PHONY : scanner_src scanner scannertest parser_src parser parsertest Parsing/bisoncpp/listvars Parsing/flexcpp/listvars touchall test

#For regular compiling as well as testing and debugging
scanner_src scanner scannertest parser_src parser parsertest Parsing/bisoncpp/listvars Parsing/flexcpp/listvars :
	@ #Silence make
	$(MAKE) -C ./Parsing/ $@

up.gchpp : update
	@ #Silence make
	echo "Updating root compiled header file..."
	$(COMP) up.gchpp up.hpp
