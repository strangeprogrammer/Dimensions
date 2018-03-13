include make.i

#Targets that shouldn't be treated as real files
.PHONY : scanner parser scanner_src parser_src flexcpp/listvars scannertest bisoncpp/listvars parsertest clean flexcpp/clean bisoncpp/clean

#Compilation stuff

scanner :
	@ #Silence make
	$(MAKE) -C ./flexcpp/ scanner_module.o

parser :
	@ #Silence make
	$(MAKE) -C ./bisoncpp/ parser_module.o

#Setup stuff

scanner_src : flexcpp/lexer
	@ #Silence make
	$(MAKE) -C ./flexcpp/ scanner.cpp

parser_src :
	@ #Silence make
	$(MAKE) -C ./bisoncpp/ parser.cpp

#Misc work to do

all.hpp :
	@ #Silence make
	touch ./all.hpp

#For testing and debugging purposes

flexcpp/listvars :
	@ #Silence make
	$(MAKE) -C ./flexcpp/ listvars

scannertest :
	@ #Silence make
	#If the debugging flags haven't been set
	if [ -z "$(DBGFLAGS)" ]
	then
		echo "This target requires the \"DEBUG\" variable to be set."
		exit 1
	else
		$(MAKE) -C ./flexcpp/ scannertest
	fi

bisoncpp/listvars :
	@ #Silence make
	$(MAKE) -C ./bisoncpp/ listvars

parsertest :
	@ #Silence make
	#If the debugging flags haven't been set
	if [ -z "$(DBGFLAGS)" ]
	then
		echo "This target requires the \"DEBUG\" variable to be set."
		exit 1
	else
		$(MAKE) -C ./bisoncpp/ parsertest
	fi

#Miscellaneous

#TODO: Change the "*.o" here to "$(OBJECTS)" in the future
clean :
	@ #Silence make
	rm -f *.o >/dev/null 2>&1 || return 0

flexcpp/clean :
	@ #Silence make
	$(MAKE) -C ./flexcpp/ clean

bisoncpp/clean :
	@ #Silence make
	$(MAKE) -C ./bisoncpp/ clean
