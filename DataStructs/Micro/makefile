SUBFOLDERS	:= 
HEADERS		:= Details.hpp ExecBlocks.hpp KVP.hpp Node.hpp
SOURCES		:= 
include make.i

microtest : testmain.o ../../Etc/Globals.cpp
	$(call testdebug,MICRO_DEBUG)
	echo "Finalizing microtest..."
	$(OUT) $@ $^

testmain.o : testmain.cpp local.hpp all.hpp
	$(call testdebug,MICRO_DEBUG)
	echo "Compiling testmain.o..."
	$(COMP) $@ $<
	
squeaky ::
	$(call cleanup,testmain.o)

squeaky ::
	$(call cleanup,microtest)
