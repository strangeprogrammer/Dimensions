SUBFOLDERS	:= bisoncpp
HEADERS		:= ParseEnv.hpp ParseEnv.proto
SOURCES		:= 
include make.i

#For testing and debugging purposes

chaintest : testchain.o up.o ../Etc/Globals.cpp
	$(call testdebug,CHAIN_DEBUG)
	echo "Finalizing parser testing executable..."
	$(OUT) $@ $^

testchain.o : testchain.cpp up.hpp
	$(call testdebug,CHAIN_DEBUG)
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ testchain.cpp

#Miscellaneous

squeaky ::
	$(call cleanup,testchain.o)

squeaky ::
	$(call cleanup,chaintest)
