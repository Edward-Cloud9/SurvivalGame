#include "player.h"

Player::Player(unsigned int health, unsigned int hunger, unsigned int thirst,
            unsigned int x, unsigned int y)
    {
        this->health = health;
        this->hunger = hunger;
        this->thirst = thirst;
        this->x = x;
        this->y = y;
    }
    
    unsigned int Player::getX() const { return x; }
    
    unsigned int Player::getY() const { return y; }
    
    void Player::setX(unsigned int newX) { x = newX; }
    
    void Player::setY(unsigned int newY) { y = newY; }
    
    unsigned int Player::getHealth() const { return health; }
    
    unsigned int Player::getHunger() const { return hunger; }
    
    unsigned int Player::getThirst() const { return thirst; }
    
    void Player::setHealth(unsigned int hp) { health = hp; }
    
    void Player::setHunger(unsigned int h) { hunger = h; }
    
    void Player::setThirst(unsigned int t) { thirst = t; }
    
    void Player::newTurn()
    {
        
        if(hunger <= 0)
        {
            hunger == 0;
        }
        else
        {
            hunger--;
        }
        
        if(thirst <= 0)
        {
            thirst == 0;
        }
        else
        {
            thirst--;
        }
        if(hunger == 0 || thirst == 0)
        {
            health--;
        }
        
    }
    
    std::string Player::printStats()
    {
        std::ostringstream ss;
        ss << "Health: " << health << " ";
        ss << "Hunger: " << hunger << " ";
        ss << "Thirst: " << thirst;
        return ss.str();
    }
    
    
    bool Player::isAlive() const { return health > 0; }