SUBFOLDERS	:= 
HEADERS		:= Scanner.proto Scanner.hpp
SOURCES		:= Wrapper.cpp

ifeq ($(SCANNER_DEBUG),true)
DBGFLAGS := -DSCANNER_DEBUG=
endif

include make.i

Scanner.cpp Scanner.hpp : lexer
	$(MAKE) clean
	echo "Creating scanner source files..."
	flexc++ -b Scanner.proto -c Scanner.hpp -i Scanner.ihpp -l Scanner.cpp lexer
	echo "Editing scanner header file..."
	{
		echo '#ifdef SCANNER_DEBUG'
		echo '	#include "parsingTest.hpp"'
		echo '#endif //SCANNER_DEBUG'
	} >>./Scanner.ihpp

Wrapper.cpp : Scanner.cpp
	$(call touche)

#For testing and debugging purposes

scannertest : testmain.o Scanner.cpp
	$(call testdebug,SCANNER_DEBUG)
	echo "Finalizing scanner testing executable..."
	$(OUT) $@ $^

testmain.o : testmain.cpp
	$(call testdebug,SCANNER_DEBUG)
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ $^

testmain.cpp : Scanner.hpp

#Miscellaneous

clean ::
	$(call cleanup,Scanner.proto)

clean ::
	$(call cleanup,Scanner.hpp)

clean ::
	$(call cleanup,Scanner.ihpp)

clean ::
	$(call cleanup,Scanner.cpp)

squeaky ::
	$(call cleanup,scannertest)
