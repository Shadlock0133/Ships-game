class Entity
{
protected:
    sf::Sprite sprite;
private:
    int hp;
    sf::Texture texture;
    sf::Vector2f velocity;
public:
    Entity(sf::Texture &texture, int hp, int pos_x, int pos_y, float vel_x, float vel_y, float rotation):
        hp(hp),
        texture(texture),
        velocity(vel_x, vel_y)
    {
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