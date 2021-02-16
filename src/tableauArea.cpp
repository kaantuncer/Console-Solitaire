
#include "tableauArea.h"

TableauArea::TableauArea() {
    pileArray[0].setClosedCount(0);
    pileArray[1].setClosedCount(1);
    pileArray[2].setClosedCount(2);
    pileArray[3].setClosedCount(3);
    pileArray[4].setClosedCount(4);
    pileArray[5].setClosedCount(5);
    pileArray[6].setClosedCount(6);
}

Pile* TableauArea::getPileArray() {
    return pileArray;
}

std::string TableauArea::getPileString() {
    std::string result;

    for(int i = 0 ;i<20 ; i++){
        int count = 0;
        if(pileArray[0].index < i){
            result += "   ";
            count+=1;
        }
        else if(pileArray[0].getClosedCount() > i){
            result+="@@@";
        }
        else{
            result+= pileArray[0].pile[i].getCardString();
        }
        result+="   ";

        if(pileArray[1].index < i){
            result += "   ";
            count+=1;
        }
        else if(pileArray[1].getClosedCount() > i){
            result+="@@@";
        }
        else{
            result+= pileArray[1].pile[i].getCardString();
        }
        result+="   ";

        if(pileArray[2].index < i){
            result += "   ";
            count+=1;
        }
        else if(pileArray[2].getClosedCount() > i){
            result+="@@@";
        }
        else{
            result+= pileArray[2].pile[i].getCardString();
        }
        result+="   ";

        if(pileArray[3].index < i){
            result += "   ";
            count+=1;
        }
        else if(pileArray[3].getClosedCount() > i){
            result+="@@@";
        }
        else{
            result+= pileArray[3].pile[i].getCardString();
        }
        result+="   ";


        if(pileArray[4].index < i){
            result += "   ";
            count+=1;
        }
        else if(pileArray[4].getClosedCount() > i){
            result+="@@@";
        }
        else{
            result+= pileArray[4].pile[i].getCardString();
        }
        result+="   ";


        if(pileArray[5].index < i){
            result += "   ";
            count+=1;
        }
        else if(pileArray[5].getClosedCount() > i){
            result+="@@@";
        }
        else{
            result+= pileArray[5].pile[i].getCardString();
        }
        result+="   ";


        if(pileArray[6].index < i){
            result += "   ";
            count+=1;
        }
        else if(pileArray[6].getClosedCount() > i){
            result+="@@@";
        }
        else{
            result+= pileArray[6].pile[i].getCardString();
        }
        result+="   ";

        if(count == 7){
            if(i != 0){
                result.erase(result.end()-42,result.end());
            }
            break;
        }
        result+='\n';

    }
    return result;




}
