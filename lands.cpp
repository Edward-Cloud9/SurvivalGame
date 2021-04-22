#include "lands.h"

Land* getRandomLand()
{
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection)
    {
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case TOWN:
            return new Town;
            break;
        case PLAIN:
            return new Plain;
            break;
        case VALLEY:
            return new Valley;
            break;
        case HILL:
            return new Hill;
            break;
        case FARM:
            return new Farm;
            break;
        default:
            return new Lake;
            break;
    }
}

std::string Lake::getShortDescription()
{
    return "lake";
}

std::string Lake::getLongDescription()
{
    return "You arrive at a large lake filled with clear sparkling water.";
}

std::string Lake::visit(Player& p)
{
    std::string description = "You drink from the lake, replenishing your thirst.";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}
//---------------------------------------------------------------------------------------
std::string Forest::getShortDescription()
{
    return "forest";
}

std::string Forest::getLongDescription()
{
    return "You arrive in a dense forest filled with trees and foliage.";
}

std::string Forest::visit(Player& p)
{
    std::string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries.
    if(chance > 50)
    {
        description = "You forage for berries and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear.
    if(chance < 10 && chance > 5)
    {
        description = "You are attacked by a hungry bear in the woods! What luck!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double double mauled.
    if(chance < 5)
    {
        description = "You are attacked by two very large bears! What are the chances of that!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    return description;
}
//--------------------------------------------------------------------------------------------
std::string Desert::getShortDescription()
{
    return "desert";
}

std::string Desert::getLongDescription()
{
    return "You arrive in an extremely hot, dry desert.";
}

std::string Desert::visit(Player& p)
{
    std::string description = "The heat of the desert makes you dehydrated.";
    if(p.getThirst() > 0)
    {
        p.setThirst(p.getThirst() - 1);
    }
    
    return description;
}
//--------------------------------------------------------------------------------------------
std::string Town::getShortDescription()
{
    return "town";
}

std::string Town::getLongDescription()
{
    return "You arrive in a town with a fair amount of people and buildings.";
}

std::string Town::visit(Player& p)
{
    std::string description = "You roam around in search for some useful things.";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance > 30)
    {
        description = "Passing through you find a town doctor, restoring your health.";
        p.setHealth(Player::DEFAULT_HEALTH);
        return description;
    }
    
    if(chance < 45 && chance > 30)
    {
        description = "You find an inn to rest up. Thirst and hunger replenished.";
        p.setHunger(p.getHunger() + 2);
        p.setThirst(p.getThirst() + 2);
        return description;
    }
    
    return description;
}
//-------------------------------------------------------------------------------------------
std::string Plain::getShortDescription()
{
    return "plain";
}

std::string Plain::getLongDescription()
{
    return "You walk along a plain route. The view is splendid.";
}

std::string Plain::visit(Player& p)
{
    std::string description = "You route was a breeze with no exciting action ...";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance < 5)
    {
        description = "You meet a stranger along the way. Friendly, he gives you a potion to heal you up.";
        p.setHealth(p.getHealth() + 1);
        return description;
    }
    
    if(chance > 5 && chance < 15)
    {
        description = "You meet a stranger along the way. Sadly a group surrounds you and smack you. You lose some health. Tuff luck ...";
        p.setHealth(p.getHealth() - 2);
        return description;
    }
    
    if(chance > 15 && chance < 20)
    {
        description = "You meet a stranger along the way. Hostile, he muggles you. Not you day ...";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
    
    return description;
}
//---------------------------------------------------------------------------------------------------------
std::string Valley::getShortDescription()
{
    return "valley";
}

std::string Valley::getLongDescription()
{
    return "You arrive in a valley. Huge terrian surrounds the sides along the path.";
}

std::string Valley::visit(Player& p)
{
    std::string description = "Your trip through the valley was calm.";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance > 50)
    {
        description = "You pass through the route when an apple bonks you on your head. You lose health ... but the apple restores it ...";
        return description;
    }
    
    return description;
}
//----------------------------------------------------------------------------------------------------------------
std::string Hill::getShortDescription()
{
    return "hill";
}

std::string Hill::getLongDescription()
{
    return "You arrive on a hill. You have to descend it ... don't trip.";
}

std::string Hill::visit(Player& p)
{
    std::string description = "You carefully walk down the hill ...";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance > 50)
    {
        description = "You trip on a rock making you tumble down the hill. At least you made down the hill ...";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
    
    return description;
}
//----------------------------------------------------------------------------------------------------------------
std::string Farm::getShortDescription()
{
    return "farm";
}

std::string Farm::getLongDescription()
{
    return "You arrive near a farm. The land is full of plants and animals. Plentiful to replenish.";
}

std::string Farm::visit(Player& p)
{
    std::string description = "You meet the farmer and ask for supplies.";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance > 50)
    {
        description = "The farmer did not like you. Big bonk in the head ... tuff luck!";
        p.setHealth(p.getHealth() - 2);
        return description;
    }
    
    if(chance < 50)
    {
        description = "The farmer is nice enough to give you some supplies.";
        p.setHunger(p.getHunger() + 1);
        p.setThirst(p.getThirst() + 1);
        return description;
    }
    
    return description;
}
