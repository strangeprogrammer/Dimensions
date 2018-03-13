#Project related

scanner_module.o : scanner.cpp
	@ #Silence make
	echo "Compiling scanner module..."
	$(COMP) ./scanner_module.o ./scanner.cpp

scanner.cpp : lexer
	@ #Silence make
	[ -f ./Scannerbase.hpp -o -f ./Scanner.hpp -o -f ./Scanner.ihpp -o -f ./scanner.cpp ] || echo "Removing leftover scanner source files..."
	rm ./Scannerbase.hpp ./Scanner.hpp ./Scanner.ihpp ./scanner.cpp &>/dev/null || true
	echo "Creating scanner source files..."
	flexc++ -b Scannerbase.hpp -c Scanner.hpp -i Scanner.ihpp -l scanner.cpp lexer
	echo "Modifying scanner headers..."
	echo '#ifdef DEBUG' >>./Scanner.ihpp
	echo '	#include "parsingTest.hpp"' >>./Scanner.ihpp
	echo '#else /*DEBUG*/' >>./Scanner.ihpp
	echo '	#include "../bisoncpp/Parser.hpp"' >>./Scanner.ihpp
	echo '#endif /*DEBUG*/' >>./Scanner.ihpp

#For testing and debugging purposes

scannertest : scanner.cpp testscanner.o
	@ #Silence make
	echo "Linking scanner testing executable..."
	$(LINK) ./scannertest ./scanner_module.o ./testscanner.o

testscanner.o : testscanner.cpp
	@ #Silence make
	echo "Compiling scanner testing module..."
	$(COMP) ./testscanner.o ./testscanner.cpp

#Miscellaneous

#TODO: Change the "*.o" here to "$(OBJECTS)" in the future
clean :
	@ #Silence make
	rm -f *.o >/dev/null 2>&1 || return 0
