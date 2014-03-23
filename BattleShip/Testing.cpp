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

bool isOutOfBounds(int hole)
{
    return (hole > 100 || hole < 1);
    
}


bool isLegalShip(std::vector<int> holes)
{
    int temp = holes[0];
    bool isVerticalShip = isOutOfBounds(temp);
    bool isHorizontalShip = isOutOfBounds(temp);
    
    
    for (int i = 1; i < holes.size(); i++)
    {
        if(holes[i] != temp+1 && isHorizontalShip)
            isHorizontalShip = false;
        
        if(holes[i] != temp+10 && isVerticalShip)
            isVerticalShip = false;
        
        temp = holes[i];
        
        isVerticalShip = isOutOfBounds(temp);
        isHorizontalShip = isOutOfBounds(temp);
        
    }
    
    return (isVerticalShip || isHorizontalShip);
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
    
    
   
    
}





