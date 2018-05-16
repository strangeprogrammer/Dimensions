SUBFOLDERS	:= 
HEADERS		:= Cell.hpp Details.hpp ExecBlocks.hpp KVP.hpp Node.hpp
SOURCES		:= Cell.cpp Details.cpp ExecBlocks.cpp

Cell.cpp : Cell.hpp Details.hpp
	$(call touche)

Details.cpp : Details.hpp ExecBlocks.proto ../../Etc/InstantiationType.hpp ../Macro/List.hpp
	$(call touche)

ExecBlocks.cpp : Details.hpp ExecBlocks.hpp ExecBlocks.proto Node.hpp ../../Etc/InstantiationType.hpp ../../Etc/InstructionType.hpp
	$(call touche)

include make.i

#For testing and debugging purposes

$(ROOT)/up.o : force
	$(MAKE) -C $(ROOT) up.o

microtest : testmain.o $(ROOT)/up.o
	$(call testdebug,MICRO_DEBUG)
	echo "Finalizing microtest..."
	$(OUT) $@ $^

testmain.o : testmain.cpp
	$(call testdebug,MICRO_DEBUG)
	echo "Compiling testmain.o..."
	$(COMP) $@ $<

#Miscellaneous

squeaky ::
	$(call cleanup,testmain.o)

squeaky ::
	$(call cleanup,microtest)
