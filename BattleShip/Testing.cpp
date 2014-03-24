//
//  Testing.cpp
//  BattleShip
//
//  Created by Erik Talvi on 3/21/14.
//  Copyright (c) 2014 Prodigy. All rights reserved.



#define CATCH_CONFIG_MAIN // This tells Catch to provide main() - only do this in one cpp file
#include "catch.hpp"
#include "ShipStrucs.h"

#include <algorithm>
#include <random>
#include <vector>
#include<string>
using std::string;



bool isValidBounds(int hole)
{
    return !(hole > 99 || hole < 0);
}


void isLegalShip(ships currentShip)
{
    int temp = currentShip.holes[0];

    for (int i = 1; i < currentShip.size; i++)
    {
        if(currentShip.direction == "horizontal" && currentShip.holes[i] == temp+1)
            currentShip.legalShip = true;
        
        else if(currentShip.direction == "vertical" && currentShip.holes[i] == temp+10)
            currentShip.legalShip = true;
        
        else
            currentShip.legalShip = false;
        
        temp = currentShip.holes[i];
        
        currentShip.legalShip = isValidBounds(temp);
    }
}

bool isValidCoordLetter(char coordLetter)
{
    return !(coordLetter < 'a' || coordLetter > 'j');
}

bool isValidCoordNumber(char coordNumber)
{
    return !(coordNumber < '0' || coordNumber > '9');
}

int coordinateToInt(string coord)
{
    if(coord.size() != 2)
        return 100;
    
    char coordLetter = tolower(coord[0]);
    
    if (!isValidCoordLetter(coordLetter))
        return 100;
    
    char coordNumber = coord[1];
    if (!isValidCoordNumber(coordNumber))
        return 100;
    
    return (coordLetter - 'a' + 1)*10 + coordNumber - 58;
}

string userInputCoordinate()
{
    string coord = "";
    
    std::cout << "Enter initial coordinate:";
    std::cin >> coord;
    
    while (!coordinateToInt(coord))
    {
        std::cout << "Invalid coordinate. Coords are letter then number; A-J and 0-9";
        std::cout << "Enter initial coordinate:";
        std::cin >> coord;
    }
    
    return coord;
}

string userInputDirection()
{
    string direction = "";
    
    std::cout << "Place ship (VERTICAL)ly or (HORIZONTAL)ly from this coordinate: ";
    std::cin >> direction;
    std::transform(direction.begin(),direction.end(),direction.begin(),::tolower);
    
    while (direction != "vertical" && direction != "horizontal")
    {
        std::cout << "Enter either VERTICAL or HORIZONTAL" << std::endl;
        std::cout << "Place ship (VERTICAL)ly or (HORIZONTAL)ly from this coordinate: ";
        std::cin >> direction;
        std::transform(direction.begin(),direction.end(),direction.begin(),::tolower);
    }

    return direction;
}

void createPlacementVector (ships currentShip)
{
    std::cout << "Create Placement Vector   :" << currentShip.legalShip <<std::endl;
    string tempCoord = currentShip.initialCoordinate;
    
    if(currentShip.direction == "horizontal")
        tempCoord[1] = tempCoord[1] - 1;
    if (currentShip.direction == "vertical")
        tempCoord[0] = tempCoord[0] - 1;
    
    for (int i = 0; i < currentShip.size; i++)
    {
        if(currentShip.direction == "horizontal")
            tempCoord[1] = tempCoord[1] + 1;
        if (currentShip.direction == "vertical")
            tempCoord[0] = tempCoord[0] + 1;
        currentShip.holes.push_back(coordinateToInt(tempCoord));
        std::cout << currentShip.holes[i] << std::endl;
    }
}

bool createShip(ships currentShip)
{
    std::cout << "Placing " << currentShip.type <<std::endl;
    currentShip.initialCoordinate = userInputCoordinate();
    currentShip.direction = userInputDirection();
    
    createPlacementVector(currentShip);
    
   if (!currentShip.legalShip)
        return 0;
    
    return true;
}

bool placeAllShips()
{
    std::cout << "It's time to place your ships! Please enter the initial hole in letter-number form i.e. C3 using letter A-J and numbers 0-9." << std::endl;
    std::cout << std::endl;
    std::cout << "Your ship will be extended horizontally to the right or vertically down from the initial coordinate/hole." << std::endl;
    std::cout << std::endl;
    
    ships aircraftCarrier;
    aircraftCarrier.size = 5;
    aircraftCarrier.type = "Aircraft Carrier";
    
    
    while (!createShip(aircraftCarrier))
    {
        std::cout << aircraftCarrier.holes[0] << " " <<aircraftCarrier.holes[1] << " " <<aircraftCarrier.holes[2] << " " <<aircraftCarrier.holes[3] << " " <<aircraftCarrier.holes[4] << std::endl << aircraftCarrier.legalShip <<std::endl;
        
        std::cout << "Bad placement, try again" << std::endl;
    }

    return 1;
}

TEST_CASE ( "BATTLESHIP TESTING", "[submarineExists]" )
{
    placeAllShips();
    
    
    
    
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 59);
    int goodRan = dis(gen);
    
    std::cout << goodRan << std::endl;
    
    std::uniform_int_distribution<> dis1(-100, -1);
    int lowRan = dis1(gen);
    
    std::uniform_int_distribution<> dis2(96, 200);
    int highRan = dis2(gen);
    
    vector<int> randHorGood {goodRan, goodRan+1, goodRan+2, goodRan+3, goodRan+4};
    vector<int> randVertGood {goodRan, goodRan+10, goodRan+20, goodRan+30, goodRan+40};
    
    vector<int> randHorBad {lowRan, lowRan+1, lowRan+2, lowRan+3, lowRan+4};
    vector<int> randVertBad {lowRan, lowRan+10, lowRan+20, lowRan+30, lowRan+40};
    
    vector<int> randHorBad2 {highRan, highRan+1, highRan+2, highRan+3, highRan+4};
    vector<int> randVertBad2 {highRan, highRan+10, highRan+20, highRan+30, highRan+40};
    
    
//    REQUIRE( isLegalShip(horizontalGood) );
//    REQUIRE( !isLegalShip(horzontalBad) );
//    REQUIRE( isLegalShip(verticalGood) );
//    REQUIRE( !isLegalShip(verticalBad) );
//    REQUIRE( !isLegalShip(outOfBounds) );
//    REQUIRE( !isLegalShip(outOfBounds2) );
//    REQUIRE( isLegalShip(randHorGood) );
//    REQUIRE( !isLegalShip(randHorBad) );
//    REQUIRE( isLegalShip(randVertGood) );
//    REQUIRE( !isLegalShip(randHorBad2) );
//    REQUIRE( !isLegalShip(randVertBad) );
//    REQUIRE( !isLegalShip(randVertBad2) );
    
    
    
    REQUIRE( coordinateToInt("C8") == 28 );
    REQUIRE( coordinateToInt("1") == 100);
    REQUIRE( coordinateToInt("g0") == 60 );
    REQUIRE( coordinateToInt("f4") == 54 );
    REQUIRE( coordinateToInt("F4") == 54 );
    REQUIRE( coordinateToInt("k11") == 100 );
    REQUIRE( coordinateToInt("f11") == 100 );
    REQUIRE( coordinateToInt("-4") == 100 );
    
    REQUIRE( coordinateToInt("-4") == 100 );
    

}





