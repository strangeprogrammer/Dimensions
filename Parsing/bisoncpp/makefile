SUBFOLDERS	:= flexcpp
HEADERS		:= Parser.hpp Parser.proto
SOURCES		:= Wrapper.cpp
include make.i

ifeq ($(TEST),true)
GTARGET := testgrammar
else
GTARGET := grammar
endif

./flexcpp/Scanner.hpp : ./flexcpp/lexer
	$(MAKE) -C ./flexcpp/ Scanner.hpp

Parser.hpp Parser.proto : $(GTARGET) ./flexcpp/Scanner.hpp
	$(MAKE) clean
	echo "Creating parser source files..."
	bisonc++ -b Parser.proto -c Parser.hpp -i Parser.ihpp -p Parser.cpp $(GTARGET)

Parser.cpp : Parser.hpp
	$(call touche)

Wrapper.cpp : Parser.cpp
	$(call touche)

#For testing and debugging purposes

parsertest : testparser.o up.o
	$(call testdebug,TEST)
	$(call testdebug,PARSER_DEBUG)
	echo "Finalizing parser testing executable..."
	$(OUT) $@ $^ ../../Etc/Globals.cpp

testparser.o : testparser.cpp
	$(call testdebug,TEST)
	$(call testdebug,PARSER_DEBUG)
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ $^

testparser.cpp : Parser.hpp

#Miscellaneous

listvars ::
	echo "GTARGET     = $(GTARGET)"

clean ::
	$(call cleanup,Parser.proto)

clean ::
	$(call cleanup,Parser.hpp)

clean ::
	$(call cleanup,Parser.ihpp)

clean ::
	$(call cleanup,Parser.cpp)

squeaky ::
	$(call cleanup,testparser.o)

squeaky ::
	$(call cleanup,parsertest)
