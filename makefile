SUBFOLDERS	:= Etc Parsing DataStructs Execution
HEADERS		:= 
SOURCES		:= 
include make.i

all.gch : update
	$(COMP) $@ all.hpp
