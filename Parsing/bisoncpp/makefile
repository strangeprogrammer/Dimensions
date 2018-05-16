SUBFOLDERS	:= flexcpp
HEADERS		:= Parser.hpp Parser.proto
SOURCES		:= Wrapper.cpp
include make.i

#FIXME the file creation process just below this note

ifeq ($(PARSER_DEBUG),true)
GTARGET := testgrammar
else
GTARGET := grammar
endif

Parser.hpp Parser.proto : $(GTARGET) flexcpp/up.hpp
	$(MAKE) clean
	echo "Creating parser source files..."
	bisonc++ -b Parser.proto -c Parser.hpp -i Parser.ihpp -p Parser.cpp $(GTARGET)

Parser.cpp : Parser.hpp Parser.proto
	$(call touche)

Wrapper.cpp : Parser.cpp
	$(call touche)

#For testing and debugging purposes

parsertest : testmain.o up.o
	$(call testdebug,PARSER_DEBUG)
	echo "Finalizing parser testing executable..."
	$(OUT) $@ $^ ../../Etc/Globals.cpp

testmain.o : testmain.cpp
	$(call testdebug,PARSER_DEBUG)
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ $^

testmain.cpp : Parser.hpp

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
	$(call cleanup,testmain.o)

squeaky ::
	$(call cleanup,parsertest)
