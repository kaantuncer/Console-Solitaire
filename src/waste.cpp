

#include "waste.h"

Waste::Waste(Card *givenDeck, Card *givenPlaceholderDeck) {
    deck = givenDeck;
    placeholderDeck= givenPlaceholderDeck;

}

std::string Waste::getWasteString() {
    std::string result;
        if(deck[0].type != '-'){
            result+= "@@@ ";
        }
        else{
            result+="___ ";
        }
        for(int i = 0 ; i<3 ; i++){

            result += waste[i].getCardString() +" ";

        }
        return result;

}

void Waste::drawCards() {

    if(waste[0].type != '-'){

        int index = 0;

        while(placeholderDeck[index].type != '-'){
            index++;
        }

        int wasteIndex = 0;

        while(wasteIndex != 3 && waste[wasteIndex].type != '-'){
            placeholderDeck[index] = waste[wasteIndex];
            index++;
            wasteIndex++;

        }
        waste[0] = Card();
        waste[1] = Card();
        waste[2] = Card();
    }

    int wasteCount = 0;

    for(int i = 0 ;i<3 ; i++){
        if(deck[i].type != '-'){
            waste[i] = deck[i];
            wasteCount++;
        }
    }



    if(wasteCount == 0){
        for(int i = 0 ;i<28 ; i++){
            deck[i] = placeholderDeck[i];
            placeholderDeck[i] = Card();
        }
        return;
    }

    int index = 0;

    while(deck[index].type != '-'){

        deck[index] = deck[index+wasteCount];
        index++;

    }
    for(int i = 1 ;i<=wasteCount ;i++){
        deck[index-i] = Card();
    }
}

Card * Waste::getWaste() {

    return waste;
}

int Waste::removeFromWaste(int index) {

    waste[index] = Card();
    if(index == 0 && placeholderDeck[0].type != '-'){
        int index = 0;
        while(placeholderDeck[index].type != '-'){
            index++;
        }
        waste[0] = placeholderDeck[index-1];
        placeholderDeck[index-1] = Card();

    }

    return 1;


}
