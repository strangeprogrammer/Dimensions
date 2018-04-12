SUBFOLDERS	:= 
HEADERS		:= Parser.proto Parser.hpp
SOURCES		:= 
include make.i

../flexcpp/Scanner.cpp : ../flexcpp/lexer
	$(MAKE) -C ../flexcpp/ Scanner.cpp

ifeq ($(TEST),true)
GTARGET := testgrammar
else
GTARGET := grammar
endif

Parser.cpp : $(GTARGET)
	$(MAKE) clean
	echo "Creating parser source files..."
	bisonc++ -b Parser.proto -c Parser.hpp -i Parser.ihpp -p Parser.cpp $(GTARGET)

#For testing and debugging purposes

parsertest : testparser.cpp Parser.cpp ../flexcpp/Scanner.cpp
	echo "Compiling and linking parser testing executable..."
	$(LINK) ./parsertest ./testparser.cpp

listvars ::
	echo "GTARGET     = $(GTARGET)"

clean ::
	$(call cleanup,Parser.proto,"Parser.proto")

clean ::
	$(call cleanup,Parser.hpp,"Parser.hpp")

clean ::
	$(call cleanup,Parser.ihpp,"Parser.ihpp")

clean ::
	$(call cleanup,Parser.cpp,"Parser.cpp")
