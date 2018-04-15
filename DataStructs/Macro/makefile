SUBFOLDERS	:= 
HEADERS		:= Tube.hpp List.hpp
SOURCES		:= 
include make.i

macrotest : testmain.o ../../Etc/Globals.cpp
	$(call testdebug,MACRO_DEBUG)
	echo "Finalizing macrotest..."
	$(OUT) $@ $^

testmain.o : testmain.cpp local.hpp all.hpp
	$(call testdebug,MACRO_DEBUG)
	echo "Compiling testmain.o..."
	$(COMP) $@ $<

squeaky ::
	$(call cleanup,testmain.o)

squeaky ::
	$(call cleanup,macrotest)
