#ifndef MACROS_HPP
#define MACROS_HPP

#define DIENULLTYPE(x,y) if((x)==NULL) return y
#define DIENULL(x) DIENULLTYPE(x,NULL)
#define DIENULLVOID(x) DIENULLTYPE(x,)

#endif //MACROS_HPP
