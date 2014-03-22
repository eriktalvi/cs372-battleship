//
//  Testing.cpp
//  BattleShip
//
//  Created by Erik Talvi on 3/21/14.
//  Copyright (c) 2014 Prodigy. All rights reserved.
//


#define CATCH_CONFIG_MAIN // This tells Catch to provide main() - only do this in one cpp file
#include "catch.hpp"

bool subExists (int hole1,int hole2,int hole3)
{
    if (hole2 != hole1+1 || hole2 != hole3-1)
        return false;
    return true;
}

TEST_CASE ( "BATTLESHIP TESTING", "[subExists]" )
{
    REQUIRE( subExists(1,2,3) == 1 );
    REQUIRE( subExists(1,2,4) == 0 );
}

