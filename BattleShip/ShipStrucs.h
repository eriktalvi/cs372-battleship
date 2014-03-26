//
//  ShipStrucs.h
//  BattleShip
//
//  Created by Prodigy on 3/21/14.
//  Copyright (c) 2014 Prodigy. All rights reserved.
//

#ifndef BattleShip_ShipStrucs_h
#define BattleShip_ShipStrucs_h
using std::vector;
#include<string>
using std::string;

struct ships {
    
    ships () :
        legalShip(1), type("default"), initialCoordinate("a0"), direction("horizontal"), size(5) { }

    bool legalShip;
    string type;
    string initialCoordinate;
    string direction;
    int size;
    vector<int> holes;
    
    void createPlacementVector();
    bool isLegalShip();
};

bool isValidBounds(int hole) {
    return !(hole > 99 || hole < 0);
}


bool ships::isLegalShip() {
    int temp = holes[0];
    
    for (int i = 1; i < size; i++) {
        if (!legalShip)
            return legalShip;
        
        else if(holes[i] == 100)
            legalShip = false;
        else if(direction == "horizontal" && holes[i] != temp+1)
            legalShip = false;
        else if(direction == "vertical" && holes[i] != temp+10)
            legalShip = false;
        
        temp = holes[i];
        legalShip = isValidBounds(temp);
    }
    return legalShip;
}

bool isValidCoordLetter(char coordLetter) {
    return !(coordLetter < 'a' || coordLetter > 'j');
}

bool isValidCoordNumber(char coordNumber) {
    return !(coordNumber < '0' || coordNumber > '9');
}

char getCoordLetter (string coordinate) {
    return tolower(coordinate[0]);
}

char getCoordNumber (string coordinate) {
    return tolower(coordinate[1]);
}

int coordinateToInt(string coord) {
    if(coord.size() != 2)
        return 100;
    
    char coordLetter = getCoordLetter(coord);
    if (!isValidCoordLetter(coordLetter))
        return 100;
    
    char coordNumber = getCoordNumber(coord);
    if (!isValidCoordNumber(coordNumber))
        return 100;
    
    return (coordLetter - 'a' + 1)*10 + coordNumber - 58;
}


void ships::createPlacementVector () {
    std::cout << "Create Placement Vector   :" << legalShip <<std::endl;
    string tempCoord = initialCoordinate;
    
    if(direction == "horizontal")
        tempCoord[1] = getCoordNumber(tempCoord) - 1;
    if (direction == "vertical")
        tempCoord[0] = getCoordLetter(tempCoord) - 1;
    
    for (int i = 0; i < size; i++) {
        if(direction == "horizontal")
            tempCoord[1] = getCoordNumber(tempCoord)+ 1;
        if (direction == "vertical")
            tempCoord[0] = getCoordLetter(tempCoord) + 1;
        
        holes.push_back(coordinateToInt(tempCoord));
    }
    isLegalShip();
}

#endif
