include make.i

SUBFOLDERS	:= Etc/ Parsing/ DataStructs/ Execution/
#HEADERS	:= 
#SOURCES	:= 

#Targets that shouldn't be treated as real files
.PHONY : scanner_src scanner scannertest parser_src parser parsertest Parsing/bisoncpp/listvars Parsing/flexcpp/listvars touchall

#For regular compiling as well as testing and debugging
scanner_src scanner scannertest parser_src parser parsertest Parsing/bisoncpp/listvars Parsing/flexcpp/listvars :
	@ #Silence make
	$(MAKE) ./Parsing/ $@
