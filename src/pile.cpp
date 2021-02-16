
#include "pile.h"

Pile::Pile(){
    index = -1;
}
void Pile::setClosedCount(int count) {
    closedCount= count;
}
int Pile::getClosedCount() {
    return closedCount;
}
int Pile::setCard(Card card) {
    if(index >= 20){
        return -1;
    }
    index+=1;
    pile[index] = card;
    return 1;

}

int Pile::addCard(Card cards[16]) {

    if(index != -1 && closedCount-1 == index){
        return -1;
    }

    int currentPileIndex = 0;

    while(cards[currentPileIndex].type ==  'H' ||  cards[currentPileIndex].type ==  'D' || cards[currentPileIndex].type ==  'S' || cards[currentPileIndex].type ==  'C'){
        currentPileIndex++;
    }
    currentPileIndex--;

    if(index == -1){

        if(cards[currentPileIndex].number == 13 ){
            while(currentPileIndex != -1){
                setCard(cards[currentPileIndex]);
                currentPileIndex--;
            }
            return 1;
        }
        else{
            return -1;
        }
    }

    char currentPileType = getTopCard()->type;

    if(cards[currentPileIndex].number +1 == pile[index].number && (currentPileType == 'H' || currentPileType == 'D') && (cards[currentPileIndex].type == 'S' ||cards[currentPileIndex].type=='C')){

        while(currentPileIndex != -1){
            setCard(cards[currentPileIndex]);
            currentPileIndex--;
        }
        return 1;

    }
    else if(cards[currentPileIndex].number +1 == pile[index].number && (currentPileType == 'S' ||currentPileType == 'C') && (cards[currentPileIndex].type == 'H' || cards[currentPileIndex].type == 'D')){
        while(currentPileIndex != -1){
            setCard(cards[currentPileIndex]);
            currentPileIndex--;
        }
        return 1;
    }
    return -1;

}

int Pile::removeCards(int count){

    for(int i = 0 ; i<count ; i++){
        pile[index - i] = Card();
    }
    index -= count;

    return 1;

}

Card* Pile::getTopCard() {
    if(index == -1 || index==closedCount-1){
        return NULL ;
    }
    else{
        return &pile[index];
    }
}
int Pile::open() {
    if(index == closedCount-1){
        closedCount--;
        return 1;
    }
    return -1;
}
