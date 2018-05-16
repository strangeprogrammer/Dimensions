//Uses recursion to include header files of different dependency levels (unbelievably useful for dependency resolution)

#ifndef RUNENV_HPP
	#include "up.hpp"
	#ifdef INCLUDE_DEBUG
		#ifdef INSTRUCTIONTYPE_HPP
			#warning INSTRUCTIONTYPE_HPP
		#endif
		#ifdef INSTANTIATIONTYPE_HPP
			#warning INSTANTIATIONTYPE_HPP
		#endif
		#ifdef GLOBALS_HPP
			#warning GLOBALS_HPP
		#endif
		#ifdef LIBRARIES_HPP
			#warning LIBRARIES_HPP
		#endif
		#ifdef MACROS_HPP
			#warning MACROS_HPP
		#endif
		#ifdef EXECTOOLS_HPP
			#warning EXECTOOLS_HPP
		#endif
		#ifdef RUNENV_HPP
			#warning RUNENV_HPP
		#endif
		#ifdef STORAGE_HPP
			#warning STORAGE_HPP
		#endif
		#ifdef LIST_HPP
			#warning LIST_HPP
		#endif
		#ifdef TUBE_HPP
			#warning TUBE_HPP
		#endif
		#ifdef CELL_HPP
			#warning CELL_HPP
		#endif
		#ifdef DETAILS_HPP
			#warning DETAILS_HPP
		#endif
		#ifdef EXECBLOCKS_PROTO
			#warning EXECBLOCKS_PROTO
		#endif
		#ifdef NODE_HPP
			#warning NODE_HPP
		#endif
		#ifdef KVP_HPP
			#warning KVP_HPP
		#endif
		#ifdef EXECBLOCKS_HPP
			#warning EXECBLOCKS_HPP
		#endif
		#ifdef PARSEENV_HPP
			#warning PARSEENV_HPP
		#endif
		#ifdef ParserBase_h_included
			#warning ParserBase_h_included
		#endif
		#ifdef ScannerBASE_H_INCLUDED
			#warning ScannerBASE_H_INCLUDED
		#endif
		#ifdef Scanner_H_INCLUDED_
			#warning Scanner_H_INCLUDED_
		#endif
		#ifdef Parser_h_included
			#warning Parser_h_included
		#endif
	#endif //INCLUDE_DEBUG
	#include "all.root.hpp" //Recursion occurs until the last header file is included
#endif //Parser_h_included
