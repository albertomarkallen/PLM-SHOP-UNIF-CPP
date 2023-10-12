#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

void clothtypesize(string clothcode, int sizecode)
{
	cout << "     ";
		 if (clothcode == "FB" ) {cout << "Blouse .............";}
	else if (clothcode == "FS" ) {cout << "Skirt ..............";}
	else if (clothcode == "MP" ) {cout << "Polo ...............";}
	else if (clothcode == "P"  ) {cout << "Pants ..............";}
	else if (clothcode == "TS" ) {cout << "T-Shirt ............";}
	else if (clothcode == "GS" ) {cout << "Garterized Shorts ..";}
	else if (clothcode == "BL" ) {cout << "Blouse .............";}
	else if (clothcode == "PA" ) {cout << "Pants ..............";}
	else if (clothcode == "WB" ) {cout << "Plain White Blouse .";}
	else if (clothcode == "PT" ) {cout << "Pleats .............";}
	else if (clothcode == "SC" ) {cout << "Sports Collar Polo .";}
	else if (clothcode == "WS" ) {cout << "White Slacks .......";}
	else if (clothcode == "CL" ) {cout << "Collar-less Blouse .";}
	else if (clothcode == "PS" ) {cout << "Pencil Skirt .......";}
	else if (clothcode == "CC" ) {cout << "Chinese Collar Polo ";}
	else if (clothcode == "PW" ) {cout << "White Slacks .......";}
	else if (clothcode == "RB" ) {cout << "Round Neck Blouse ..";}
	else if (clothcode == "S"  ) {cout << "Skirt ..............";}
	else if (clothcode == "VN" ) {cout << "V-Neck Polo ........";}
	else if (clothcode == "WP" ) {cout << "White Pants ........";}
	else if (clothcode == "IL" ) {cout << "ID Lace ............";}
	else if (clothcode == "PP" ) {cout << "PLM Pin ............";}
	else if (clothcode == "PPF") {cout << "PLM Patch (M) ......";}
	else if (clothcode == "PPM") {cout << "PLM Patch (F) ......";}
	else if (clothcode == "PR" ) {cout << "PLM Ribbon .........";}
	
		 if (sizecode == 1) { cout << " (Extra-Small) ......";}
	else if (sizecode == 2) { cout << " (Small) ............";}
	else if (sizecode == 3) { cout << " (Medium) ...........";}
	else if (sizecode == 4) { cout << " (Large) ............";}
	else if (sizecode == 5) { cout << " (X-Large) ..........";}
	else if (sizecode == 6) { cout << " (2X-Large) .........";}
	else if (sizecode == 7) { cout << " (3X-Large) .........";}
	else if (sizecode == 8) { cout << " (Add-ons) ..........";}
}

void invoiceDate( )
{
    time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
    cout << 1 + local_time->tm_mon<<"/"<<local_time->tm_mday <<"/"<< 1900 + local_time->tm_year ;
}

void receipt(string order[], int quantity)
{
	system("CLS");
	string dept;
	string itemcode;
	string clothcode;
	int sizecode;
	int price, stocks;
	int singlePrice=0;
	int totalPrice=0;
	
	cout << endl
		 << "  ======================== Item Ordered =======================" << endl
		//name
		 << "     Date: ";
	invoiceDate();
	cout << endl
		 << "   Item Description with Price" << endl
		 << "  -------------------------------------------------------------"<<endl;
	
	for(int i=0;i<quantity;i++)
	{	
		ifstream  clotheprice("clotheprice.txt");
			
		while(clotheprice>>dept>>itemcode>>clothcode>>sizecode>>price>>stocks)
		{
			if(order[i]==itemcode)
			{
			clothtypesize(clothcode, sizecode); 
			cout<<"..."<<"Php "<<price<<".00"<<endl;
			singlePrice=price;
			totalPrice+=singlePrice;
			}
		}
	}
	cout<<"  -------------------------------------------------------------"<<"\n"
		<<"\n"<<"     Total price: "<<"Php "<<totalPrice<<".00"<<"\n"
		<<"  ============================================================="<<endl
		<<"                This serves as your official receipt.           " << endl
		<<"           Email us at plmuniformshopfeedback@plm.edu.ph        " << endl
		<<"              Visit us also at www.plmuniformshop.com           " << endl
		<<"                   Thank you, please shop again.                " << endl;
}

string codeMaker(int clotheNum, int sizeNum) {
	system("CLS");
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
	int z;
	if (typeNum == 1) {
		switch (clotheNum) {
			case 1: z = 1; break; case 2: z = 2; break;
			case 3: z = 3; break; case 4: z = 4; break;
		}
	} else if (typeNum == 2) {
		switch (clotheNum) {
			case 1: z = 5; break; case 2: z = 6; break;
		}
	} else if (typeNum == 3) {
		switch (clotheNum) {
			case 1: z = 7; break; case 2: z = 8; break;
		}
	} else if (typeNum == 4) {
		switch (clotheNum) {
			case 1: z = 9; break; case 2: z = 10; break;
			case 3: z = 11; break; case 4: z = 12; break;
		}
	} else if (typeNum == 5) {
		switch (clotheNum) {
			case 1: z = 13; break; case 2: z = 14; break;
			case 3: z = 15; break; case 4: z = 16; break;
		}
	} else if (typeNum == 6) {
		switch (clotheNum) {
			case 1: z = 17; break; case 2: z = 18; break;
			case 3: z = 19; break; case 4: z = 20; break;
		}
	} else if (typeNum == 7) {
		switch (clotheNum) {
			case 1: z = 21; break; case 2: z = 22; break;
			case 3: z = 23; break; case 4: z = 24; break;
			case 5: z = 25; break;
		}
	}
	return z;
}

string numToClotheCode(int clotheNum) {
	string clotheCode;
	switch (clotheNum) {
		case 1 : clotheCode = "FB"; break; case 2 : clotheCode = "FS"; break; case 3 : clotheCode = "MP"; break;
		case 4 : clotheCode = "P" ; break; case 5 : clotheCode = "TS"; break; case 6 : clotheCode = "GS"; break;
		case 7 : clotheCode = "BL"; break; case 8 : clotheCode = "PA"; break; case 9 : clotheCode = "WB"; break;
		case 10: clotheCode = "PT"; break; case 11: clotheCode = "SC"; break; case 12: clotheCode = "WS"; break;
		case 13: clotheCode = "CL"; break; case 14: clotheCode = "PS"; break; case 15: clotheCode = "CC"; break;
		case 16: clotheCode = "PW"; break; case 17: clotheCode = "RB"; break; case 18: clotheCode = "S" ; break;
		case 19: clotheCode = "VN"; break; case 20: clotheCode = "WP"; break;
	}
	return clotheCode;
}

int sizeTypeMenu(int typeNum, int clotheNum) {
	
	char repeat;
	
	do {
		system("CLS");
		int cycle = 2, looper, count, sizePrice[8], price, bucket;
		int stocks[10], sizeNum , i = 1, itemSize, stocksInFile;
		string unifType, fullCode, itemCode, clotheCode;
	
		string sizeLoop[] = {"Extra Small", "   Small   ", "   Medium  ", "   Large   ", "Extra Large", "  2X Large ", "  3X Large "};
		string clotheLoop[] = {"Blouse", "Skirt", "Polo", "Pants", "T-Shirt", "Garterized Shorts", "Blouse", "Pants",
			"Plain White Blouse", "Pleats", "Sports Collar Polo", "White Slacks", "Collar-less Blouse", "Pencil Skirt",
			"Chinese Collar Polo", "White Slacks", "Round Neck Blouse", "Skirt", "V-Neck Polo", "White Pants"};
	
		if (clotheNum == 1 || clotheNum == 7 || clotheNum == 9 || clotheNum == 13 || clotheNum == 17) {
			looper = 5;
			sizePrice[2] = sizePrice[3] = sizePrice[4] = 370;
			sizePrice[5] = 380;
		} else if (clotheNum == 2 || clotheNum == 8 || clotheNum == 10 || clotheNum == 14 || clotheNum == 18) {
			cycle = 1;
			looper = 5;
			sizePrice[1] = sizePrice[2] = sizePrice[3] = sizePrice[4] = 300;
			sizePrice[5] = 310;		
		} else if (clotheNum == 3 || clotheNum == 11 || clotheNum == 15 || clotheNum == 19) {
			looper = 4;
			sizePrice[2] = sizePrice[3] = sizePrice[4] = 420;
		} else if (clotheNum == 4 || clotheNum == 12 || clotheNum == 16 || clotheNum == 20) {
			looper = 4;
			sizePrice[2] = sizePrice[3] = sizePrice[4] = 370;
		} else if (clotheNum == 5 || clotheNum == 6) {
			looper = 7;
			sizePrice[2] = sizePrice[3] = sizePrice[4] = 195;
			sizePrice[5] = 205; sizePrice[6] = 215; sizePrice[7] = 225;
		}
		cout << endl
			 << "  ============================================================" << endl
			 << setw(35) << clotheLoop[clotheNum - 1]  << endl
			 << "  ============================================================" << endl << endl
			 << "                       " << "Size" << "       " << "Price (Php)" << "  " << "Stocks" << endl;
		clotheCode = numToClotheCode(clotheNum);
		ifstream sizeMenuStocks("clotheprice.txt");
		while (sizeMenuStocks >> unifType >> fullCode >> itemCode >> itemSize >> price >> stocksInFile) {
			if (clotheCode == itemCode) {
				stocks[i] = stocksInFile;
				i += 1;
			}
		}
		sizeMenuStocks.close();
		for (count = 1; cycle <= looper; count += 1) {
			cout << setw(12) << "[" << count << "]" << "     " << sizeLoop[cycle - 1] << setw(9) << sizePrice[cycle] << ".00" << setw(9) << stocks[count] << endl;
			cycle += 1;
		}
		cout << setw(12) << "[" << count << "]" << "     " << "    Back   " << endl << endl
			 << "  =============================================================" << endl << endl	 
			 << "   Choose what size: ";
		cin >> sizeNum;
		if (sizeNum == count) {
			sizeNum = 10;
			return (sizeNum);
		} else if (sizeNum > count || sizeNum < 1) {
			cout << "Kindly choose among the choices." << endl
				 << endl << endl << "   ";
			system("pause");
			repeat = 'y';
		} else if (sizeNum < count || sizeNum > 0) {
			if (stocks[sizeNum] != 0) {
				return (sizeNum);
			} else {
				cout << "\n   ==============================================================\n"
					 << "\n               This Item is Temporarily Unavailable!\n"
					 << endl << endl << "   ";
				system("pause");
				repeat = 'y';
			}
		}
	}
	while(repeat == 'y');
}

int clotheTypeMenu(int typeNum) {
	system("CLS");
	int count, cycle;
	string unifType[10], clothe[10];

	switch (typeNum) {
		case 1:
			unifType[typeNum] = "Undergraduate Uniform";
			clothe[1] = "Blouse"; clothe[2] = "Skirt";
			clothe[3] = "Polo";	clothe[4] = "Pants";
			cycle = 4; break;
		case 2:
			unifType[typeNum] = "Physical Education Uniform";
			clothe[1] = "T-Shirt"; clothe[2] = "Garterized Shorts";
			cycle = 2; break;
		case 3:
			unifType[typeNum] = "Architecture Uniform";
			clothe[1] = "Blouse"; clothe[2] = "Pants";
			cycle = 2; break;
		case 4:
			unifType[typeNum] = "Physical Therapy Uniform";
			clothe[1] = "Plain White Blouse"; clothe[2] = "Pleats";
			clothe[3] = "Sport Collar Polo"; clothe[4] = "White Slacks";
			cycle = 4; break;
		case 5:
			unifType[typeNum] = "Psychology Uniform";
			clothe[1] = "Collarless Blouse"; clothe[2] = "Pencil Skirt";
			clothe[3] = "Chinese Collar Polo"; clothe[4] = "White Slacks";
			cycle = 4; break;
		case 6:
			unifType[typeNum] = "Medicine Uniform";
			clothe[1] = "Round Neck Blouse"; clothe[2] = "Skirt";
			clothe[3] = "V Neck Polo"; clothe[4] = "White Pants";
			cycle = 4; break;
	}
	cout << endl
		 << "  =============================================================" << endl
		 << setw(42) << unifType[typeNum] << endl
		 << "  =============================================================" << endl << endl
		 << setw(38) << "Items" << endl;
	for (count = 1; count <= cycle; count += 1) {
		cout << setw(24) << "[" << count << "]" << "       " << clothe[count] << endl;
	}
	cout << setw(24) << "[" << count << "]" << "       " << "Back" << endl << endl
		 << "  =============================================================" << endl << endl
		 << "   Choose item: ";
	return (count);
}

int addonsMenu() {
	char repeat;
	do {
		system("CLS");
		string unifType, fullCode, itemCode, price;
		int i = 0, itemSize, stocksInFile, stocks[5], clotheNum;
		ifstream addonsMenuStocks("clotheprice.txt");
		while (addonsMenuStocks >> unifType >> fullCode >> itemCode >> itemSize >> price >> stocksInFile) {
			if (unifType == "AO") {
				stocks[i] = stocksInFile;
				i += 1;
			}
		}
		addonsMenuStocks.close();
		cout << endl
			 << "  =============================================================" << endl
			 << setw(35) << "Add-ons" << endl
			 << "  =============================================================" << endl << endl	 
			 << setw(25) << "Item" << setw(19) << "Price (Php)" << "   " << "Stocks" << endl
			 << setw(12) << "[1]" << "     " << "   ID Lace   " << "      " << "75.00" << "        " << stocks[0] << endl
			 << setw(12) << "[2]" << "     " << "   PLM Pin   " << "      " << "50.00" << "        " << stocks[1] << endl
			 << setw(12) << "[3]" << "     " << "PLM Patch (F)" << "      " << "45.00" << "        " << stocks[2] << endl
			 << setw(12) << "[4]" << "     " << "PLM Patch (M)" << "      " << "50.00" << "        " << stocks[3] << endl
			 << setw(12) << "[5]" << "     " << " PLM Ribbon  " << "      " << "20.00" << "        " << stocks[4] << endl
			 << setw(12) << "[6]" << "     " << "    Back" << endl << endl
			 << "  =============================================================" << endl << endl 
			 << "   Choose item: ";
		cin >> clotheNum;
		if (clotheNum == 6) {
			clotheNum = 6;
			return (clotheNum);
		} else if (clotheNum > 6 || clotheNum < 1) {
			cout << "Kindly choose among the choices." << endl
				 << endl << endl << "   ";
			system("pause");
			repeat = 'y';
		} else if (clotheNum < 6 || clotheNum > 0) {
			if (stocks[clotheNum - 1] != 0) {
				return (clotheNum);
			} else {
				cout << "\n   =============================================================\n"
					 << "\n               This Item is Temporarily Unavailable!\n"
					 << endl << endl << "   ";
				system("pause");
				repeat = 'y';
			}
		}
	}
	while (repeat == 'y');
}

void uniTypeMenu() {
	
	char more;
	int typeNum, clotheNum, sizeNum, count;
	string order, bucket;
	
	system("CLS");
	cout << endl
		 << "  =============================================================" << endl
 		 << "                        PLM UNIFORM STORE " << endl
 		 << "  =============================================================" << endl << endl
		 << "                 [1] Undergraduate Uniform" << endl
		 << "                 [2] Physical Education Uniform" << endl 
		 << "                 [3] Architecture Uniform" << endl 
		 << "                 [4] Physical Therapy Uniform" << endl 
		 << "                 [5] Psychology Uniform" << endl 
		 << "                 [6] Medicine Uniform" << endl 
		 << "                 [7] Add-ons" << endl
		 << "                 [8] Cancel Transaction" << endl << endl
		 << "  =============================================================" << endl
		 << "   Choose item: ";
}

string mainMenu() {
	string order;
	int typeNum, clotheNum, sizeNum, count, repeater, i;
	
	do {
		uniTypeMenu();
		cin >> typeNum;
		if (typeNum > 8 || typeNum < 1) {
			cout << "Kindly choose among the choices." << endl;
			cout << endl << endl << "   ";
			system("pause");
		} else if (typeNum == 8) {
			system("CLS");
			cout << endl
				 << "  =============================================================" << endl << endl
				 << "                         Cancelling Order";
			for (i = 0; i < 3; i++) {
				Sleep(500);
				cout << ".";
			}
			system("CLS");
			cout << endl
				 << "  =============================================================" << endl << endl
				 << "                          Order Cancelled " << endl;
			order = "cancelled";
		} else if (typeNum == 7) {
			do {
				clotheNum = addonsMenu();
				if (clotheNum == 6) {
					typeNum = 10;
				} else if (clotheNum > 6 || clotheNum < 1) {
					cout << "Kindly choose among the choices." << endl;
					clotheNum = 0;
					cout << endl << endl << "   ";
					system("pause");
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
				cin >> clotheNum;
				repeater = clotheNum;
				if (clotheNum == count) {
					typeNum = 10;
				} else if (clotheNum > count || clotheNum < 1) {
					cout << "Kindly choose among the choices." << endl
						 << endl << endl << "   ";
					system("pause");
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

void inserFile(string fullname, string mobileNum, string address, string studentID, string orderToFile, int quantity) {
	ofstream toFile("database.txt", ios::app);
	toFile	<< endl << fullname
			<< endl << mobileNum
			<< endl << address
			<< endl << studentID
			<< endl << quantity
			<< endl << orderToFile
			<< endl;
	toFile.close();
	exit(0);
}

void gettingStocks(string order[], int quantity) {
	int stocks, itemSize, price, i;
	string unifType, itemCode, clotheCode;
	
	ifstream openFile("clotheprice.txt");
	ofstream newFile("newfile.txt");
	while(openFile >> unifType >> itemCode >> clotheCode >> itemSize >> price >> stocks) {
		for (i = 0; i < quantity; i++) {
			if (order[i] == itemCode) {
				stocks -= 1;
			}
		}
		newFile << unifType << " " << itemCode << " " << clotheCode << " " << itemSize << " " << price << " " << stocks << endl;
	}
	newFile.close();
	openFile.close();
	
	remove("clotheprice.txt");
	rename("newfile.txt", "clotheprice.txt");
}

void buyMenu(string fullname, string mobileNum, string address, string studentID) {
	
	int quantity = 0, i;
	string order[100], orderToFile;
	char more;
	
	do {
		system("CLS");
		cout << endl
			 << "  =============================================================" << endl << endl
			 << "                        Processing Menu";
		for (i = 0; i < 3; i++) {
			Sleep(500);
			cout << ".";
		}
		order[quantity] = mainMenu();
		if (order[quantity] == "cancelled") {
			if (quantity == 0) {
				exit(0);
			} else {
				more = 'n';
			}
		} else {
			quantity += 1;
			cout << endl
				 << "  =============================================================" << endl << endl
  				 << "             Would you like to purchase more? [Y/N]: ";
			cin >> more;
		}
	}
	while(more == 'Y' || more == 'y');
	system("CLS");
	cout << endl
		 << "  =============================================================" << endl << endl
		 << "                      Processing receipt";
	for (i = 0; i < 3; i++) {
		Sleep(500);
		cout << ".";
	}
	gettingStocks(order, quantity);
	receipt(order, quantity);
	for (int k = 0; k < quantity; k++) {
		orderToFile = order[k] + " " + orderToFile;
	}
	cout << endl << endl << "   ";
	system("pause");
	inserFile(fullname, mobileNum, address, studentID, orderToFile, quantity);
}
