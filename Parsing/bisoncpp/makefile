SUBFOLDERS	:= 
#HEADERS	:= 
#SOURCES	:= 

#Project related

parser_module.o : parser.cpp
	@ #Silence make
	echo "Compiling parser module..."
	$(COMP) ./parser_module.o ./parser.cpp

parser.cpp : grammar
	@ #Silence make
	[ -f ./Parserbase.hpp -o -f ./Parser.hpp -o -f ./Parser.ihpp -o -f ./parser.cpp ] || echo "Removing leftover parser source files..."
	rm ./Parserbase.hpp ./Parser.hpp ./Parser.ihpp ./parser.cpp &>/dev/null || true
	echo "Creating parser source files..."
	bisonc++ -b Parserbase.hpp -c Parser.hpp -i Parser.ihpp -p parser.cpp grammar

#For testing and debugging purposes

parsertest : parser_module.o testparser.o
	@ #Silence make
	echo "Linking parser testing executable..."
	$(LINK) ./parsertest ./parser_module.o ./testparser.o

testparser.o : testparser.cpp
	@ #Silence make
	echo "Compiling parser testing module..."
	$(COMP) ./testparser.o ./testparser.cpp
