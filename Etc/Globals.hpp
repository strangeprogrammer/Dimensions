#ifndef GLOBALS_HPP
#define GLOBALS_HPP

//Useful macros
#define DIENULLTYPE(x,y) if((x)==NULL) return y
#define DIENULL(x) DIENULLTYPE(x,NULL)
#define DIENULLVOID(x) DIENULLTYPE(x,)

namespace Globals{
	extern const int dimensions;
	extern Parsing::ParseEnv env;
	extern std::string matchedtext;
}

#endif //GLOBALS_HPP
