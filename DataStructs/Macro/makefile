SUBFOLDERS	:= 
HEADERS		:= Tube.hpp List.hpp
SOURCES		:= 
include make.i

testprog : testmain.o
	$(call testDebug)
	echo "Linking testprog..."
	$(LINK) $@ $^ ../../Etc/Globals.cpp

testmain.o : testmain.cpp local.hpp all.hpp
	$(call testDebug)
	echo "Compiling testmain.cpp..."
	$(COMP) $@ $<
