#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <windows.h>
#include "Buyersmenu-frontend.h"

using namespace std;

void nextStep(string studentID, string fullname);
void buyerMenu();
void back(string input, int x);

int stringToInt(string x)
{
	int num;
	if (x.length() > 1) {num = 10;}
	else if (x == "1")  {num = 1;}
	else if (x == "2")  {num = 2;}
	else if (x == "3")  {num = 3;}
	else if (x == "4")  {num = 4;}
	else if (x == "5")  {num = 5;}
	else if (x == "6")  {num = 6;}
	else if (x == "7")  {num = 7;}
	else if (x == "8")  {num = 8;}
	else if (x == "9")  {num = 9;}
	else {num = 10;}
	return num;
}

/*	Receipt system*/
void receipt(string order[], int quantity, string fullname, string mobileNum, string address, string studentID)
{
	system("CLS");
	system("color F1");
	string unifType, fullCode, itemCode;
	int itemSize, price, stocks;
	int totalPrice = 0;
	
	topReceipt();
	for (int i = 0; i < quantity; i++)
	{
		ifstream clotheprice("clotheprice.txt");
		while (clotheprice >> unifType >> fullCode >> itemCode >> itemSize >> price >> stocks)
		{
			if (order[i] == fullCode)
			{
				cout << "\n\t\t\t" << "º  "; 
				clotheTypeSize(itemCode, itemSize);
				cout << ".. " << "Php " << price << ".00 \t\tº";
				totalPrice += price;
			}
		}
	}
	bottomReceipt(totalPrice, fullname, mobileNum, address, studentID);
}

/*	Creates the clothecode to be inserted in to the file "databaseOrder.txt" */
string codeMaker(int clotheNum, int sizeNum)
{
	string cCode[26], iCode[8], order;
	
	if (clotheNum == 1 || clotheNum == 7 || clotheNum == 9 || clotheNum == 13 || clotheNum == 17) {
		cCode[1] = "FB"; cCode[7] = "BL"; cCode[9] = "WB"; cCode[13] = "CL"; cCode[17] = "RB";
		iCode[1] = "02"; iCode[2] = "03";
		iCode[3] = "04"; iCode[4] = "05";
	} else if (clotheNum == 2 || clotheNum == 8 || clotheNum == 10 || clotheNum == 14 || clotheNum == 18) {
		cCode[2] = "FS"; cCode[8] = "PA"; cCode[10] = "PT"; cCode[14] = "PS"; cCode[18] = "S";
		iCode[1] = "01"; iCode[2] = "02";
		iCode[3] = "03"; iCode[4] = "04";
		iCode[5] = "05";
	} else if (clotheNum == 3 || clotheNum == 4 || clotheNum == 11 || clotheNum == 12 || clotheNum == 15 || clotheNum == 16 || clotheNum == 19 || clotheNum == 20) {
		cCode[3] = "MP"; cCode[11] = "SC"; cCode[15] = "CC"; cCode[19] = "VN";
		cCode[4] = "P"; cCode[12] = "WS"; cCode[16] = "PW"; cCode[20] = "WP";
		iCode[1] = "02"; iCode[2] = "03";
		iCode[3] = "04";
	} else if (clotheNum == 5 || clotheNum == 6) {
		cCode[5] = "TS"; cCode[6] = "GS";
		iCode[1] = "02"; iCode[2] = "03";
		iCode[3] = "04"; iCode[4] = "05";
		iCode[5] = "06"; iCode[6] = "07";
	} else if (clotheNum == 21 || clotheNum == 22 || clotheNum == 23 || clotheNum == 24 || clotheNum == 25) {
		cCode[21] = "IL"; cCode[22] = "PP";
		cCode[23] = "PPF"; cCode[24] = "PPM";
		cCode[25] = "PR"; iCode[01] = "08";
	}
	order = cCode[clotheNum] + iCode[sizeNum];
	return (order);
}

int clotheCodeMaker(int typeNum, int clotheNum) {
	if (typeNum == 1) {
		switch (clotheNum) {
			case 1: clotheNum = 1 ; break; case 2: clotheNum = 2; break;
			case 3: clotheNum = 3 ; break; case 4: clotheNum = 4; break;
		}
	} else if (typeNum == 2) {
		switch (clotheNum) {
			case 1: clotheNum = 5 ; break; case 2: clotheNum = 6; break;
		}
	} else if (typeNum == 3) {
		switch (clotheNum) {
			case 1: clotheNum = 7 ; break; case 2: clotheNum = 8; break;
		}
	} else if (typeNum == 4) {
		switch (clotheNum) {
			case 1: clotheNum = 9 ; break; case 2: clotheNum = 10; break;
			case 3: clotheNum = 11; break; case 4: clotheNum = 12; break;
		}
	} else if (typeNum == 5) {
		switch (clotheNum) {
			case 1: clotheNum = 13; break; case 2: clotheNum = 14; break;
			case 3: clotheNum = 15; break; case 4: clotheNum = 16; break;
		}
	} else if (typeNum == 6) {
		switch (clotheNum) {
			case 1: clotheNum = 17; break; case 2: clotheNum = 18; break;
			case 3: clotheNum = 19; break; case 4: clotheNum = 20; break;
		}
	} else if (typeNum == 7) {
		switch (clotheNum) {
			case 1: clotheNum = 21; break; case 2: clotheNum = 22; break;
			case 3: clotheNum = 23; break; case 4: clotheNum = 24; break;
			case 5: clotheNum = 25; break;
		}
	}
	return clotheNum;
}

/*	Translates the users input into the clothecode */
string numToClotheCode(int clotheNum)
{
	string clotheCode;
	switch (clotheNum) {
		case 1 : clotheCode = "FB"; break; case 2 : clotheCode = "FS"; break;
		case 3 : clotheCode = "MP"; break; case 4 : clotheCode = "P" ; break;
		case 5 : clotheCode = "TS"; break; case 6 : clotheCode = "GS"; break;
		case 7 : clotheCode = "BL"; break; case 8 : clotheCode = "PA"; break;
		case 9 : clotheCode = "WB"; break; case 10: clotheCode = "PT"; break;
		case 11: clotheCode = "SC"; break; case 12: clotheCode = "WS"; break;
		case 13: clotheCode = "CL"; break; case 14: clotheCode = "PS"; break;
		case 15: clotheCode = "CC"; break; case 16: clotheCode = "PW"; break;
		case 17: clotheCode = "RB"; break; case 18: clotheCode = "S" ; break;
		case 19: clotheCode = "VN"; break; case 20: clotheCode = "WP"; break;
	}
	return clotheCode;
}

/*	Types of sizes for each type of clothe system */
int sizeTypeMenu(int typeNum, int clotheNum)
{
	char repeat;
	string choice;
	
	do {
		system("CLS");
		int cycle = 2, looper, price, count, spaces;
		int stocks[10], prices[10], sizeNum , i = 1, itemSize, stocksInFile;
		string unifType, fullCode, itemCode, clotheCode;
			
		if (clotheNum == 1 || clotheNum == 7 || clotheNum == 9 || clotheNum == 13 || clotheNum == 17) {
			looper = 5; spaces = 3;
		} else if (clotheNum == 2 || clotheNum == 8 || clotheNum == 10 || clotheNum == 14 || clotheNum == 18) {
			cycle = 1;
			looper = 5; spaces = 2;
		} else if (clotheNum == 3 || clotheNum == 11 || clotheNum == 15 || clotheNum == 19) {
			looper = 4; spaces = 4;
		} else if (clotheNum == 4 || clotheNum == 12 || clotheNum == 16 || clotheNum == 20) {
			looper = 4; spaces = 4;
		} else if (clotheNum == 5 || clotheNum == 6) {
			looper = 7; spaces = 1;
		}
		sizeMenuTop(clotheNum);
		clotheCode = numToClotheCode(clotheNum);
		ifstream sizeMenuStocks("clotheprice.txt");
		while (sizeMenuStocks >> unifType >> fullCode >> itemCode >> itemSize >> price >> stocksInFile) {
			if (clotheCode == itemCode) {
				prices[i] = price;
				stocks[i] = stocksInFile;
				i += 1;
			}
		}
		sizeMenuStocks.close();
		count = sizeMenuBottom(stocks, prices, cycle, looper, spaces);
		
		getline(cin, choice);
		sizeNum = stringToInt(choice);
		if (sizeNum == count) {
			sizeNum = 10;
			return (sizeNum);
		} else if (sizeNum > count || sizeNum < 1) {
			otherOption();
			repeat = 'y';
		} else if (sizeNum < count || sizeNum > 0) {
			if (stocks[sizeNum] != 0) {
				return (sizeNum);
			} else {
				itemUnavailible();
				repeat = 'y';
			}
		}
	}
	while (repeat == 'y');
}

/*	Add ons menu */
int addonsMenu()
{
	char repeat;
	string choice;
	do {
		system("CLS");
		string unifType, fullCode, itemCode;
		int i = 0, itemSize, stocksInFile, stocks[5], prices[5], clotheNum, price;
		ifstream addonsMenuStocks("clotheprice.txt");
		while (addonsMenuStocks >> unifType >> fullCode >> itemCode >> itemSize >> price >> stocksInFile) {
			if (unifType == "AO") {
				prices[i] = price;
				stocks[i] = stocksInFile;
				i += 1;
			}
		}
		addonsMenuStocks.close();
		addons(stocks, prices);
		getline(cin, choice);
		clotheNum = stringToInt(choice);
		if (clotheNum == 6) {
			clotheNum = 6;
			return (clotheNum);
		} else if (clotheNum > 6 || clotheNum < 1) {
			otherOption();
			repeat = 'y';
		} else if (clotheNum < 6 || clotheNum > 0) {
			if (stocks[clotheNum - 1] != 0) {
				return (clotheNum);
			} else {
				itemUnavailible();
				repeat = 'y';
			}
		}
	}
	while (repeat == 'y');
}

/*	Main control of the ordering system */
string mainMenu()
{
	string order;
	int typeNum, clotheNum, sizeNum, count, repeater;
	string choice;
	
	do {
		uniTypeMenu();
		getline(cin, choice);
		typeNum = stringToInt(choice);
		if (typeNum > 8 || typeNum < 1) {
			otherOption();
		} else if (typeNum == 8) {
			cancelOrder();
			order = "cancelled";
		} else if (typeNum == 7) {
			do {
				clotheNum = addonsMenu();
				if (clotheNum == 6) {
					typeNum = 10;
				} else if (clotheNum > 6 || clotheNum < 1) {
					otherOption();
					clotheNum = 0;
				} else {
					clotheNum = clotheCodeMaker(typeNum, clotheNum);
					sizeNum = 1;
					order = codeMaker(clotheNum, sizeNum);
				}
			}
			while(clotheNum == 0);
		} else {
			do {
				count = clotheTypeMenu(typeNum);
				getline(cin, choice);
				clotheNum = stringToInt(choice);
				repeater = clotheNum;
				if (clotheNum == count) {
					typeNum = 10;
				} else if (clotheNum > count || clotheNum < 1) {
					otherOption();
				} else {
					clotheNum = clotheCodeMaker(typeNum, clotheNum);
					sizeNum = sizeTypeMenu(typeNum, clotheNum);
					if (sizeNum == 10) {
						repeater = 10;
					} else {
						order = codeMaker(clotheNum, sizeNum);
					}
				}
			}
			while(repeater > count);
		}
	}
	while(typeNum > 8 || typeNum < 1);	
	return order;
}

/*	Inserting orders to the file "databaseOrder.txt" */
void inserFile(string fullname, string mobileNum, string address, string studentID, string orderToFile, int quantity)
{
	int day, month, year;
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	day = local_time->tm_mday;
	month = 1 + local_time->tm_mon;
	year = 1900 + local_time->tm_year;
	ofstream toFile("databaseOrder.txt", ios::app);
	toFile	<< endl
			<< endl << fullname
			<< endl << mobileNum
			<< endl << address
			<< endl << studentID
			<< endl << quantity
			<< endl << orderToFile;
	toFile.close();
	ofstream orderDay("day of order.txt", ios::app);
	orderDay<< endl
			<< fullname << endl
			<< studentID << endl
			<< month << "/" << day << "/" << year << endl;
	orderDay.close();
	exit(0);
}

/*	Main buying menu */
void buyMenu(string fullname, string mobileNum, string address, string studentID)
{
	int quantity = 0;
	string order[100], orderToFile;
	int stocks, itemSize, price, i;
	string unifType, itemCode, clotheCode;
	char more;
	
	do {
		processMenu();
		order[quantity] = mainMenu();
		if (order[quantity] == "cancelled") {
			if (quantity == 0) {
				exit(0);
			} else {
				more = 'n';
				quantity -= 1;
			}
		} else {
			purchaseMore();
			cin >> more;
			cin.ignore();
		}
		ifstream openFile("clotheprice.txt");
		ofstream newFile("newfile.txt");
		while(openFile >> unifType >> itemCode >> clotheCode >> itemSize >> price >> stocks) {
			if (order[quantity] == itemCode) {
				stocks -= 1;
			}
			newFile << unifType << " " << itemCode << " " << clotheCode << " " << itemSize << " " << price << " " << stocks << endl;
		}
		newFile.close();
		openFile.close();
		remove("clotheprice.txt");
		rename("newfile.txt", "clotheprice.txt");
		quantity += 1;
	}
	while(more == 'Y' || more == 'y');
	processReceipt();
	receipt(order, quantity, fullname, mobileNum, address, studentID);
	for (int k = 0; k < quantity; k++) {
		orderToFile = orderToFile + order[k] + " ";
	}
	inserFile(fullname, mobileNum, address, studentID, orderToFile, quantity);
}

/*	Part of the receipt and history */
void codeOfClothe(string orders)
{
	int price, itemSize, stocks;
	string unifType, fullCode, itemCode;
		
	ifstream codeClotheOpen("clotheprice.txt");
	
	while(codeClotheOpen >> unifType >> fullCode >> itemCode >> itemSize >> price >> stocks)
	{
		if (fullCode == orders)
		{
			clotheTypeSize(itemCode, itemSize);
			cout << "... " << "Php " << price << ".00" << "\tº";
		}
	}
	codeClotheOpen.close();
}

/*	History of past transactions
	Data gathered from "databaseOrder.txt" */
void seeHistory(string studentID, string fullname)
{
	system("CLS");
	int transaction = 1, priceSum = 0, overallTotal = 0;
	int price, stocks, quantity, itemSize;
	string unifType, fullCode, itemCode;
	string idNumber, orders;
	ifstream history("databaseOrder.txt");
	historyTransactions();
	while (history >> idNumber)
	{
		if (studentID == idNumber)
		{
			history >> quantity;
			cout << "\n\t\t\t" << "º  Transaction No. " << transaction << "\t\t\t\t\t\tº";
			line();
			for (int counts = 1; counts <= quantity; counts++)
			{
				history >> orders;
				cout << "\n\t\t\t" << "º  " << counts << ". ";
				codeOfClothe(orders);
				ifstream addPrice("clotheprice.txt");
				while (addPrice >> unifType >> fullCode >> itemCode >> itemSize >> price >> stocks)
				{
					if (orders == fullCode)
					{
						priceSum += price;
					}
				}
				addPrice.close();
			}
			totalPrice(priceSum);
			overallTotal += priceSum;
			priceSum = 0;
			transaction += 1;
		}
	}
	allTotal(overallTotal);
	got(44, 8);
	cout << fullname;
	got(44, 9);
	cout << studentID;
	got(1, 1);
	system("pause > nul");
	history.close();
	system("CLS");
	nextStep(studentID, fullname);	
}

/*	Account data collection process */
void buyMore(string studentID, string fullname)
{
	string fname, mobileNum, address, studentNum;
	ifstream buymore("databaseOrder.txt");
	
	while (!buymore.eof())
	{
		getline(buymore, fname);
		if (fullname == fname)
		{
			buymore >> mobileNum;
			getline(buymore >> ws, address);
			buymore >> studentNum;
			if (studentNum == studentID)
			{
				buymore.close();
				buyMenu(fullname, mobileNum, address, studentID);
			}
		}
	}
}

/*	Account found menu
	Options:
	Buy Again
	See History
	Exit */
void nextStep(string studentID, string fullname)
{
	system("CLS");
	int user;
	string choice;
	SearchAcctMenu();
	got(39, 16);
	getline(cin, choice);
	user = stringToInt(choice);
	if (user == 1)
	{
		buyMore(studentID, fullname);
	} else if (user == 2)
	{
		HstryLoadMsg();
		seeHistory(studentID, fullname);
	} else if (user == 3)
	{
		ExitMsg ();
		exit(0);
	} else
	{
		otherOption();
		nextStep(studentID, fullname);
	}
}

/*	Search account process */
void searchAccount()
{
	system("CLS");
	string username, userID;
	string fullname, mobileNum, address, studentID;
	char user;
	ifstream search("databaseOrder.txt");
	username = nameInput(1); back(username, 2);
	userID = idInput(1); back(userID, 2);
	ProcessAcctLoadMsg();
	while (!search.eof())
	{
		getline(search, fullname);
		if (username == fullname)
		{
			getline(search >> ws, mobileNum);
			getline(search >> ws, address);
			getline(search, studentID);
			if (userID == studentID)
			{
				AcctFndMsg();
				nextStep(studentID, fullname);
			}
		}
	}
	AcctNotFndMsg ();
	searchAccount();
}

/*	Account creating process */
void createAccount()
{
	system("CLS");
	string fullname, mobileNum, address, studentID;
	
	fullname = nameInput(0);
	mobileNum = numberInput();
	address = homeInput();
	studentID = idInput(0);
	CreateAcctLoadMsg();
	buyMenu(fullname, mobileNum, address, studentID);
}

/*	Back Option
	"press x to return" */
void back(string input, int x)
{
	if (input == "x" || input == "X")
	{
		loadingMessage();
		buyerMenu();
	} else if (input == "")
	{
		emptyOption();
		if (x == 1)
		{
			createAccount();
		} else if (x == 2)
		{
			searchAccount();
		}
	}
}

/*	First Menu 
	Options:
 	Create Account
	Search Accoun */
void buyerMenu()
{
	int user;
	string choice;
	system("color F0");
	do {
		WelcomeMessage ();
		getline(cin, choice);
		user = stringToInt(choice);
		if (user == 1)
		{
			loadingMessage();
			createAccount();
		} else if (user == 2)
		{
			loadingMessage();
			searchAccount();
		} else
		{
			WelcomeMessage ();
			otherOption();
		}
	}
	while (user > 2);
}
