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
    if (hole2 == hole1+1 && hole3 == hole2+1)
        return true;
    if (hole2 == hole1+10 && hole3 == hole2+10)
        return true;
        
    return false;
}

TEST_CASE ( "BATTLESHIP TESTING", "[subExists]" )
{
    REQUIRE( subExists(1,2,3) == 1 );
    REQUIRE( subExists(1,2,4) == 0 );
    REQUIRE( subExists(1,3,4) == 0 );
    REQUIRE( subExists(1,11,21) == 1 );
}

