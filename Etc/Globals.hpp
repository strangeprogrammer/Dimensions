//Useful macros
#define DIENULLTYPE(x,y) if((x)==NULL) return y
#define DIENULL(x) DIENULLTYPE(x,NULL)
#define DIENULLVOID(x) DIENULLTYPE(x,)

namespace Globals{
	extern const int dimensions;
}
