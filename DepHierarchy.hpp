//Uses recursion to include header files of different dependency levels (unbelievably useful for dependency resolution)

#ifndef BOUNDARY
	#define BOUNDARY 16
#endif //BOUNDARY

#ifndef LEVEL
	#define LEVEL 0
#elif LEVEL == 0
	#undef LEVEL
	#define LEVEL 1
#elif LEVEL == 1
	#undef LEVEL
	#define LEVEL 2
#elif LEVEL == 2
	#undef LEVEL
	#define LEVEL 3
#elif LEVEL == 3
	#undef LEVEL
	#define LEVEL 4
#elif LEVEL == 4
	#undef LEVEL
	#define LEVEL 5
#elif LEVEL == 5
	#undef LEVEL
	#define LEVEL 6
#elif LEVEL == 6
	#undef LEVEL
	#define LEVEL 7
#elif LEVEL == 7
	#undef LEVEL
	#define LEVEL 8
#elif LEVEL == 8
	#undef LEVEL
	#define LEVEL 9
#elif LEVEL == 9
	#undef LEVEL
	#define LEVEL 10
#elif LEVEL == 10
	#undef LEVEL
	#define LEVEL 11
#elif LEVEL == 11
	#undef LEVEL
	#define LEVEL 12
#elif LEVEL == 12
	#undef LEVEL
	#define LEVEL 13
#elif LEVEL == 13
	#undef LEVEL
	#define LEVEL 14
#elif LEVEL == 14
	#undef LEVEL
	#define LEVEL 15
#elif LEVEL == 15
	#undef LEVEL
	#define LEVEL BOUNDARY
#endif //LEVEL

#if LEVEL < BOUNDARY
	#include "up.hpp"
	#include "DepHierarchy.hpp" //Recursion occurs 'BOUNDARY' times
#endif //LEVEL

#ifdef LEVEL
	#undef LEVEL
#endif //LEVEL

#ifdef BOUNDARY
	#undef BOUNDARY
#endif //BOUNDARY
