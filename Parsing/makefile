SUBFOLDERS	:= bisoncpp
HEADERS		:= ParseEnv.hpp ParseEnv.proto
SOURCES		:= 
include make.i

#For testing and debugging purposes

chaintest : testmain.o up.o ../Etc/Globals.cpp
	$(call testdebug,CHAIN_DEBUG)
	echo "Finalizing parser testing executable..."
	$(OUT) $@ $^

testmain.o : testmain.cpp up.hpp
	$(call testdebug,CHAIN_DEBUG)
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ testmain.cpp

#Miscellaneous

squeaky ::
	$(call cleanup,chaintest)
