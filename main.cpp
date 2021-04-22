#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"

enum PlayerChoice {NORTH, SOUTH, EAST, WEST};

void clearTerminal()
{
    for(int i = 0; i < 50; i++)
    {
        std::cout << std::endl;
    }
}

bool getPlayerInput(PlayerChoice &playerChoice)
{
    // 0 = North, 1 = South, 2 = East, 3 = West
    std::string input;
    std::cout << "Which direction will you go?" << std::endl;
    std::cout << "Enter N, S, E, or W" << std::endl;
    std::cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if(input == "n")
    {
        playerChoice = NORTH;
    } else if(input == "s")
    {
        playerChoice = SOUTH;
    } else if(input == "e")
    {
        playerChoice = EAST;
    } else if(input == "w")
    {
        playerChoice = WEST;
    } else
    {
        std::cout << "Invalid input." << std::endl;
        return false;
    }
    return true;
}

int main()
{
    const unsigned int MAP_SIZE = 20;
    Player player(Player::DEFAULT_HEALTH, Player::DEFAULT_HUNGER, Player::DEFAULT_THIRST, MAP_SIZE/2, MAP_SIZE/2);
    
    // Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = getRandomLand();
        }
    }
    
    std::cout << "You wake up in a " <<
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << std::endl;
    
    while(player.isAlive())
    {
        //clearTerminal();
        player.newTurn();
        
        // Give description of surroundings
        unsigned int x = player.getX();
        unsigned int y = player.getY();
        
        std::cout << map[x][y]->getLongDescription() << std::endl << std::endl;
        std::cout << map[x][y]->visit(player) << std::endl << std::endl;
        
        std::cout << player.printStats() << std::endl << std::endl;
        
        // TODO: Handle boundry conditions
        //North works fine
        std::cout << "To the north you see a " << map[x][(y + 1) % 20]->getShortDescription() << std::endl;
        //South will bus error
        //std::cout << "To the south you see a " << map[x][(y - 1 + 20) % 20]->getShortDescription() << std::endl;
        if(map[x][y] == map[x][0])
        {
            std::cout << "To the south you see a " << map[x][20]->getShortDescription() << std::endl;
        } else {
            std::cout << "To the south you see a " << map[x][(y - 1 + 20) % 20]->getShortDescription() << std::endl;
        }
        //East will segmentation fault
        std::cout << "To the east you see a " << map[(x + 1 + 20) % 20][y]->getShortDescription() << std::endl;
        //West will bus error
        std::cout << "To the west you see a " << map[(x - 1 + 20) % 20][y]->getShortDescription() << std::endl;
        
        PlayerChoice playerChoice;
        
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice)
        {
            case NORTH:
                player.setY(player.getY() + 1);
                break;
            case SOUTH:
                player.setY(player.getY() - 1);
                break;
            case EAST:
                player.setX(player.getX() + 1);
                break;
            case WEST:
                player.setX(player.getX() - 1);
                break;
            default:
                std::cout << "Invalid input found: " << playerChoice << std::endl;
        }
        
    }
    
    return 0;
}