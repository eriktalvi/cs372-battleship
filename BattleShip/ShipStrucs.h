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

struct ships
{
    bool legalShip;
    string type;
    string initialCoordinate;
    string direction;
    int size;
    
    vector<int> holes;
};


int attack(int coordinates)
{
    return 0;
}

#endif
