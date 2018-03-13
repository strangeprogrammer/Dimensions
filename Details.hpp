#ifndef DETAILS
#define DETAILS

class Details;
template<int num> class axes;
template<> class axes<0>;
class number;
class jump;

typedef axes<26> axes;//NOTE: This line is counterproductive to infinite dimensions implementation, so remove later

#endif /*DETAILS*/
