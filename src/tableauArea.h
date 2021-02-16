#include "pile.h"
#pragma once


//This class is for storing the entire tableau area

class TableauArea {
    Pile pileArray[7];
public:
    TableauArea();
    Pile* getPileArray();
    std::string getPileString();

};


