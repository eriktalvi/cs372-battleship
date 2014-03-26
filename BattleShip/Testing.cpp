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

string userInputCoordinate() {
    string coord = "";
    
    std::cout << "Enter initial coordinate:";
    std::cin >> coord;
    
    while (!coordinateToInt(coord)) {
        std::cout << "Invalid coordinate. Coords are letter then number; A-J and 0-9";
        std::cout << "Enter initial coordinate:";
        std::cin >> coord;
    }
    
    return coord;
}

string userInputDirection() {
    string direction = "";
    
    std::cout << "Place ship (VERTICAL)ly or (HORIZONTAL)ly from this coordinate: ";
    std::cin >> direction;
    std::transform(direction.begin(),direction.end(),direction.begin(),::tolower);
    
    while (direction != "vertical" && direction != "horizontal") {
        std::cout << "Enter either VERTICAL or HORIZONTAL" << std::endl;
        std::cout << "Place ship (VERTICAL)ly or (HORIZONTAL)ly from this coordinate: ";
        std::cin >> direction;
        std::transform(direction.begin(),direction.end(),direction.begin(),::tolower);
    }

    return direction;
}

bool createShip(ships currentShip) {
    std::cout << "Placing " << currentShip.type <<std::endl;
    //currentShip.initialCoordinate = userInputCoordinate();
    //currentShip.direction = userInputDirection();
    currentShip.createPlacementVector();
    return currentShip.legalShip;
}

bool placeAllShips() {
    std::cout << "It's time to place your ships! Please enter the initial hole in letter-number form i.e." << "C3 using letter A-J and numbers 0-9." << std::endl;
    std::cout << std::endl;
    std::cout << "Your ship will be extended horizontally to the right or vertically down from the initial coordinate/hole." << std::endl;
    
    ships aircraftCarrier;
    aircraftCarrier.size = 5;
    aircraftCarrier.type = "Aircraft Carrier";
    
    while (!createShip(aircraftCarrier)) {
        std::cout << "Bad placement, try again" << std::endl;
    }

    return 1;
}

TEST_CASE ( "BATTLESHIP TESTING", "[submarineExists]" ) {
    std::cout << "good ship";
    ships testShipGoodHor;
    testShipGoodHor.createPlacementVector();
    
    std::cout << "bad ship";
    ships testShipBadHor;
    testShipBadHor.type = "Bad hor";
    testShipBadHor.initialCoordinate = "a7";
    testShipBadHor.createPlacementVector();
    
    std::cout << "good ship";
    ships testShipGoodVert;
    testShipGoodVert.direction = "vertical";
    testShipGoodVert.createPlacementVector();

    std::cout << "bad ship";
    ships testShipBadVert;
    testShipBadVert.type = "Bad hor";
    testShipBadVert.initialCoordinate = "g7";
    testShipBadVert.direction = "vertical";
    testShipBadVert.createPlacementVector();
  
    REQUIRE( testShipGoodHor.isLegalShip() );
    REQUIRE( !testShipBadHor.isLegalShip() );
    REQUIRE( testShipGoodVert.isLegalShip() );
    REQUIRE( !testShipBadVert.isLegalShip() );
    REQUIRE( createShip(testShipGoodHor) );
    REQUIRE( !createShip(testShipBadHor) );
    REQUIRE( createShip(testShipGoodVert) );
    REQUIRE( !createShip(testShipBadVert) );

    
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
    
    testShipBadVert.holes = randVertBad;
    testShipBadHor.holes = randHorBad;
    testShipGoodVert.holes = randVertGood;
    testShipGoodHor.holes = randHorGood;
    
    REQUIRE( createShip(testShipGoodHor) );
    REQUIRE( !createShip(testShipBadHor) );
    REQUIRE( createShip(testShipGoodVert) );
    REQUIRE( !createShip(testShipBadVert) );
    
    vector<int> randHorBad2 {highRan, highRan+1, highRan+2, highRan+3, highRan+4};
    vector<int> randVertBad2 {highRan, highRan+10, highRan+20, highRan+30, highRan+40};
    
    testShipBadVert.holes = randVertBad2;
    testShipBadHor.holes = randHorBad2;
    
    REQUIRE( !createShip(testShipBadHor) );
    REQUIRE( !createShip(testShipBadVert) );
    
    REQUIRE( coordinateToInt("C8") == 28 );
    REQUIRE( coordinateToInt("1") == 100);
    REQUIRE( coordinateToInt("g0") == 60 );
    REQUIRE( coordinateToInt("f4") == 54 );
    REQUIRE( coordinateToInt("F4") == 54 );
    REQUIRE( coordinateToInt("k11") == 100 );
    REQUIRE( coordinateToInt("f11") == 100 );
    REQUIRE( coordinateToInt("-4") == 100 );
    
}





