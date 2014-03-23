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


bool shipExists(std::vector<int> holes)
{
    int temp = holes[0];
    bool verticalBool = true;
    bool horizontalBool = true;
    
    for (int i = 1; i < holes.size(); i++)
    {
        if(holes[i] != temp+1 && horizontalBool)
            horizontalBool = false;
        
        if(holes[i] != temp+10 && verticalBool)
            verticalBool = false;
        
        temp = holes[i];
    }
    
    return (verticalBool || horizontalBool);
}




TEST_CASE ( "BATTLESHIP TESTING", "[submarineExists]" )
{
    vector<int> horizontalGood {1,2,3,4,5};
    vector<int> horzontalBad {1,3,5,7,8};
    vector<int> verticalGood {1,11,21,31,41};
    vector<int> verticalBad {1,3,7,6,5};
    

    REQUIRE( shipExists(horizontalGood) );
    REQUIRE( !shipExists(horzontalBad) );
    REQUIRE( shipExists(verticalGood) );
    REQUIRE( !shipExists(verticalBad) );
    
   
    
}





