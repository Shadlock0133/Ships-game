#include "Player.h"

void Player::AddShip(Ship ship)
{
    ships.push_back(ship);
}

ostream& operator<<(std::ostream& out, const Player& p)
{
    out << p.name;
    return out;
}

void Player::Scancrew()//wglad w ilosc okretow, zaloge na nich i ich statystyki
{
    //cout<<name<<endl;
    cout<<"Tyle masz kasy: "<<money<<endl;
    cout<<"Tyle masz rumu: "<<rum<<endl;
    cout<<"Lista statkow: "<<ships.size()<<endl;
    int sum=0;
    for(int i=0;i<ships.size();i++)
    {
        cout<<i+1<<". "<<ships[i]<<endl;
        sum+=ships[i].GetCrews().size();
    }
    cout<<"Liczba zalogi ogolem: "<<sum;

}
