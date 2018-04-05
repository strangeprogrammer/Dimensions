SUBFOLDERS	:= 
HEADERS		:= 
SOURCES		:= 
include make.i

#Project related

parser_module.o : Parser.cpp
	echo "Compiling parser module..."
	$(COMP) ./parser_module.o ./Parser.cpp

Parser.cpp : grammar
	[ -f ./Parserbase.hpp -o -f ./Parser.hpp -o -f ./Parser.ihpp -o -f ./Parser.cpp ] || echo "Removing leftover parser source files..."
	rm ./Parserbase.hpp ./Parser.hpp ./Parser.ihpp ./Parser.cpp &>/dev/null || true
	echo "Creating parser source files..."
	bisonc++ -b Parserbase.hpp -c Parser.hpp -i Parser.ihpp -p Parser.cpp grammar

#For testing and debugging purposes

parsertest : parser_module.o testparser.o ../flexcpp/scanner_module.o
	$(call testDebug)
	echo "Linking parser testing executable..."
	$(LINK) ./parsertest ./parser_module.o ./testparser.o ../flexcpp/scanner_module.o

testparser.o : testparser.cpp
	$(call testDebug)
	echo "Compiling parser testing module..."
	$(COMP) ./testparser.o ./testparser.cpp
