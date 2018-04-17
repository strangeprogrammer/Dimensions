SUBFOLDERS	:= 
HEADERS		:= Details.hpp ExecBlocks.hpp KVP.hpp Node.hpp
SOURCES		:= 
include make.i

#For testing and debugging purposes

microtest : testmain.o ../../Etc/Globals.cpp
	$(call testdebug,MICRO_DEBUG)
	echo "Finalizing microtest..."
	$(OUT) $@ $^

testmain.o : testmain.cpp local.hpp all.hpp
	$(call testdebug,MICRO_DEBUG)
	echo "Compiling testmain.o..."
	$(COMP) $@ $<

#Miscellaneous

squeaky ::
	$(call cleanup,microtest)
