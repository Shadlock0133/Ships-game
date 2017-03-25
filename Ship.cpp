#include "Ship.h"

ostream& operator<<(std::ostream& out, const Ship& s)
{
    out << s.name;
    return out;
}
