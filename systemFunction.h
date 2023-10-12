#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>
#include <ctime>

using namespace std;
//Set Essential Coordinates
int consoleWidth = 120;
int consoleHeight = 30;
int widthBorder = 11;
int heightBorder = 2;
int upperx = widthBorder;
int uppery = heightBorder;
int lowerx = widthBorder;
int lowery = (consoleHeight - heightBorder) - 1;

/*Declaration of Functions*/

//Accessory Functions
void clrscr();
void pause();
void gotoxy(int x,int y);
void setColor(string backgroundColor,string textColor);
int searchArray(string arrayName[], string valueToFind);
void exitProgram();
int searchVector(vector<string> vector_name, string value);
void gridGuide();

//Design Functions
void displayBox(int title);
void mainPageHeader(int page);
void mainPageFooter(int page);
void mainPageBody();
void mainPageFull(int page);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Definition of Functions*/

//Accessory Functions
void clrscr(){
	system("CLS");
}

void pause(){
	system("pause");
}

void gotoxy(int x,int y){
	COORD orderedPair = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), orderedPair);
}

void setColor(string backgroundColor, string textColor){
	string arrBackgroundColor[16] = {"B","DB","DG","DC","DR","DP","DY","DW","G","LB","LG","LC","LR","LP","LY","LW"};
	string arrTextColor[16] = {"B","DB","DG","DC","DR","DP","DY","DW","G","LB","LG","LC","LR","LP","LY","LW"};
	int text = searchArray(arrTextColor,textColor);
	int background = searchArray(arrBackgroundColor,backgroundColor);
	int x = (background * 16) + text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

int searchArray(string arrayName[], string valueToFind){
	for (int i = 0 ; i < 16 ; i++){
		if(arrayName[i] == valueToFind){
			return i;
		}
	}
}

void exitProgram(){
	clrscr();
	setColor("B","LG");
	gotoxy(51,12);
	cout << "Exiting Program...";
	gotoxy(50,13);
	cout << "ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ";
	gotoxy(50,14);
	cout << "ณ                       ณ";
	gotoxy(50,15);
	cout << "ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู";
	for(int i = 51 ; i < 74 ; i++){
		gotoxy(i,14);
		cout << "Û";
		Sleep(65);
	}
	exit(0);
}

int searchVector(vector<string> vector_name, string value){
	for(int i = 0 ; i < vector_name.size() ; i++){
		if(vector_name[i] == value){
			return i;
		}
	}
	return -1;
}

void gridGuide(){
	int x = 0;
	int y = 0;
	gotoxy(upperx-1,uppery-1);cout<<"x";
	for(int i = upperx ; i <= 107 ; i++){
		gotoxy(i,uppery-1);
		cout << x;
		x++;
		if( x == 10){
			x = 0;
		}
	}
	for(int i = uppery ; i <= 27 ; i++){
		gotoxy(upperx - 1,i);
		cout << y;
		y++;
		if( y == 10){
			y = 0;
		}
	}
}

//Database Functions
void readDataSellerAccounts(vector <string>& vec_name , vector <string>& vec_address , vector <string>& vec_phoneNumber , vector <string>& vec_username , vector <string>& vec_password){
	ifstream in_database("databaseSellerAccounts.txt");
	sellerDetails accounts;
	while(!in_database.eof()){
        getline(in_database >> ws ,accounts.name);
        getline(in_database >> ws ,accounts.address);
        getline(in_database >> ws ,accounts.phoneNumber);
        getline(in_database >> ws ,accounts.username);
        getline(in_database >> ws ,accounts.password);
        
        vec_name.push_back(accounts.name);
        vec_address.push_back(accounts.address);
        vec_phoneNumber.push_back(accounts.phoneNumber);
        vec_username.push_back(accounts.username);
        vec_password.push_back(accounts.password);
    }
}

void writeDataUserLog(int vector_position,vector <string> vec_name,vector <string> vec_username,vector <string> vec_phoneNumber,string timestamp){
	ofstream out_userLog ("User_Log.csv",ios::app);
	out_userLog << vec_name[vector_position] << "," << vec_username[vector_position] << "," << vec_phoneNumber[vector_position] << "," << timestamp;
}
//Design Functions
void displayBox(int title){
	gridGuide();
	//prints the box
		for(int i = uppery ; i < uppery +25 ; i++){
			gotoxy(upperx,i);cout << "บ";
			gotoxy(upperx + 97,i);cout << "บ";
		}
		gotoxy(upperx,uppery);cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
		gotoxy(upperx,uppery + 2);cout << "ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน";
		gotoxy(upperx,uppery + 25);cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
		gotoxy(upperx + 1,uppery + 4);cout << "------------------------------------------------------------------------------------------------";
		gotoxy(upperx + 1,uppery + 20);cout << "------------------------------------------------------------------------------------------------";
	//Prints the page title
	gotoxy(12,3);
	if(title == 0){
		setColor("DB","LW");
		cout << "            -       S   E   L   L   E   R   S             M   E   N   U   -                     ";
	}
	else if(title == 1){
		setColor("DG","LW");
		cout << "              -       O   R   D   E   R   S             M   E   N   U       -                   ";
	}
	else if(title == 2){
		setColor("DP","LW");
		cout << "               -       S   A   L   E   S                  M   E   N   U   -                     ";
	}
	else if(title == 3){
		setColor("DY","LW");
		cout << "           -     I   N   V   E   N   T   O   R   Y           M   E   N   U   -                  ";
	}
	else if(title == 4){
		setColor("G","LW");
		cout << "           -      A   C   C   O   U   N   T   S            M   E   N   U   -                    ";
	}
	setColor("B","LW");
}

void mainPageHeader(int page){
	//seller mainheader
	if(page == 0){
		gotoxy(upperx + 15 ,uppery + 3);cout << "NO.";
		gotoxy(upperx + 42 ,uppery + 3);cout << "Menu Page";
		gotoxy(upperx + 76 ,uppery + 3);cout << "Function";
		
	}
	if (page == 4){
		gotoxy(upperx + 15 ,uppery + 3);cout << "NO.";
		gotoxy(upperx + 42 ,uppery + 3);cout << "Name";
		gotoxy(upperx + 76 ,uppery + 3);cout << "Username";
	}
}

void mainPageFooter(int page){
	//seller main footer
	if(page == 0){
		gotoxy(upperx + 22 ,uppery + 22);cout << "Please choose a menu in the selection: ";
	}
	if(page == 1){
		gotoxy(upperx + 28 ,uppery + 21);cout << "[1] Confirm Order";
		gotoxy(upperx + 28 ,uppery + 22);cout << "[2] View Order";
		gotoxy(upperx + 52 ,uppery + 21);cout << "[2] Back to Main Menu";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[3] Exit Program";
		gotoxy(upperx + 28 ,uppery + 24);cout << "Please choose a menu in the selection: ";
	}
	if(page == 2){
		gotoxy(upperx + 28 ,uppery + 21);cout << "[1] Save Sales";
		gotoxy(upperx + 28 ,uppery + 22);cout << "[2] Print Sales";
		gotoxy(upperx + 52 ,uppery + 21);cout << "[2] Back to Main Menu";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[3] Exit Program";
		gotoxy(upperx + 28 ,uppery + 24);cout << "Please choose a menu in the selection: ";
	}
	if(page == 3){
		gotoxy(upperx + 28 ,uppery + 21);cout << "[1] Add Stocks";
		gotoxy(upperx + 28 ,uppery + 22);cout << "[2] Remove Stocks";
		gotoxy(upperx + 52 ,uppery + 21);cout << "[2] Back to Main Menu";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[3] Exit Program";
		gotoxy(upperx + 28 ,uppery + 24);cout << "Please choose a menu in the selection: ";
	}
	if(page == 4){
		gotoxy(upperx + 28 ,uppery + 21);cout << "[1] Add Account";
		gotoxy(upperx + 28 ,uppery + 22);cout << "[2] Edit Account";
		gotoxy(upperx + 52 ,uppery + 21);cout << "[2] Back to Main Menu";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[3] Exit Program";
		gotoxy(upperx + 28 ,uppery + 24);cout << "Please choose a menu in the selection: ";
	}
}

void mainPageBody(){
		//Display Function Column
		gotoxy(upperx + 74 ,uppery + 5);cout << "Confirm Order";
		gotoxy(upperx + 74 ,uppery + 6);cout << "Edit  Order";
		gotoxy(upperx + 74 ,uppery + 7);cout << "Delete Order";
		gotoxy(upperx + 74 ,uppery + 9);cout << "Save  Sales";
		gotoxy(upperx + 74 ,uppery + 10);cout << "Edit  Sales";
		gotoxy(upperx + 74 ,uppery + 12);cout << "Add  Stocks";
		gotoxy(upperx + 74 ,uppery + 13);cout << "Remove  Stocks";
		gotoxy(upperx + 74 ,uppery + 15);cout << "Add Account";
		gotoxy(upperx + 74 ,uppery + 16);cout << "Edit Account";
		gotoxy(upperx + 74 ,uppery + 17);cout << "Delete Account";
		gotoxy(upperx + 74 ,uppery + 19);cout << "þþþþþþþþþþþþþ";
		
		//Display Menu Page Column
		setColor("B","DY");
		gotoxy(upperx + 41 ,uppery + 5);cout << "Order Menu";
		gotoxy(upperx + 41 ,uppery + 9);cout << "Sales Menu";
		gotoxy(upperx + 41 ,uppery + 12);cout << "Stocks Menu";
		gotoxy(upperx + 41 ,uppery + 15);cout << "Accounts Menu";
		gotoxy(upperx + 41 ,uppery + 19);cout << "Exit Program";
		setColor("B","LW");
		
		//Display the No. Column
		gotoxy(upperx + 15 ,uppery + 5);cout << "[1]";
		gotoxy(upperx + 15 ,uppery + 9);cout << "[2]";
		gotoxy(upperx + 15 ,uppery + 12);cout << "[3]";
		gotoxy(upperx + 15 ,uppery + 15);cout << "[4]";
		gotoxy(upperx + 15 ,uppery + 19);cout << "[5]";		
}

void mainPageFull(int page){
	if(page == 0){
		displayBox(0);
		mainPageHeader(0);
		mainPageFooter(0);
		mainPageBody();
	}
	if(page == 1){
		displayBox(1);
		mainPageHeader(1);
		mainPageFooter(1);
	}
	if(page == 2){
		displayBox(2);
		mainPageHeader(2);
		mainPageFooter(2);
	}
	if(page == 3){
		displayBox(3);
		mainPageHeader(3);
		mainPageFooter(3);
	}
	if(page == 4){
		displayBox(4);
		mainPageHeader(4);
		mainPageFooter(4);
	}
}
