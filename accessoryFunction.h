#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>
#include <ctime>
#include <iomanip>
using namespace std;

//define global variables

//Order variables
vector <string> vec_buyerName;
vector <string> vec_buyerPhoneNumber;
vector <string> vec_buyerAddress;
vector <string> vec_studentNumber;
vector <int> vec_numberOfItems;
vector <string> rawDressCode;
vector <string> vec_dateOfOrder;
vector <string> vec_dateName;
vector <string> vec_dateStudent;
vector <vector <string> > vec_DressCode;
    
//Inventory Variables
vector <string> vec_college;
vector <string> vec_dressCode;
vector <string> vec_dressType;
vector <string> vec_size;
vector <int> vec_price;
vector <int> vec_quantity;

//Account Variables
vector <string> vec_name;
vector <string> vec_address;
vector <string> vec_phoneNumber;
vector <string> vec_username;
vector <string> vec_password;

//Sales Variables
vector <string> vec_salesDressCode;


//Set Essential Variables
int consoleWidth = 120;
int consoleHeight = 30;
int widthBorder = 11;
int heightBorder = 2;
int upperx = widthBorder;
int uppery = heightBorder;
int lowerx = widthBorder;
int lowery = (consoleHeight - heightBorder) - 1;
int length;
int toPay;

using namespace std;

/*Declaration of Functions*/
void clrscr();
void pause();
void gotoxy(int x,int y);
void setColor(string backgroundColor,string textColor);
int searchArray(string arrayName[], string valueToFind);
void exitProgram();
int searchVector(vector<string> vector_name, string value);
void gridGuide();
void dotMaker();
void refreshVector(vector <string>& vectorName);
void loadingBar(string title);
void clearConsole();
void refreshIntVector(vector <int>& vectorName);
void splitPhrase(vector <vector <string> >& vec_DressCode);
string passwordMasker();



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Definition of Functions*/

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
	logUser("Logged Out");
	clrscr();
	setColor("B","LG");
	gotoxy(51,12);
	cout << "Exiting Program...";
	gotoxy(50,13);
	cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	gotoxy(50,14);
	cout << "³                       ³";
	gotoxy(50,15);
	cout << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
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

void dotMaker(){
    for (int i = 0 ; i <= 5 ; i++){
        cout << ".";
        Sleep(80);
    }
    cout << endl;
}

void refreshVector(vector <string>& vectorName){
	vectorName.clear();
}

void refreshIntVector(vector <int>& vectorName){
	vectorName.clear();
}

void loadingBar(string title){
	gotoxy(upperx + 18,uppery + 21);cout << title << "                              "; 
	gotoxy(upperx + 17,uppery + 22);cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	gotoxy(upperx + 17,uppery + 23);cout << "³                                                       ³";
	gotoxy(upperx + 17,uppery + 24);cout << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	for(int i = 29 ; i < 84 ; i++){
		gotoxy(i,25);cout << "Û";
		Sleep(60);
	}
	gotoxy(upperx + 18,uppery + 21);
	cout << "Completed!              ";
	pause();
	setColor("B","LW");
}

void clearConsole(){
	gotoxy(upperx + 2,uppery + 21);cout << "                                                                                        ";
	gotoxy(upperx + 2,uppery + 22);cout << "                                                                                        ";
	gotoxy(upperx + 2,uppery + 23);cout << "                                                                                        ";
	gotoxy(upperx + 2,uppery + 24);cout << "                                                                                        ";
}

void splitPhrase(vector <vector <string> >& vec_DressCode){
    vector <string> orderSegment;
        for (int i = 0 ; i < rawDressCode.size() ; i++){
            vector <string> orderSegment;
            string order = rawDressCode[i];
            string temp;
            int counter = 0;
            for(int i = 0 ; i < order.length() ; i++){
                string selector = order.substr(i,1);
                if (selector == " "){
                    int start = i - (counter);
                    temp = order.substr(start, counter);
                    orderSegment.push_back(temp);
                    i++;
                    counter = 0;
                }

                if (i == order.length() - 1){
                    int start = i - (counter);
                    temp = order.substr(start, counter + 1);
                    orderSegment.push_back(temp);
                    counter = 0;
                }
                counter ++;
            } 
            vec_DressCode.push_back(orderSegment);
        }
}

string passwordMasker(){
	int ch;
	string password;
	while (ch = getch()){
		if(ch == 13){
			break;
		}
		else if(ch == 8){
			if(password.length() > 0){
				cout << "\b \b";
				password.erase(password.length() - 1);
			} 
		}
		else{
				cout << "*";
				password+= ch;
		}
	}
	return password;
}

