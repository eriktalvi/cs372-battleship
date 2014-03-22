//
//  Testing.cpp
//  BattleShip
//
//  Created by Erik Talvi on 3/21/14.
//  Copyright (c) 2014 Prodigy. All rights reserved.
//


#define CATCH_CONFIG_MAIN // This tells Catch to provide main() - only do this in one cpp file
#include "catch.hpp"

bool submarineExists (int hole1,int hole2,int hole3)
{
    if (hole2 == hole1+1 && hole3 == hole2+1)
        return true;
    if (hole2 == hole1+10 && hole3 == hole2+10)
        return true;
        
    return false;
}

bool aircraftExists (int hole1,int hole2,int hole3, int hole4, int hole5)
{
    if (hole2 == hole1+1 && hole3 == hole2+1 && hole4 == hole3+1 && hole5 == hole4+1)
        return true;
    if (hole2 == hole1+10 && hole3 == hole2+10 && hole4 == hole3+10 && hole5 == hole4+10)
        return true;
    
    return false;
}

bool battleshipExists (int hole1,int hole2,int hole3, int hole4)
{
    if (hole2 == hole1+1 && hole3 == hole2+1 && hole4 == hole3+1)
        return true;
    if (hole2 == hole1+10 && hole3 == hole2+10 && hole4 == hole3+10)
        return true;
    
    return false;
}

bool destroyerExists (int hole1,int hole2,int hole3)
{
    return submarineExists(hole1, hole2, hole3);
}

bool patrolboatExists (int hole1,int hole2)
{
    if (hole2 == hole1+1)
        return true;
    if (hole2 == hole1+10)
        return true;
    
    return false;
}




TEST_CASE ( "BATTLESHIP TESTING", "[submarineExists]" )
{
    REQUIRE( submarineExists(1,2,3) == 1 );
    REQUIRE( submarineExists(1,2,4) == 0 );
    REQUIRE( submarineExists(1,3,4) == 0 );
    REQUIRE( submarineExists(1,11,21) == 1 );
    REQUIRE( aircraftExists(1,11,21,31,41) == 1 );
    REQUIRE( battleshipExists(1,11,21,31) == 1 );
    REQUIRE( destroyerExists(1,11,21) == 1 );
    REQUIRE( patrolboatExists(1,11) == 1 );
    REQUIRE( aircraftExists(1,2,3,4,5) == 1 );
    REQUIRE( battleshipExists(1,2,3,4) == 1 );
    REQUIRE( destroyerExists(1,2,3) == 1 );
    REQUIRE( patrolboatExists(1,2) == 1 );
    REQUIRE( aircraftExists(1,11,21,31,40) == 0 );
    REQUIRE( battleshipExists(1,11,21,30) == 0 );
    REQUIRE( destroyerExists(1,41,21) == 0 );
    REQUIRE( patrolboatExists(1,41) == 0 );
    REQUIRE( aircraftExists(1,2,3,4,8) == 0 );
    REQUIRE( battleshipExists(1,7,3,5) == 0 );
    REQUIRE( destroyerExists(1,2,5) == 0 );
    REQUIRE( patrolboatExists(1,3) == 0 );
    
}





