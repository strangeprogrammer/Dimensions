SUBFOLDERS	:= flexcpp bisoncpp
HEADERS		:= 
SOURCES		:= 
include make.i

#Targets that shouldn't be treated as real files
.PHONY : scanner parser scanner_src parser_src scannertest parsertest

#Compilation stuff

scanner :
	@ #Silence make
	$(MAKE) -C ./flexcpp/ scanner_module.o

parser :
	@ #Silence make
	$(MAKE) -C ./bisoncpp/ parser_module.o

#Setup stuff

scanner_src :
	@ #Silence make
	$(MAKE) -C ./flexcpp/ Scanner.cpp

parser_src :
	@ #Silence make
	$(MAKE) -C ./bisoncpp/ Parser.cpp

#For testing and debugging purposes

define TEST
	if [ -z "$(DBGFLAGS)" ] #If the debugging flags haven't been set
	then
		echo "This target requires the \"DEBUG\" variable to be set."
		exit 1
	else
		$(MAKE) -C ./$(1)/ $@
	fi
endef

scannertest : 
	@ #Silence make
	$(call TEST,flexcpp)

parsertest :
	@ #Silence make
	$(call TEST,bisoncpp)
