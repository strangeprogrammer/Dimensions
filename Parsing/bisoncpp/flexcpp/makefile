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
		echo '#ifdef DEBUG'
		echo '	#include "parsingTest.hpp"'
		echo '#endif //DEBUG'
	} >>./Scanner.ihpp

Wrapper.cpp : Scanner.cpp
	$(call touche)

#For testing and debugging purposes

scannertest : testscanner.o Scanner.cpp
	$(call testdebug,SCANNER_DEBUG)
	$(call testdebug,DEBUG)
	echo "Finalizing scanner testing executable..."
	$(OUT) $@ $^

testscanner.o : testscanner.cpp
	$(call testdebug,SCANNER_DEBUG)
	$(call testdebug,DEBUG)
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ $^

testscanner.cpp : Scanner.hpp

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
	$(call cleanup,testscanner.o)

squeaky ::
	$(call cleanup,scannertest)
