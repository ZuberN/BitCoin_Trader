//CryptoAccount Application
//Zuber Najam
//20180208

#include "cryptoAccount.h"



int getUserOption()
{
	int userOption;
	cout<<"\n**************ɃɃɃɃɃɃ*****************"<<endl;
	cout<<"Welcome To BitCoin Trader!"<<endl;
	//cout<<"Main Menu:"<<endl;
	cout<<"1- Buy More Bitcoins" <<endl;
	cout<<"2- Sell Some Bitcoins" <<endl;
	cout<<"3- Check Current Balance" <<endl;
	cout<<"***************ɃɃɃɃɃɃ****************"<<endl;
	cout<<"Enter an option:";
	cin>> userOption;
	return userOption;
}

double getInitialDepositFromUser()
{
	cout<<"Enter the initial deposit: ";
	double balance;
	cin>>balance;
	return balance;
}

void process()
{
	Account aAccount;
	int response;
	char cont = 'y';
	double balance= getInitialDepositFromUser();
	initialize(&aAccount, balance);
	print(&aAccount);
	while (cont!= 'n') 
		{
		response = getUserOption();
		switch (response) 
			{
			case 1: 
				buyMore(&aAccount, aAccount.coins);
				print(&aAccount);
				break;
			case 2: 
				sellSome(&aAccount, aAccount.coins);
				print(&aAccount);
				break;
			case 3: 
				print(&aAccount);
				break;
			}
		cout << "Would you like to perform another function? (type 'y' to continue or 'n' to end)>";
		cin >> cont;
	}
}

void initialize(Account* account, double deposit)
{
	account->balance = deposit;
	account->coins = 0.0;
}

bool buyMore(Account* account, double coins)
{
	
	double result = buy(coins);
	cout << "Checking Current Price=" << checkPrice() << endl;
	
	cout << "How Many Coins Do You Want To Purchase> ";
	cin >> coins;
	result = buy(coins);
	//cout<<result<<endl;
	
	if(result <= account->balance)
	{
		account->balance -= result;
		account->coins += coins;
		return 1;
		
	}
	else
	{
		cout<< "Sorry, Inadequate Funds"; cout << endl;
	return 0;
	}
	return 1;
}

bool sellSome(Account* account, double coins)
{
	double selling = sell(coins);
	cout << "Checking Current Price=" << checkPrice() << endl;
	cout << "How many coins do you want to sell?" << endl;
	cin >> coins;
	selling = sell(coins);
	//cout<<selling<<endl;
	
	if (coins <= account->coins) {
		account->balance += selling;
		account->coins -= coins;
		return 1;
	}
	else {
		cout << "Sorry, not enough coins to complete transaction" << endl;
		return 0;
	}

	return 1;
}

void print(Account* account)
{
	double total;
	total = account->coins*currentPrice + account->balance;
	
	cout<<"Your $balance = $"<<account->balance<<endl;
	cout<<"Your #coins = Ƀ"<<account ->coins<<endl;
	cout << "Total account value: $" << total << endl;
}



void print()
{
	cout<<"Current Price is="<<checkPrice()<<endl;
}

void test()
{
	Account aAccount;
	
	//double balance = getInitialDepositFromUser();
	double balance = 2000.01;
	cout<<"Balance = "<<balance<<endl;
	initialize(&aAccount, balance);
	print(&aAccount);
	cout<<"Current Price is="<<checkPrice()<<endl;
	buyMore(&aAccount, 0.25);
	sellSome(&aAccount, 0.20);
	print(&aAccount);
}


//void test()
//{
    //for(int i = 0; i < 20; i++) {
       //checkPrice();
        //print();
/*
    double soldAmount;
    double boughtAmount;
    cout<<"Current Price="<<checkPrice()<<endl;
    soldAmount = sell(1.0);
    cout<<"Money recovered="<<soldAmount<<endl;
        
    cout<<"Current Price="<<checkPrice()<<endl;
    boughtAmount = buy(1.0);
   cout<<"Profit="<< soldAmount-boughtAmount<<endl;
  */  