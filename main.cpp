///Gra Jak Statki Na Niebie
///projekt na laboratoria z PROI
///gra polega na interakcji z uzytkownikiem i wyborze akcji jakie klasa gracza ma wykonac, co zmienia je wartosci.
///wiecej informacji mozna uzyskac grajac w gre
#include <iostream>
#include <fstream>
// To please the RNGods
#include <ctime>
#include <cstdio>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

const static string ENEMY_TEXTURE = "assets/enemy1.png";
const static string BALL_TEXTURE = "assets/ball.png";
const static int PLAYER_FRAMES_COUNT = 8;
const static string PLAYER_TEXTURE[PLAYER_FRAMES_COUNT] = { "assets/ship2.png", "assets/ship3.png", "assets/ship4.png", "assets/ship5.png", "assets/ship6.png", "assets/ship7.png", "assets/ship8.png", "assets/ship1.png" };
const static string FONT = "assets/Treamd.ttf";
const float DEG_TO_RADS = 3.14159265 / 180;

template<typename T>
T clamp(T v, T lo, T hi)
{
    if(v < lo) return lo;
    if(v > hi) return hi;
    return v;
}

template<typename T>
T wrap(T v, T limit)
{
    T r = v;
    if(r < 0) r = limit + r;
    while(r > limit) r -= limit;
    return r;
}

template<typename T>
string to_string(T value)
{
    string buffer;
    sprintf((char*)buffer.c_str(), "%i", value);
    return buffer.c_str();
}

class Entity
{
protected:
    sf::Sprite sprite;
private:
    int hp;
    sf::Texture texture;
    sf::Vector2f velocity;
public:
    Entity(string texture_file, int hp, int pos_x, int pos_y, float vel_x, float vel_y, float rotation):
        hp(hp),
        velocity(vel_x, vel_y)
    {
        texture.loadFromFile(texture_file);
        sf::Vector2u dims = texture.getSize();
        sprite.setTexture(texture);
        sprite.setOrigin((float)dims.x / 2, (float)dims.y / 2);
        sprite.setPosition(pos_x, pos_y);
        sprite.setRotation(rotation);
    }
    sf::Vector2f getPosition() { return sprite.getPosition(); }
    float getRotation() { return sprite.getRotation(); }
    void setRotation(float rotation) { sprite.setRotation(rotation); }
    bool isDead() { return hp <= 0; }
    void damage() { hp--; }
    int getHP() { return hp; }
    void setHP(int hp_) { hp = hp_; }
    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }
    void update(sf::Vector2f movement, float delta)
    {
        float x = (velocity.x + movement.x) * delta;
        float y = (velocity.y + movement.y) * delta;
        sprite.move(x, y);
    }
};

class EnemyEntity : public Entity
{
    float cannon_timer = 0;
    float cannon_timer_limit = 1.5;
public:
    EnemyEntity(int pos_x, int pos_y, float vel_x, float vel_y, float rotation):
        Entity(ENEMY_TEXTURE, 5, pos_x, pos_y, vel_x, vel_y, rotation)
    {}
    void update(sf::Vector2f movement, float delta)
    {
        Entity::update(movement, delta);
        cannon_timer = clamp(cannon_timer + delta, 0.0f, cannon_timer_limit);
    }
    bool canShoot()
    {
        return cannon_timer >= cannon_timer_limit;
    }
    void restartCannon()
    {
        cannon_timer = 0;
    }
};

class BallEntity : public Entity
{
public:
    BallEntity(int pos_x, int pos_y, float vel_x, float vel_y):
        Entity(BALL_TEXTURE, 1, pos_x, pos_y, vel_x, vel_y, 0)
    {}
};

class PlayerShipEntity : public Entity
{
private:
    sf::Texture textures;
    int frame_counter = 0;
    float cannon_timer = 0;
    float cannon_timer_limit = 1.0;
    float texture_timer = 0;
    float texture_timer_limit = 0.06;
public:
    PlayerShipEntity(int pos_x, int pos_y):
        Entity(PLAYER_TEXTURE[0], 11, pos_x, pos_y, 0, 0, 0)
    {
        textures.loadFromFile(PLAYER_TEXTURE[7]);
    }
    void update(float rotation, float delta)
    {
        setRotation(rotation);
        texture_timer = clamp(texture_timer + delta, 0.0f, texture_timer_limit);
        if(canTextureBeChanged())
        {
            frame_counter = clamp(frame_counter + 1, 0, PLAYER_FRAMES_COUNT - 1);
            textures.loadFromFile(PLAYER_TEXTURE[frame_counter]);
            texture_timer = 0;
        }
        sprite.setTexture(textures);
        cannon_timer = clamp(cannon_timer + delta, 0.0f, cannon_timer_limit);
    }
    bool canTextureBeChanged()
    {
        return texture_timer >= texture_timer_limit;
    }
    bool canShoot()
    {
        return cannon_timer >= cannon_timer_limit;
    }
    void restartCannon()
    {
        cannon_timer = 0;
        frame_counter = 0;
    }
};

class World
{
    float spawnEnemy_timer = 0;
    float spawnEnemy_timer_limit = 2.0;
    float boost_timer = 0;
    float boost_timer_limit = 0.3;
    float boost_load_timer = 0;
    float boost_load_timer_limit = 3.0;

    const static int MAX_BALLS = 120;
    const static int MAX_ENEMIES = 5;
    const float MAX_SPEED = 500;
    const float BALL_SPEED = 300;
    const float ENEMY_SPEED = 60;
    const int WIDTH;
    const int HEIGHT;

    sf::Font font;
    BallEntity* balls[MAX_BALLS];
    EnemyEntity* enemies[MAX_ENEMIES];
    int numBalls;
    int numEnemies;
    PlayerShipEntity player;
    long long int points;
    float speed;

    sf::RenderWindow window;

    bool keys[sf::Keyboard::KeyCount];

    float rotation_rads() { return player.getRotation() * DEG_TO_RADS; }

    bool outsideView(sf::Vector2f entity_pos)
    {
        if(entity_pos.x < -100 || entity_pos.x > WIDTH + 100 ||
           entity_pos.y < -100 || entity_pos.y > HEIGHT + 100)
            return true;
        return false;
    }
    bool doCollide(sf::Vector2f v1, sf::Vector2f v2, float limit)
    {
        float x = v1.x - v2.x;
        float y = v1.y - v2.y;
        float dist = x * x + y * y;
        return dist < limit * limit;
    }
    void processEvent(sf::Event event)
    {
        if(event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape))
                window.close();
        if(event.type == sf::Event::KeyPressed)
            keys[event.key.code] = true;
        if(event.type == sf::Event::KeyReleased)
            keys[event.key.code] = false;
    }
    void checkCollision()
    {
        for(int i = numEnemies - 1; i >= 0; i--)
        {
            for(int j = numBalls - 1; j >= 0; j--)
            {
                if(doCollide(enemies[i]->getPosition(), balls[j]->getPosition(), 40))
                {
                    enemies[i]->damage();
                    balls[j]->damage();
                }
            }
            if(doCollide(enemies[i]->getPosition(), player.getPosition(), 100))
            {
                enemies[i]->damage();
                player.damage();
            }
        }
        for(int j = numBalls - 1; j >= 0; j--)
        {
            if(doCollide(player.getPosition(), balls[j]->getPosition(), 40))
            {
                player.damage();
                balls[j]->damage();
            }
        }
    }
    void clearEntities()
    {
        for(int i = numBalls - 1; i >= 0; i--)
            delete balls[i];
        numBalls = 0;
        for(int i = numEnemies - 1; i >= 0; i--)
            delete enemies[i];
        numEnemies = 0;
    }
    void spawnEnemy(int pos_x, int pos_y, float vel_x, float vel_y, float rotation)
    {
        if(numEnemies < MAX_ENEMIES) enemies[numEnemies++] = new EnemyEntity(pos_x, pos_y, vel_x, vel_y, rotation);
    }
    void spawnBall(int pos_x, int pos_y, float vel_x, float vel_y)
    {
        if(numBalls < MAX_BALLS) balls[numBalls++] = new BallEntity(pos_x, pos_y, vel_x, vel_y);
    }
    void fireCannons(float px, float py, float sin, float cos)
    {
        const int FRONT = -20, MIDDLE = 10, BACK = 40, DISTANCE = 55;
        // Left side
        spawnBall(px + cos *  FRONT + sin * -DISTANCE, py + sin *  FRONT + cos *  DISTANCE, -sin * BALL_SPEED,  cos * BALL_SPEED);
        spawnBall(px + cos * MIDDLE + sin * -DISTANCE, py + sin * MIDDLE + cos *  DISTANCE, -sin * BALL_SPEED,  cos * BALL_SPEED);
        spawnBall(px + cos *   BACK + sin * -DISTANCE, py + sin *   BACK + cos *  DISTANCE, -sin * BALL_SPEED,  cos * BALL_SPEED);
        // Right side
        spawnBall(px + cos *  FRONT + sin *  DISTANCE, py + sin *  FRONT + cos * -DISTANCE,  sin * BALL_SPEED, -cos * BALL_SPEED);
        spawnBall(px + cos * MIDDLE + sin *  DISTANCE, py + sin * MIDDLE + cos * -DISTANCE,  sin * BALL_SPEED, -cos * BALL_SPEED);
        spawnBall(px + cos *   BACK + sin *  DISTANCE, py + sin *   BACK + cos * -DISTANCE,  sin * BALL_SPEED, -cos * BALL_SPEED);
    }
    bool canCoup_de_Burst() { return boost_timer < boost_timer_limit; }
    bool canSpawnEnemy() { return spawnEnemy_timer >= spawnEnemy_timer_limit; }
    void restartSpawnerEnemy() { spawnEnemy_timer = 0; }
    void restartCoup_de_Burst() { boost_timer = 0; }
    void restartCoup_de_Burst_Load() { boost_load_timer = 0; }
public:
    World(const int width, const int height):
        WIDTH(width),
        HEIGHT(height),
        numBalls(0),
        numEnemies(0),
        player(width/2, height/2),
        points(0),
        speed(0),
        window(sf::VideoMode(width, height, 32), "Jak Statki Na Niebie")
    {
        font.loadFromFile(FONT);
        for(int i = 0; i < sf::Keyboard::KeyCount; i++) keys[i] = false;
    }
    bool isPlayerDead() { return player.isDead(); }
    long long int getPoints() { return points; }
    void saveToFile(string filename)
    {
        ofstream file;
        file.open(filename);

        file << player.getHP() << endl << points;

        file.close();
    }
    void loadFromFile(string filename)
    {
        ifstream file;
        file.open(filename);

        int hp_;
        long long int points_;
        file >> hp_ >> points_;
        player.setHP(hp_);
        points = points_;

        file.close();
    }
    void WindowClose() { window.close(); }
    bool isWindowOpen() { return window.isOpen(); }
    void update(float delta)
    {
        sf::Event event;
        while(window.pollEvent(event)) processEvent(event);

        if(keys[sf::Keyboard::F7]) saveToFile("test1.sav");
        if(keys[sf::Keyboard::F8]) loadFromFile("test1.sav");
        if(keys[sf::Keyboard::F9]) points = 1000;

        float px = player.getPosition().x;
        float py = player.getPosition().y;
        float sin_rot = sin(rotation_rads());
        float cos_rot = cos(rotation_rads());
        float rot_step = 60 * delta;
        float player_speed = 0;
        bool up = keys[sf::Keyboard::Up] || keys[sf::Keyboard::W];
        bool left = keys[sf::Keyboard::Left] || keys[sf::Keyboard::A];
        bool right = keys[sf::Keyboard::Right] || keys[sf::Keyboard::D];

        //if(player.canShoot()) cout << "PRESS SPACE TO WIN" << endl;
        if(keys[sf::Keyboard::Space] && player.canShoot())
        {
            fireCannons(px, py, sin_rot, cos_rot);
            player.restartCannon();
        }

        if(up && canCoup_de_Burst())
        {
            boost_timer = clamp(boost_timer + delta, 0.0f, boost_timer_limit);
            player_speed = 500;
        }
        else
        {
            boost_load_timer = clamp(boost_load_timer + delta, 0.0f, boost_load_timer_limit);
            if(boost_load_timer >= boost_load_timer_limit)
            {
                restartCoup_de_Burst();
                restartCoup_de_Burst_Load();
            }
            player_speed = 50;
        }

        if(left && !right) rot_step = -rot_step;
        else if(right && !left) rot_step = rot_step;
        else rot_step = 0;

        player_speed = clamp(player_speed, 0.0f, MAX_SPEED);
        sf::Vector2f move_step = sf::Vector2f(cos_rot * player_speed, sin_rot * player_speed);
        float rotation = wrap(player.getRotation() + rot_step, 360.0f);

        // Spawn these mother-duckers
        spawnEnemy_timer = clamp(spawnEnemy_timer + delta, 0.0f, spawnEnemy_timer_limit);
        if(canSpawnEnemy())
        {
            int dir = rand()%4;
            int x , y;
            int where = rand()%10;
            switch(dir)
            {
            case 1:
                x = WIDTH / 10 * where;
                y = -100;
                break;
            case 3:
                x = WIDTH + 100;
                y = HEIGHT / 10 * where;
                break;
            case 2:
                x = WIDTH / 10 * where;
                y = HEIGHT + 100;
                break;
            default:
            case 0:
                x = -100;
                y = HEIGHT / 10 * where;
                break;
            }
            float dist_x = WIDTH - 2 * x;
            float dist_y = HEIGHT - 2 * y;
            float dist = sqrt(dist_x * dist_x + dist_y * dist_y);
            float sin_e = dist_y / dist;
            float cos_e = dist_x / dist;
            float Enemy_rot = 1 / DEG_TO_RADS;
            if(dir == 0 || (where < 5 && (dir == 1 || dir == 2))) Enemy_rot = Enemy_rot * asin(sin_e) - 180;
            else Enemy_rot *= asin(-sin_e);
            spawnEnemy(x, y, cos_e * ENEMY_SPEED, sin_e * ENEMY_SPEED, Enemy_rot);
            restartSpawnerEnemy();
        }

        checkCollision();
        for(int i = numBalls - 1; i >= 0; i--)
        {
            balls[i]->update(move_step, delta);
            if(balls[i]->isDead() || outsideView(balls[i]->getPosition()))
            {
                *balls[i] = *balls[numBalls - 1];
                delete balls[numBalls - 1];
                numBalls--;
            }
        }
        for(int i = numEnemies - 1; i >= 0; i--)
        {
            enemies[i]->update(move_step, delta);
            if(enemies[i]->isDead())
            {
                points += 11;
            }
            float rot_e = enemies[i]->getRotation() * 3.14159265 / 180;
            float px_e = enemies[i]->getPosition().x;
            float py_e = enemies[i]->getPosition().y;
            float sin_rot_e = sin(rot_e);
            float cos_rot_e = cos(rot_e);
            if(enemies[i]->canShoot())
            {
                fireCannons(px_e, py_e, sin_rot_e, cos_rot_e);
                enemies[i]->restartCannon();
            }
            if(enemies[i]->isDead() || outsideView(enemies[i]->getPosition()))
            {
                *enemies[i] = *enemies[numEnemies - 1];
                delete enemies[numEnemies - 1];
                numEnemies--;
            }
        }
        player.update(rotation, delta);
    }
    void draw()
    {
        window.clear(sf::Color(0,128,183));
        for(int i = numBalls - 1; i >= 0; i--)
            balls[i]->draw(window);
        for(int i = numEnemies - 1; i >= 0; i--)
            enemies[i]->draw(window);
        player.draw(window);

        sf::Text health_text("HEALTH: " + to_string(player.getHP()), font);
        health_text.setFillColor(sf::Color(205,23,20));
        health_text.setStyle(sf::Text::Bold);
        health_text.setPosition(10, 0);
        window.draw(health_text);
        sf::Text points_text("POINTS: " + to_string(points), font);
        points_text.setFillColor(sf::Color::Yellow);
        points_text.setPosition(10, 40);
        window.draw(points_text);

        window.display();
    }
    ~World() { clearEntities(); }
};

int main()
{
    srand(time(NULL));
    const int width = 1200, height = 900;
    World zaWarudo(width, height);
    sf::Clock timer = sf::Clock();
    while (zaWarudo.isWindowOpen())
    {
        float delta = timer.restart().asSeconds();
        zaWarudo.update(delta);
        zaWarudo.draw();

        if(zaWarudo.isPlayerDead())
        {
            zaWarudo.WindowClose();
        }
    }
    cout << "NICKNAME: ";
    string c;
    cin >> c;
    cout << "Dead man tell no tales." << endl
         << c << " gained score: " << zaWarudo.getPoints() << endl
         << "Game over" << endl << endl
         << "Press any letter then enter to end, because c++ sucks..." << endl << endl;
    cin >> c;
    //ranking
    return 0;
}

//koniec
