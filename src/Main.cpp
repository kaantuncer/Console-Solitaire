#include "./cardManager.h"

using namespace std;

int main(int argc, char *argv[]) {

    CardManager cardManager = CardManager(argv[1],argv[2],argv[3]);

    cardManager.fillDeck();
    cardManager.executeCommands();




    return 0;
}
