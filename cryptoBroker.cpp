//CryptoAccount Application
//Zuber Najam
//20180208


#include "cryptoBroker.h"

double sell(double quantity){
    return quantity * currentPrice;
}
double  buy(double quantity){
    
    return  quantity * currentPrice;
}

double checkPrice(){
     //sleep(1);
     //srand(time(NULL));
     return    currentPrice = 1000 + (0.5 - ((double) rand())/RAND_MAX)*RANGE;
}