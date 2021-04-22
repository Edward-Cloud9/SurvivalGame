#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>

class Player
{
    public:
    Player(unsigned int health, unsigned int hunger, unsigned int thirst,
            unsigned int x, unsigned int y);
    
    unsigned int getX() const;
    unsigned int getY() const;
    
    void setX(unsigned int newX);
    void setY(unsigned int newY);
    
    unsigned int getHealth() const;
    unsigned int getHunger() const;
    unsigned int getThirst() const;
    
    void setHealth(unsigned int hp);
    void setHunger(unsigned int h);
    void setThirst(unsigned int t);
    
    void newTurn();
    
    std::string printStats();
    
    bool isAlive() const;
    
    static const unsigned int DEFAULT_HEALTH = 5;
    static const unsigned int DEFAULT_HUNGER = 15;
    static const unsigned int DEFAULT_THIRST = 15;
    
    private:
    unsigned int health;
    unsigned int hunger;
    unsigned int thirst;
    unsigned int x;
    unsigned int y;
    
};

#endif