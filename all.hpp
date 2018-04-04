//Uses recursion to include header files of different dependency levels (unbelievably useful for dependency resolution)

#ifndef BOUNDARY
	#define BOUNDARY 8
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
	#define LEVEL BOUNDARY
#endif //LEVEL

#if LEVEL < BOUNDARY
	#include "up.hpp"
	#include "all.hpp" //Recursion occurs 'BOUNDARY' times
#endif //LEVEL
