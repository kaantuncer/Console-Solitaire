
#pragma once
#include <iostream>
#include <fstream>
#include "card.h"
#include "foundation.h"
#include "tableauArea.h"
#include "cardManager.h"
#include "waste.h"


//This class fills the entire deck and executes all the commands.

class CardManager {
    std::string deckPath;
    std::string commandsPath;
    std::string outputPath;
public:
    CardManager(std::string deck ,std::string commands,std::string output);
    Foundation foundation;
    Card deck[28];
    Card placeholderDeck[28];
    Waste waste = Waste(deck,placeholderDeck);
    TableauArea tableauArea;
    void fillDeck();
    void executeCommands();


};


