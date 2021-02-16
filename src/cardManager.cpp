#include "cardManager.h"

CardManager::CardManager(std::string deck ,std::string commands,std::string output) {

    deckPath = deck;
    commandsPath =commands;
    outputPath = output;

    foundation = Foundation();
    tableauArea = TableauArea();
}

void CardManager::fillDeck() {
    std::ifstream input;

    input.open(deckPath);

    std::string line;
    std::string strDeck[52];
    for(int i = 0 ; i<52; i++){
        input>>line;
        strDeck[i] = line;
    }
    input.close();

    int index = 51;

    for(int i = 0 ; i<8;i++){

        if(i<1){
            tableauArea.getPileArray()[0].setCard(Card(strDeck[index]));
            index--;
        }
        if(i<2){
            tableauArea.getPileArray()[1].setCard(Card(strDeck[index]));
            index--;
        }
        if(i<3){
            tableauArea.getPileArray()[2].setCard(Card(strDeck[index]));
            index--;
        }
        if(i<4){
            tableauArea.getPileArray()[3].setCard(Card(strDeck[index]));
            index--;
        }
        if(i<5){
            tableauArea.getPileArray()[4].setCard(Card(strDeck[index]));
            index--;
        }
        if(i<6){
            tableauArea.getPileArray()[5].setCard(Card(strDeck[index]));
            index--;
        }
        if(i<7){
            tableauArea.getPileArray()[6].setCard(Card(strDeck[index]));
            index--;
        }
        else{
            int deckIndex = 0;
            while(index != -1){
                deck[deckIndex] = Card(strDeck[index]);
                deckIndex++;
                index--;
            }

        }
    }
}




void CardManager::executeCommands() {
    bool exited = false;
    std::ofstream output;
    output.open(outputPath);
    output<<std::endl;
    std::ifstream input;
    std::string line;
    input.open(commandsPath);
    while(input>>line){

        bool invalidMove = false;

        if(line == "exit"){
            exited =true;
            break;
        }

        std::string entireCommand;

        entireCommand +=line+ " ";

        output<<waste.getWasteString()<<"        "<<foundation.getTopCards()<<std::endl;
        output<<std::endl;
        output<<tableauArea.getPileString()<<std::endl;

        if(line == "move"){

            input>>line;
            entireCommand +=line+ " ";

            if(line == "to"){
                input>>line; //foundation
                entireCommand +=line + " ";
                input>>line; //pile
                entireCommand +=line+ " ";

                if(line == "waste"){

                    int index = 2;
                    while(index != -1 && waste.getWaste()[index].type == '-'){
                        index--;
                    }
                    int response = foundation.addCard(waste.getWaste()[index]);
                    if(response == 1){
                        waste.removeFromWaste(index);
                    }
                    else{
                        invalidMove = true;
                    }


                }
                else{
                    input>>line; //number
                    entireCommand +=line+ " ";
                    int index = std::stoi(line);
                    Card* card = tableauArea.getPileArray()[index].getTopCard();
                    if(card == NULL){
                        entireCommand.erase(entireCommand.end()-1,entireCommand.end());
                        output<<entireCommand<<std::endl;
                        output<<std::endl;
                        output<<"Invalid Move!"<<std::endl;
                        output<<std::endl;
                        output<<"****************************************"<<std::endl;
                        output<<std::endl;
                        continue;
                    }
                    int response = foundation.addCard(*card);
                    if(response == 1){
                        tableauArea.getPileArray()[index].removeCards(1);
                    }
                    else{
                        invalidMove = true;
                    }
                }

            }
            //move foundation pile 0 1
            else if(line == "foundation"){

                input>>line;//pile
                entireCommand+=line +" ";
                input>>line; //foundation Index
                entireCommand+=line+" ";

                int foundationIndex = std::stoi(line);

                input>>line;//pile index
                entireCommand+=line +" ";
                int pileIndex = std::stoi(line);

                Card removedCard = foundation.removeCard(foundationIndex);
                if(removedCard.type == '-'){
                    invalidMove = true;
                }
                else{
                  int response =  tableauArea.getPileArray()[pileIndex].addCard(&removedCard);
                  if(response != 1){
                      invalidMove =true;
                      foundation.addCard(removedCard);
                  }
                }

            }


            else if(line == "pile"){
                input>>line; //index from
                int indexFrom = std::stoi(line);
                entireCommand +=line+ " ";
                input>>line; //amount -1
                int amount = std::stoi(line) +1;
                entireCommand +=line+ " ";
                input>>line; //index to
                int indexTo = std::stoi(line);
                entireCommand +=line+ " ";


                Card cards[13];
                bool wrongMove = false;
                for(int i = 0 ; i<amount ; i++){
                    cards[i] = tableauArea.getPileArray()[indexFrom].pile[tableauArea.getPileArray()[indexFrom].index-i];
                    if(tableauArea.getPileArray()[indexFrom].index-i + 1  <= tableauArea.getPileArray()[indexFrom].getClosedCount()){
                        entireCommand.erase(entireCommand.end()-1,entireCommand.end());
                        output<<entireCommand<<std::endl;
                        output<<std::endl;
                        output<<"Invalid Move!"<<std::endl;
                        output<<std::endl;
                        output<<"****************************************"<<std::endl;
                        output<<std::endl;
                        invalidMove = true;
                        wrongMove =true;
                        break;
                    }
                }
                if(wrongMove){
                    continue;
                }
                int response = tableauArea.getPileArray()[indexTo].addCard(cards);
                if(response == 1){
                    tableauArea.getPileArray()[indexFrom].removeCards(amount);
                }
                else{
                    invalidMove = true;
                }



            }
            else if(line == "waste"){
                input>>line; //pile index
                int pileIndex = std::stoi(line);
                entireCommand +=line+ " ";

                int index = 2;
                while(index != -1 && waste.getWaste()[index].type == '-'){
                    index--;
                }
                Card card[16];
                card[0] = waste.getWaste()[index];
                int response = tableauArea.getPileArray()[pileIndex].addCard(card);

                if(response == 1){
                    waste.removeFromWaste(index);
                }
                else{
                    invalidMove =true;
                }

            }



        }
        else if(line == "open"){

            input>>line;
            entireCommand +=line+ " ";
            if(line == "from"){
                input>>line; //stock
                entireCommand +=line+ " ";
                waste.drawCards();
            }
            else{
                int index = std::stoi(line);
                int response = tableauArea.getPileArray()[index].open();
                if(response == -1){
                    invalidMove = true;
                }
            }



        }
        else{
            output<<"ERROR : "<<line<<std::endl;
        }
        entireCommand.erase(entireCommand.end()-1,entireCommand.end());
        output<<entireCommand<<std::endl;
        output<<std::endl;
        if(invalidMove){
            output<<"Invalid Move!"<<std::endl;
            output<<std::endl;
        }
        output<<"****************************************"<<std::endl;
        output<<std::endl;
    }


    input.close();

    output<<waste.getWasteString()<<"        "<<foundation.getTopCards()<<std::endl;
    output<<std::endl;
    output<<tableauArea.getPileString()<<std::endl;
    if(exited){
        output<<"exit"<<std::endl;
        output<<std::endl;
    }
    else{
        output<<std::endl;
    }
    output<<"****************************************"<<std::endl;
    output<<std::endl;


    if(foundation.isComplete()){
        output<<"You Win!"<<std::endl;
        output<<std::endl;
    }
    output<<"Game Over!"<<std::endl;
    output.close();


}

