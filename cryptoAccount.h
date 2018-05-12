//CryptoAccount Application
//Zuber Najam
//20180208

#include "cryptoBroker.h"


#ifndef CRYPTOACCOUNT_H
#define CRYPTOACCOUNT_H


typedef struct{
	double balance;
	double coins;
} Account;

int getUserOption();
double getInitialDepositFromUser();
void process();
void initialize(Account* account, double coins);
bool buyMore(Account* account, double coins);
bool sellSome(Account* account, double coins);
void print(Account* account);

void print();
void test();

#endif