#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

//--------------------------< Others >-----------------------------------------

void back(string input, int x);

void invoiceDate()
{
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	cout << 1 + local_time->tm_mon << "/" << local_time->tm_mday << "/" << 1900 + local_time->tm_year;
}

void invoiceTime()
{
	int hour, min;
	string type = "AM";
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	hour = local_time->tm_hour;
	min = local_time->tm_min;
	if (hour > 11)
	{
		if (hour != 12)
		{
			hour -= 12;
		}
		type = "PM";
	}
	if (min < 10)
	{
		cout << hour << ":0" << min << " " << type;
	} else
	{
   		cout << hour << ":" << min << " " << type;
    }
    
}

void got(int x, int y)
{
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

//--------------------------< Menus >------------------------------------------

void WelcomeMessage ()
{
	system("CLS");
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
		 << "\n\t\t\t" << "�                       PLM UNIFORM STORE                       �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�      � � ��� �   ��� �ͻ �˻ ���   ��� �ͻ   ��� � � ���      �"
		 << "\n\t\t\t" << "�      �Һ ��  �   �   � � �к ��     �  � �    �  �͹ ��       �"
		 << "\n\t\t\t" << "�      �ʼ ��� ��� ��� �ͼ � � ���    �  �ͼ    �  � � ���      �"
		 << "\n\t\t\t" << "�   �ͻ �   �˻   � � �ͻ � ��� �ͻ �ͻ  �˻   ��� � � �ͻ �ͻ  �"
		 << "\n\t\t\t" << "�   �ͼ �   �к   � � � � � ��� � � ��ʻ �к   �ͻ �͹ � � �ͼ  �"
		 << "\n\t\t\t" << "�   �   ��� � �   �ͼ � � � �   �ͼ �  � � �   �ͼ � � �ͼ �    �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�        [1]  Create Account                                    �"
		 << "\n\t\t\t" << "�        [2]  Search Account                                    �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
}

void SearchAcctMenu ()
{
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
 		 << "\n\t\t\t" << "�                       PLM UNIFORM STORE                       �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�       [1]     Buy Again                                       �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�       [2]     See History                                     �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�       [3]     Exit                                            �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
}

//--------------------------< Idle Screens >-----------------------------------

void emptySpace()
{
	system("CLS");
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
 		 << "\n\t\t\t" << "�                       PLM UNIFORM STORE                       �"
 		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �"
 		 << "\n\t\t\t" << "�                                                               �";
}

void AcctFndMsg ()
{
	got(25, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                  Account Successfully Found!                  �"
		 << "\n\t\t\t" << "�               Please press any key to continue                �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(72, 16);
	system("pause > nul");
}

void AcctNotFndMsg ()
{
	got(25, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                      Account Not Found!                       �"
		 << "\n\t\t\t" << "�                  Press any key to try again                   �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(69, 16);
	system("pause > nul");
}

void otherOption()
{
	got(25, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�             Kindly Choose Among the Given Options             �"
		 << "\n\t\t\t" << "�                  Press any key to try again                   �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(69, 16);
	system("pause > nul");
}

void emptyOption()
{
	got(25, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                         Invalid Input                         �"
		 << "\n\t\t\t" << "�                  Press any key to try again                   �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(69, 16);
	system("pause > nul");
}

void itemUnavailible()
{
	got(25, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                 Item is Currently Unavailable                 �"
		 << "\n\t\t\t" << "�                  Press any key to try again                   �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(69, 16);
	system("pause > nul");
}

void purchaseMore()
{
	emptySpace();
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
	 	 << "\n\t\t\t" << "�             Would you like to purchase more?[Y/N]             �"
	 	 << "\n\t\t\t" << "�  User Input:                                                  �"
	 	 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
}

//--------------------------< Loading Screens >--------------------------------

void processMenu()
{
	int i = 63;
	emptySpace();
	got(25, 13);            
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                        Processing Menu                        �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
}

void CreateAcctLoadMsg()
{
	int i = 63;
	
	got(25, 13);	                 							    
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                       Creating Account                        �"		 	
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
}

void ProcessAcctLoadMsg()
{
	int i = 63;
	got(25, 13);				   								                      
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                       Processing Account                      �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
}

void HstryLoadMsg()
{
	int i = 63;
	got(25, 13);				   										           
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                  Loading Transaction History                  �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
}

void ExitMsg ()
{
	int i = 63;
	got(25, 13);		   					
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                        Exiting Program                        �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
	cout << "\n\n\n\n\n";
	got(25, 13);				  							                
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                        Program Closed                         �"
		 << "\n\t\t\t" << "�                     Please press any key                      �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(66, 16);
	system("pause > nul");
}

void loadingMessage() 
{
	int i = 63;
	emptySpace();
	got(25, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                            Loading                            �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
}

void cancelOrder()
{
	int i = 63;
	got(25, 13); 
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                      Ending Transaction                       �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
	got(25, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                       Transaction Ended                       �"
		 << "\n\t\t\t" << "�                     Please press any key                      �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(66, 16);
	system("pause > nul");
}

void processReceipt()
{
	int i = 63;
	got(25, 13);					      								                  
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                      Processing Receipt                       �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "�";
		Sleep(30);
		j++;
	}
}

//--------------------------< Clothe Menus >-----------------------------------

void uniTypeMenu()
{
	system("CLS");
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
 		 << "\n\t\t\t" << "�                       PLM UNIFORM STORE                       �"
 		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�       [1]          Undergraduate Uniform                      �"
		 << "\n\t\t\t" << "�       [2]          Physical Education Uniform                 �"
		 << "\n\t\t\t" << "�       [3]          Architecture Uniform                       �"
		 << "\n\t\t\t" << "�       [4]          Physical Therapy Uniform                   �"
		 << "\n\t\t\t" << "�       [5]          Psychology Uniform                         �"
		 << "\n\t\t\t" << "�       [6]          Medicine Uniform                           �"
		 << "\n\t\t\t" << "�       [7]          Add-ons                                    �"
		 << "\n\t\t\t" << "�       [8]          End Transaction                            �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
}

int clotheTypeMenu(int typeNum) {
	system("CLS");
	int count, cycle, spaces = 3;
	string unifType[10], clothe[10];

	switch (typeNum) {
		case 1:
			unifType[typeNum] = "  Undergraduate Uniform   ";
			clothe[1] = "       Blouse      "; clothe[2] = "       Skirt       ";
			clothe[3] = "        Polo       "; clothe[4] = "       Pants       ";
			cycle = 4; break;
		case 2:
			unifType[typeNum] = "Physical Education Uniform";
			clothe[1] = "      T-Shirt      "; clothe[2] = " Garterized Shorts ";
			cycle = 2; spaces = 5; break;
		case 3:
			unifType[typeNum] = "   Architecture Uniform   ";
			clothe[1] = "       Blouse      "; clothe[2] = "       Pants       ";
			cycle = 2; spaces = 5; break;
		case 4:
			unifType[typeNum] = " Physical Therapy Uniform ";
			clothe[1] = " Plain White Blouse"; clothe[2] = "       Pleats      ";
			clothe[3] = " Sports Collar Polo"; clothe[4] = "    White Slacks   ";
			cycle = 4; break;
		case 5:
			unifType[typeNum] = "    Psychology Uniform    ";
			clothe[1] = " Collar-less Blouse"; clothe[2] = "    Pencil Skirt   ";
			clothe[3] = "Chinese Collar Polo"; clothe[4] = "    White Slacks   ";
			cycle = 4; break;
		case 6:
			unifType[typeNum] = "    Medicine Uniform      ";
			clothe[1] = " Round Neck Blouse "; clothe[2] = "       Skirt       ";
			clothe[3] = "     V-Neck Polo   "; clothe[4] = "    White Pants    ";
			cycle = 4; break;
	}
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
		 << "\n\t\t\t" << "�                    " << unifType[typeNum] << "                 �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                       Item                                    �";
	for (count = 1; count <= cycle; count += 1) {
		cout << "\n\t\t\t" << "�       [" << count << "]     " << clothe[count] << "                             �";
	}
	cout << "\n\t\t\t" << "�       [" << count << "]             Back                                    �";
	while (spaces > 0)
	{
		cout << "\n\t\t\t" << "�                                                               �";
		spaces -= 1;
	}
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
	return (count);
}

void addons(int stocks[], int prices[])
{
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
		 << "\n\t\t\t" << "�                            Add-ons                            �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                   Item        Price (Php)     Stocks          �"
		 << "\n\t\t\t" << "�       [1]        ID Lace        " << prices[0] << ".00  \t  " << stocks[0] << "     \t�"
		 << "\n\t\t\t" << "�       [2]        PLM Pin        " << prices[1] << ".00  \t  " << stocks[1] << "     \t�"
		 << "\n\t\t\t" << "�       [3]     PLM Patch (M)     " << prices[2] << ".00  \t  " << stocks[2] << "     \t�"
		 << "\n\t\t\t" << "�       [4]     PLM Patch (F)     " << prices[3] << ".00  \t  " << stocks[3] << "     \t�"
		 << "\n\t\t\t" << "�       [5]       PLM Ribbon      " << prices[4] << ".00  \t  " << stocks[4] << "     \t�"
		 << "\n\t\t\t" << "�       [6]         Back                                        �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
}

void sizeMenuTop(int clotheNum)
{
	string clotheLoop[] = {
		"       Blouse      ", "       Skirt       ", "       Polo        ", "       Pants       ", "      T-Shirt      ",
		" Garterized Shorts ", "       Blouse      ", "       Pants       ", " Plain White Blouse", "       Pleats      ",
		" Sports Collar Polo", "    White Slacks   ", " Collar-less Blouse", "    Pencil Skirt   ", "Chinese Collar Polo",
		"    White Slacks   ", " Round Neck Blouse ", "       Skirt       ", "     V-Neck Polo   ", "    White Pants    "};
			
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
		 << "\n\t\t\t" << "�                      " << clotheLoop[clotheNum - 1]  << "                      �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                   Size        Price (Php)     Stocks          �";
}

int sizeMenuBottom(int stocks[], int prices[], int cycle, int looper, int spaces)
{
	int count;
	
	string sizeLoop[] = {"Extra Small", "   Small   ", "  Medium   ", "   Large   ", "Extra Large", " 2X Large  ", " 3X Large  "};
	
	for (count = 1; cycle <= looper; count += 1) {
	cout << "\n\t\t\t" << "�       [" << count << "]      " << sizeLoop[cycle - 1] << "      " << prices[count] << ".00" << "  \t  " << stocks[count] << "\t        �";
		cycle += 1;
	}
	cout << "\n\t\t\t" << "�       [" << count << "]         Back                                        �";
	while (spaces > 0)
	{
		cout << "\n\t\t\t" << "�                                                               �";
		spaces -= 1;
	}
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
	return count;
}

//--------------------------< Information Processes >--------------------------

string nameInput(int x) 
{
	string fullname;
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
		 << "\n\t\t\t" << "�               To go back, Press 'x' then enter.               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  Enter Fullname        :                                      �"
		 << "\n\t\t\t" << "�                                                               �";
	if (x == 1)
	{
	cout << "\n\t\t\t" << "�  Enter Student ID      :                                      �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�                                                               �";
	} else if (x == 0)
	{
	cout << "\n\t\t\t" << "�  Enter Phone Number    :                                      �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  Enter Address (Street):                                      �"
		 << "\n\t\t\t" << "�                 (City) :                                      �"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�  Enter Student ID      :                                      �";
	}
	cout << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�       Enter Fullname: (First, Middle Initial, Last)           �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
	getline(cin, fullname);
	back(fullname, 1);
	got(51, 5);
	cout << fullname;
	return fullname;
}

string numberInput() 
{
	string mobileNum, y, one, two;
	int x;
	got(50, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�       Enter Phone Number : (Required)                         �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
	getline(cin, mobileNum);
	back(mobileNum, 1);
	x = mobileNum.length();
	one = mobileNum[0];
	two = mobileNum[1];
	if (x > 11 || x < 11 || one != "0" || two != "9")
	{
		emptyOption();
		numberInput();
	} else {
		x -= 1;
		while (x >= 0)
		{
			y = mobileNum[x];
			if (y == "1" || y == "2" || y == "3" || y == "4" || y == "5"
			|| y == "6" || y == "7" || y == "8" || y == "9" || y == "0")
			{
				if (x == 0)
				{
					got(51, 7);
					cout << mobileNum;
					return mobileNum;
				}
			} else {
				emptyOption();
				numberInput();
			}
			x -= 1;
		}
	}
}

string homeInput() 
{
	string address, addressone, addresstwo;
	got(50, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�       Enter Address      : (House Number, Street)             �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
	getline(cin, addressone);
	got(51, 9);
	cout << addressone;
	got(50, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�       Enter Address      : (City)                             �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
	getline(cin, addresstwo);
	got(51, 10);
	cout << addresstwo;
	address = addressone + ", " + addresstwo;
	back(address, 1);
	return address;
}

string idInput(int x) 
{
	int z;
	string studentID, y;
	got(50, 13);
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�       Enter Student ID   : (Officially given by the school)   �"
		 << "\n\t\t\t" << "�  User Input:                                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
	got(39, 16);
	getline(cin, studentID);
	back(studentID, 1);
	z = studentID.length();
	if (z > 9 || z < 9)
	{
		emptyOption();
		idInput(x);
	
	}
	z -= 1;
	while (z >= 0)
	{
		y = studentID[z];
		if (y == "1" || y == "2" || y == "3" || y == "4" || y == "5"
		|| y == "6" || y == "7" || y == "8" || y == "9" || y == "0")
		{
			if (z == 0)
			{
				if (x == 1)
				{	
					got(51, 7);
					cout << studentID;
					return studentID;
				} else if (x == 0)
				{
					got(51, 12);
					cout << studentID;
					return studentID;
				}
			}
		} else {
			emptyOption();
			idInput(x);
		}
		z -= 1;
	}
}

//--------------------------< Receipt and History >----------------------------

void clotheTypeSize(string itemCode, int itemSize)
{
		 if (itemCode == "FB" ) {cout << "Blouse .............";}
	else if (itemCode == "FS" ) {cout << "Skirt ..............";}
	else if (itemCode == "MP" ) {cout << "Polo ...............";}
	else if (itemCode == "P"  ) {cout << "Pants ..............";}
	else if (itemCode == "TS" ) {cout << "T-Shirt ............";}
	else if (itemCode == "GS" ) {cout << "Garterized Shorts ..";}
	else if (itemCode == "BL" ) {cout << "Blouse .............";}
	else if (itemCode == "PA" ) {cout << "Pants ..............";}
	else if (itemCode == "WB" ) {cout << "Plain White Blouse .";}
	else if (itemCode == "PT" ) {cout << "Pleats .............";}
	else if (itemCode == "SC" ) {cout << "Sports Collar Polo .";}
	else if (itemCode == "WS" ) {cout << "White Slacks .......";}
	else if (itemCode == "CL" ) {cout << "Collar-less Blouse .";}
	else if (itemCode == "PS" ) {cout << "Pencil Skirt .......";}
	else if (itemCode == "CC" ) {cout << "Chinese Collar Polo ";}
	else if (itemCode == "PW" ) {cout << "White Slacks .......";}
	else if (itemCode == "RB" ) {cout << "Round Neck Blouse ..";}
	else if (itemCode == "S"  ) {cout << "Skirt ..............";}
	else if (itemCode == "VN" ) {cout << "V-Neck Polo ........";}
	else if (itemCode == "WP" ) {cout << "White Pants ........";}
	else if (itemCode == "IL" ) {cout << "ID Lace ............";}
	else if (itemCode == "PP" ) {cout << "PLM Pin ............";}
	else if (itemCode == "PPF") {cout << "PLM Patch (M) ......";}
	else if (itemCode == "PPM") {cout << "PLM Patch (F) ......";}
	else if (itemCode == "PR" ) {cout << "PLM Ribbon .........";}
	
		 if (itemSize == 1) { cout << " (Extra-Small) ...";}
	else if (itemSize == 2) { cout << " (Small) .........";}
	else if (itemSize == 3) { cout << " (Medium) ........";}
	else if (itemSize == 4) { cout << " (Large) .........";}
	else if (itemSize == 5) { cout << " (X-Large) .......";}
	else if (itemSize == 6) { cout << " (2X-Large) ......";}
	else if (itemSize == 7) { cout << " (3X-Large) ......";}
	else if (itemSize == 8) { cout << " (Add-ons) .......";}
}

void line()
{
	cout << "\n\t\t\t" << "�  -----------------------------------------------------------\t�";
}

void topReceipt()
{
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
		 << "\n\t\t\t" << "�                       PLM UNIFORM SHOP                        �"
   		 << "\n\t\t\t" << "�        Gen. Luna corner Muralla St. Intramuros, Manila        �"
 		 << "\n\t\t\t" << "���������������������������������������������������������������͹" 
 		 << "\n\t\t\t" << "�                     Customer Information                      �"
		 << "\n\t\t\t" << "�  Student Name     :                                           �"
		 << "\n\t\t\t" << "�  Student Number   :                                           �"
		 << "\n\t\t\t" << "�  Phone Number     :                                           �"
		 << "\n\t\t\t" << "�  Address/Location :                                           �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�  Date: ";
	invoiceDate();
	cout << "\t\t\t\tTime: ";
	invoiceTime();
	cout << "	�"
	 	 << "\n\t\t\t" << "���������������������������������������������������������������͹" 
		 << "\n\t\t\t" << "�                         Item Ordered                          �"
	     << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�  Item Description with Price                                  �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹";
}

void bottomReceipt(int totalPrice, string fullname, string mobileNum, string address, string studentID)
{
	cout << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�  Total price: " << "Php " << totalPrice << ".00\t                                �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�             This serves as your official receipt.             �"
		 << "\n\t\t\t" << "�         Email us at plmuniformshopfeedback@plm.edu.ph         �"
		 << "\n\t\t\t" << "�            Visit us also at www.plmuniformshop.com            �"
		 << "\n\t\t\t" << "�                 Thank you, please shop again.                 �"
		 << "\n\t\t\t" << "�                 Please press any key to exit.                 �"
		 << "\n\t\t\t" <<"���������������������������������������������������������������ͼ";
	got(46, 6);
	cout << fullname;
	got(46, 7);
	cout << studentID;
	got(46, 8);
	cout << mobileNum;
	got(46, 9);
	cout << address;
	got(1, 1);
	system("pause > nul");
}

void historyTransactions()
{
	cout << "\n\t\t\t" << "���������������������������������������������������������������ͻ"
		 << "\n\t\t\t" << "�                       PLM UNIFORM SHOP                        �"
   		 << "\n\t\t\t" << "�        Gen. Luna corner Muralla St. Intramuros, Manila        �"
 		 << "\n\t\t\t" << "���������������������������������������������������������������͹" 
 		 << "\n\t\t\t" << "�                 TRANSCRIPT OF HISTORY RECORDS                 �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�                     Customer Information                      �"
		 << "\n\t\t\t" << "�  Student Name   :                                             �"
		 << "\n\t\t\t" << "�  Student Number :                                             �"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹"
		 << "\n\t\t\t" << "�  Date: ";
	invoiceDate();
	cout << "\t\t\t\tTime: ";
	invoiceTime();
	cout << "	�"
		 << "\n\t\t\t" << "���������������������������������������������������������������͹";
}

void totalPrice(int priceSum)
{
	cout << "\n\t\t\t" << "�  ------------------------------------ Total - Php " << priceSum << ".00" << "\t�"
		 << "\n\t\t\t" << "� ============================================================= �";
}

void allTotal(int overallTotal)
{
	cout << "\n\t\t\t" << "�  ---------------------------- Overall Total - Php " << overallTotal << ".00" << "\t�"
		 << "\n\t\t\t" << "�                                                               �"
		 << "\n\t\t\t" << "�               Please press any key to continue                �"
		 << "\n\t\t\t" << "���������������������������������������������������������������ͼ";
}
