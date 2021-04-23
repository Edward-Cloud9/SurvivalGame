#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"

enum PlayerChoice {NORTH, SOUTH, EAST, WEST, QUIT};

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
    std::cout << "Enter N, S, E, W, or Q" << std::endl;
    std::cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);    // The four valid inputs is automatically lower case.
    
    if(input == "n")                                                    // Returns the input to move in that direction.
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
    } else if(input == "q")
    {
        playerChoice = QUIT;
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
    
    // Build the map size: 20 x 20
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = getRandomLand();
        }
    }
    
    std::cout << "You wake up in a " <<                                 // Introduction message.
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << std::endl;
    
    while(player.isAlive())
    {
        
        player.newTurn();
        
        // Give description of surroundings
        unsigned int x = player.getX();
        unsigned int y = player.getY();
        
        std::cout << map[x][y]->getLongDescription() << std::endl << std::endl; // Gets long description of the current location.
        std::cout << map[x][y]->visit(player) << std::endl << std::endl;        // Applies the random effects.
        
        std::cout << player.printStats() << std::endl << std::endl;             // Prints out the player's stats.
        
        // TODO: Handle boundry conditions
        //North works fine
        std::cout << "To the north you see a " << map[x][(y + 1 + 20) % 20]->getShortDescription() << std::endl; // Using Module % to wrap around the map.
        //South will bus error [FIXED]
        std::cout << "To the south you see a " << map[x][(y - 1 + 20) % 20]->getShortDescription() << std::endl;
        //East will segmentation fault [FIXED]
        std::cout << "To the east you see a " << map[(x + 1 + 20) % 20][y]->getShortDescription() << std::endl;
        //West will bus error [FIXED]
        std::cout << "To the west you see a " << map[(x - 1 + 20) % 20][y]->getShortDescription() << std::endl;
        
        PlayerChoice playerChoice;
        
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice)
        {
            case NORTH:
                player.setY((player.getY() + 1 + 20) % 20); // Using module % fixed the bus error.
                break;
            case SOUTH:
                player.setY((player.getY() - 1 + 20) % 20); // Each one moves the character in the direction it specifies.
                break;
            case EAST:
                player.setX((player.getX() + 1 + 20) % 20);
                break;
            case WEST:
                player.setX((player.getX() - 1 + 20) % 20);
                break;
            case QUIT:
                player.setHealth(0);
                break;
            default:
                std::cout << "Invalid input found: " << playerChoice << std::endl;
        }
        
        clearTerminal();    // "clear" the terminal.
    }
    
    std::cout << "You died! You did your best in surviving. Better luck next time!" << std::endl;
    
    return 0;
}