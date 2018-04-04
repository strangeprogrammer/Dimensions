SUBFOLDERS	:= 
HEADERS		:= Details.hpp ExecBlocks.hpp KVP.hpp Node.hpp
SOURCES		:= 
include make.i

testprog : testmain.o local.hpp
	@ #Silence make
	$(call testDebug)
	$(LINK) $@ $^

testmain.o : testmain.cpp
	@ #Silence make
	$(call testDebug)
	echo "Compiling testmain.cpp..."
	$(COMP) $@ $^
