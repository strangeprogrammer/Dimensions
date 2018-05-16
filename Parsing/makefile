SUBFOLDERS	:= bisoncpp
HEADERS		:= ParseEnv.hpp
SOURCES		:= ParseEnv.cpp
include make.i

$(ROOT)/up.o :
	$(MAKE) -C $(ROOT) up.o

#For testing and debugging purposes

chaintest : testmain.o up.o ../Etc/Globals.cpp $(ROOT)/up.o
	$(call testdebug,CHAIN_DEBUG)
	echo "Finalizing chain generating testing executable..."
	$(OUT) $@ $^

testmain.o : testmain.cpp
	$(call testdebug,CHAIN_DEBUG)
	echo "Compiling $$PWD/$@..."
	$(COMP) $@ testmain.cpp

#Miscellaneous

squeaky ::
	$(call cleanup,testmain.o)

squeaky ::
	$(call cleanup,chaintest)
