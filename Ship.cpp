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

void Ship::HireCrewMember()//zatrudnianie piratow do konkretnego okretu z losowymi statystykami
{

}

//koniec
