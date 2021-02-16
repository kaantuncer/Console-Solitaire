#include <iostream>
#pragma once



struct Card{
    int number;
    char type;
    Card(std::string str);
    Card();
    std::string getCardString();
};