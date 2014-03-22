//
//  Simple.h
//  BattleShip
//
//  Created by Prodigy on 3/21/14.
//  Copyright (c) 2014 Prodigy. All rights reserved.
//

#ifndef BattleShip_Simple_h
#define BattleShip_Simple_h
#define CATCH_CONFIG_MAIN // This tells Catch to provide main() - only do this in one cpp file
#include "catch.hpp"



TEST_CASE ( "BATTLESHIP TESTING", "[subExists]" )
{
    REQUIRE( subExists(1,2,3) == 1 );
}

#endif
