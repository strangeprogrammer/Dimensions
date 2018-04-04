SUBFOLDERS	:= 
HEADERS		:= 
SOURCES		:= 
include make.i

#Project related

scanner_module.o : Scanner.cpp
	@ #Silence make
	echo "Compiling scanner module..."
	$(COMP) ./scanner_module.o ./Scanner.cpp

Scanner.cpp : lexer
	@ #Silence make
	[ -f ./Scannerbase.hpp -o -f ./Scanner.hpp -o -f ./Scanner.ihpp -o -f ./Scanner.cpp ] || echo "Removing leftover scanner source files..."
	rm ./Scannerbase.hpp ./Scanner.hpp ./Scanner.ihpp ./Scanner.cpp &>/dev/null || true
	echo "Creating scanner source files..."
	flexc++ -b Scannerbase.hpp -c Scanner.hpp -i Scanner.ihpp -l Scanner.cpp lexer
	echo "Modifying scanner headers..."
	echo '#ifdef DEBUG' >>./Scanner.ihpp
	echo '	#include "parsingTest.hpp"' >>./Scanner.ihpp
	echo '#else //DEBUG' >>./Scanner.ihpp
	echo '	#include "all.hpp"' >>./Scanner.ihpp
	echo '#endif //DEBUG' >>./Scanner.ihpp

#For testing and debugging purposes

scannertest : Scanner.cpp testscanner.o
	@ #Silence make
	$(call testDebug)
	echo "Linking scanner testing executable..."
	$(LINK) ./scannertest ./scanner_module.o ./testscanner.o

testscanner.o : testscanner.cpp
	@ #Silence make
	$(call testDebug)
	echo "Compiling scanner testing module..."
	$(COMP) ./testscanner.o ./testscanner.cpp
