SUBFOLDERS	:= flexcpp/ bisoncpp/
#HEADERS	:= 
#SOURCES	:= 

#Targets that shouldn't be treated as real files
.PHONY : scanner parser scanner_src parser_src scannertest parsertest

#Compilation stuff

scanner :
	@ #Silence make
	$(MAKE) ./flexcpp/ scanner_module.o

parser :
	@ #Silence make
	$(MAKE) ./bisoncpp/ parser_module.o

#Setup stuff

scanner_src :
	@ #Silence make
	$(MAKE) ./flexcpp/ scanner.cpp

parser_src :
	@ #Silence make
	$(MAKE) ./bisoncpp/ parser.cpp

#For testing and debugging purposes

scannertest parsertest :
	@ #Silence make
	#If the debugging flags haven't been set
	if [ -z "$(DBGFLAGS)" ]
	then
		echo "This target requires the \"DEBUG\" variable to be set."
		exit 1
	else
		$(MAKE) ./flexcpp/ $@
	fi
