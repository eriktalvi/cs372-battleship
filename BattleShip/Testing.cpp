//
//  Testing.cpp
//  BattleShip
//
//  Created by Erik Talvi on 3/21/14.
//  Copyright (c) 2014 Prodigy. All rights reserved.
//


#define CATCH_CONFIG_MAIN // This tells Catch to provide main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include "ShipStrucs.h"
#include<string>
using std::string;


bool isValidBounds(int hole)
{
    return !(hole > 99 || hole < 0);
}


bool isLegalShip(std::vector<int> holes)
{
    int temp = holes[0];
    bool isVerticalShip = isValidBounds(temp);
    bool isHorizontalShip = isValidBounds(temp);
    
    
    for (int i = 1; i < holes.size(); i++)
    {
        if(isHorizontalShip && holes[i] != temp+1)
            isHorizontalShip = false;
        
        if(isVerticalShip && holes[i] != temp+10)
            isVerticalShip = false;
        
        temp = holes[i];
        
        if (isVerticalShip) {
            isVerticalShip = isValidBounds(temp);
        }
        if (isHorizontalShip) {
            isHorizontalShip = isValidBounds(temp);
        }
        
        
    }
    
    return (isVerticalShip || isHorizontalShip);
}

int coordinateToInt(string coord)
{
    char coordLetter = tolower(coord[0]);
    if(coordLetter < 'a' || coordLetter > 'j')
    {
        return 0;
    }
    
    char coordNumber = coord[1];
    if(coordNumber < '0' || coordNumber > '9')
    {
        return 0;
    }
    
    return (coordLetter - 'a' + 1)*10 + coordNumber - 58;
}


TEST_CASE ( "BATTLESHIP TESTING", "[submarineExists]" )
{
    vector<int> horizontalGood {1,2,3,4,5};
    vector<int> horzontalBad {1,3,5,7,8};
    vector<int> verticalGood {1,11,21,31,41};
    vector<int> verticalBad {1,3,7,6,5};
    vector<int> outOfBounds {-2,-1,0,1,2};
    vector<int> outOfBounds2 {81,91,101};

    REQUIRE( isLegalShip(horizontalGood) );
    REQUIRE( !isLegalShip(horzontalBad) );
    REQUIRE( isLegalShip(verticalGood) );
    REQUIRE( !isLegalShip(verticalBad) );
    REQUIRE( !isLegalShip(outOfBounds) );
    REQUIRE( !isLegalShip(outOfBounds2) );
    REQUIRE( coordinateToInt("C8") == 28 );
    REQUIRE( !coordinateToInt("1") );
    REQUIRE( coordinateToInt("g0") == 60 );
    REQUIRE( coordinateToInt("f4") == 54 );
    REQUIRE( coordinateToInt("F4") == 54 );
    REQUIRE( !coordinateToInt("k11") );
    REQUIRE( coordinateToInt("f11") == 51 ); // If more than one number for coordinate x it takes first digit
    REQUIRE( !coordinateToInt("-4") );

    
    
    
   
    
}





