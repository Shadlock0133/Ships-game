#include "Ship.h"

ostream& operator<<(std::ostream& out, const Ship& s)
{
    out << s.name;
    return out;
}

void Ship::AddCrewMember(CrewMember crewmember)
{
    crews.push_back(crewmember);
}

void Ship::setHPMax( int hpmax_ )
{
    int increase;
    increase = hpmax_ - hpmax;
    hpmax = hpmax_;
    hp += increase;
}

//koniec
