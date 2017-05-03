//Gra Jak Statki Na Niebie
//projekt #1 na laboratoria z PROI
#include "Player.h"
#include "test.h"
#include <SFML/Graphics.hpp>
#include "Shoot.h"

int main()
{
    //psie z kulawą nogą, nieokrzesane bydlaki
    //Do armat slepe oszołomy! Arghhhh...
    //Do stu tysięcy kartaczy! Arghhhh...

    //Zobaczymy sie w luku Dawy'ego Jones'a! Arghhhh...
    srand(time(NULL));
    //testAll();
    Player player("");
    player.Start();
    player.menu();


    /*int width = 1200, height = 900;
    sf::RenderWindow window(sf::VideoMode(width, height, 32), "Jak Statki Na Niebie");
    sf::Texture ship_texture;
    ship_texture.loadFromFile("Grafika/ship1.png");
    sf::Sprite ship;
    ship.setTexture(ship_texture);
    int x = ship_texture.getSize().x;
    int y = ship_texture.getSize().y;
    ship.setPosition(width/2, height/2);
    float speed = 0.0, rotleft = 0.0, rotright = 0.0;
    ship.setOrigin(2*x/3, y/2);
    long long int aa=0;
    while (window.isOpen())
    {
        float dir = ship.getRotation()*6.28/360;
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H)
            {
                cout << "BAKA" << endl;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            ship.move(-cos(dir) * speed,sin(-dir) * speed);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if(speed<=0.02) speed += 0.000001;
                else speed -= 0.000001;
            }
            else
            {
                if(speed<=0.05) speed += 0.000001;
            }
        }
        else
        {
            if(speed>0)
            {
                ship.move(-cos(dir) * speed,sin(-dir) * speed);
                speed -= 0.000001;
            }
        }
        if(rotright==0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if(speed>0)
                {
                    ship.rotate(-rotleft*speed);
                    dir -= 0.4*speed;
                    if(rotleft<=0.4) rotleft += 0.00005;
                }
            }
            else
            {
                if(speed>0) ship.rotate(-rotleft*speed);
                if(rotleft>0) rotleft -= 0.0001;
                if(rotleft<0) rotleft = 0;
            }
        }
        if(rotleft==0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if(speed>0)
                {
                    ship.rotate(rotright*speed);
                    dir += 0.4*speed;
                    if(rotright<=0.4) rotright += 0.00005;
                }
            }
            else
            {
                if(speed>0) ship.rotate(rotright*speed);
                if(rotright>0) rotright -= 0.0001;
                if(rotright<0) rotright = 0;
            }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(speed>0)
            {
                speed -= 0.000001;
            }
        }



        window.clear(sf::Color(0,128,183));
        window.draw(ship);

        window.display();
    }
*/


    return 0;
}



//koniec
