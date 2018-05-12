//CryptoAccount Application
//Zuber Najam
//20180208

#define _CRT_SECURE_NO_WARNINGS
#ifndef  CRYPTOBROKER_H
#define CRYPTOBROKER_H 

#include <iostream>
#include <string>
#include <cstdlib>

#define RANGE 300

using namespace std;

extern double currentPrice;

double sell(double quantity);  //Returns the $value of the coins sold. 
double buy(double quantity);   //Returns the $value of the coins bought.
double checkPrice();           //Returns  the current value of one coin.
void print();
void test();

#endif