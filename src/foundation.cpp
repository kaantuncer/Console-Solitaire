#include "card.h"

#include "foundation.h"

    Foundation::Foundation(){
         type1 = 'H';
         type2 = 'D';
         type3 = 'S';
         type4 = 'C';
        index1 =-1;
        index2=-1;
        index3=-1;
        index4=-1;
    }
    int Foundation::addCard(Card card){
        if(card.type == type1){
            if(index1 == -1 && card.number == 1){
                index1++;
                foundation[0][index1] = card;
                return 1;
            }
            else if(foundation[0][index1].number + 1 == card.number){
                index1++;
                foundation[0][index1] = card;
                return 1;
            }
            else{
                return -1;
            }

        }
        else if(card.type == type2){
            if(index2 == -1 && card.number == 1){
                index2++;
                foundation[1][index2] = card;
                return 1;
            }
            else if(foundation[1][index2].number +1 == card.number){
                index2++;
                foundation[1][index2] = card;
                return 1;
            }
            else{
                return -1;
            }

        }
        else if(card.type == type3){
            if(index3 == -1 && card.number == 1){
                index3++;
                foundation[2][index3] = card;
                return 1;
            }
            else if(foundation[2][index3].number +1 == card.number){
                index3++;
                foundation[2][index3] = card;
                return 1;
            }
            else{
                return -1;
            }

        }
        else if(card.type == type4){
            if(index4 == -1 && card.number == 1){
                index4++;
                foundation[3][index4] = card;
                return 1;
            }
            else if(foundation[3][index4].number +1 == card.number){
                index4++;
                foundation[3][index4] = card;
                return 1;
            }
            else{
                return -1;
            }

        }
        return -1;
    };

Card Foundation::removeCard(int index) {

    if(index==0){
        if(index1 == -1){
            return Card();
        }
        else{
            Card card = foundation[0][index1];
            foundation[0][index1] = Card();
            index1--;
            return card;

        }
    }
    else if(index==1){
        if(index2 == -1){
            return Card();
        }
        else{
            Card card = foundation[1][index2];
            foundation[1][index2] = Card();
            index2--;
            return card;

        }
    }
    else if(index==2){
        if(index3 == -1){
            return Card();
        }
        else{
            Card card = foundation[2][index3];
            foundation[2][index3] = Card();
            index3--;
            return card;

        }
    }
    else if(index==3){
        if(index4 == -1){
            return Card();
        }
        else{
            Card card = foundation[3][index4];
            foundation[3][index4] = Card();
            index4--;
            return card;

        }
    }
    return Card();

}

std::string Foundation::getTopCards() {

    std::string result ;
        if(index1 != -1){
            std::string strNumber = std::to_string(foundation[0][index1].number);
            if(strNumber.size() == 1){
                strNumber+=strNumber;
                strNumber[0] = '0';
            }
            result += foundation[0][index1].type+  strNumber  +" ";
        }
        else{
            result += "___ ";
        }

        if(index2 != -1){
            std::string strNumber = std::to_string(foundation[1][index2].number);
            if(strNumber.size() == 1){
                strNumber+=strNumber;
                strNumber[0] = '0';
            }
            result += foundation[1][index2].type+ strNumber +" ";
        }
        else{
            result += "___ ";
        }

        if(index3 != -1){

            std::string strNumber = std::to_string(foundation[2][index3].number);
            if(strNumber.size() == 1){
                strNumber+=strNumber;
                strNumber[0] = '0';
            }

            result +=  foundation[2][index3].type + strNumber  +" ";
        }
        else{
            result += "___ ";
        }

        if(index4 != -1){
            std::string strNumber = std::to_string(foundation[3][index4].number);
            if(strNumber.size() == 1){
                strNumber+=strNumber;
                strNumber[0] = '0';
            }
            result += foundation[3][index4].type + strNumber  +" ";
        }
        else{
            result += "___ ";
        }

        return result;


    }
    bool Foundation::isComplete() {

        if(foundation[0][12].number == 13 && foundation[1][12].number == 13 && foundation[2][12].number == 13 && foundation[3][12].number == 13){
            return true;
        }
        else{
            return false;
        }

    }

