#ifndef LANDS_H
#define LANDS_H

#include <string>
#include <stdlib.h>
#include "player.h"

enum LandTypes {LAKE, FOREST, DESERT, TOWN, PLAIN, VALLEY, HILL, FARM, MAX_NUM_LANDS};

class Land
{
    public:
    virtual std::string getShortDescription() = 0;
    virtual std::string getLongDescription() = 0;
    virtual std::string visit(Player &p) = 0;
    
    private:
    
};

class Lake : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

class Forest : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

class Desert : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

class Town : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

class Plain : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

class Valley : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

class Hill : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

class Farm : public Land
{
    public:
    std::string getShortDescription();
    std::string getLongDescription();
    std::string visit(Player &p);
    
    private:
    
};

Land* getRandomLand(void);

#endif