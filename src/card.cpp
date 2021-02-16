
#include "card.h"
    Card::Card(std::string str){
        type = str[0] ;
        std::string strNumber;
        strNumber+=str[1];
        strNumber+=str[2];
        number = std::stoi(strNumber);
    };
    Card::Card(){
        type = '-';
        number = -1;
    }
std::string Card::getCardString() {

        if(type == '-'){
            return "___";
        }
        else{
            std::string strNumber = std::to_string(number);
            if(strNumber.size() == 1){
                strNumber+=strNumber;
                strNumber[0] = '0';
            }
            return type+ strNumber;
        }

    }
