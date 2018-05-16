SUBFOLDERS	:= 
HEADERS		:= List.hpp Tube.hpp
SOURCES		:= 
include make.i

#For testing and debugging purposes

$(ROOT)/up.o : force
	$(MAKE) -C $(ROOT) up.o

macrotest : testmain.o $(ROOT)/up.o
	$(call testdebug,MACRO_DEBUG)
	echo "Finalizing macrotest..."
	$(OUT) $@ $^

testmain.o : testmain.cpp local.hpp
	$(call testdebug,MACRO_DEBUG)
	echo "Compiling testmain.o..."
	$(COMP) $@ $<

#Miscellaneous

squeaky ::
	$(call cleanup,testmain.o)

squeaky ::
	$(call cleanup,macrotest)
