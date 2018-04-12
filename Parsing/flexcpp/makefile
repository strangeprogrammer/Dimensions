SUBFOLDERS	:= 
HEADERS		:= Scanner.proto Scanner.hpp
SOURCES		:= 
include make.i

Scanner.cpp : lexer
	$(MAKE) clean
	echo "Creating scanner source files..."
	flexc++ -b Scanner.proto -c Scanner.hpp -i Scanner.ihpp -l Scanner.cpp lexer
	echo "Modifying scanner headers..."
	{
		echo '#ifdef DEBUG'
		echo '	#include "parsingTest.hpp"'
		echo '#endif //DEBUG'
	} 1>>./Scanner.ihpp

#For testing and debugging purposes

scannertest : testscanner.cpp Scanner.cpp
	echo "Compiling and linking scanner testing executable..."
	$(LINK) ./scannertest ./testscanner.cpp

clean ::
	$(call cleanup,Scanner.proto,"Scanner.proto")

clean ::
	$(call cleanup,Scanner.hpp,"Scanner.hpp")

clean ::
	$(call cleanup,Scanner.ihpp,"Scanner.ihpp")

clean ::
	$(call cleanup,Scanner.cpp,"Scanner.cpp")
