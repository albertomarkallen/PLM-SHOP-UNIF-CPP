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
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
		 << "\n\t\t\t" << "บ                       PLM UNIFORM STORE                       บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ      า า ษออ า   ษออ ษอป ษหป ษออ   อหอ ษอป   อหอ า า ษออ      บ"
		 << "\n\t\t\t" << "บ      บาบ ฬอ  บ   บ   บ บ บะบ ฬอ     บ  บ บ    บ  ฬอน ฬอ       บ"
		 << "\n\t\t\t" << "บ      ศสผ ศออ ศออ ศออ ศอผ ะ ะ ศออ    ะ  ศอผ    ะ  ะ ะ ศออ      บ"
		 << "\n\t\t\t" << "บ   ษอป า   ษหป   า า ษอป า ษออ ษอป ษอป  ษหป   ษออ า า ษอป ษอป  บ"
		 << "\n\t\t\t" << "บ   ฬอผ บ   บะบ   บ บ บ บ บ ฬออ บ บ ฬอสป บะบ   ศอป ฬอน บ บ ฬอผ  บ"
		 << "\n\t\t\t" << "บ   ะ   ศออ ะ ะ   ศอผ ะ ะ ะ ะ   ศอผ ะ  ะ ะ ะ   ออผ ะ ะ ศอผ ะ    บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ        [1]  Create Account                                    บ"
		 << "\n\t\t\t" << "บ        [2]  Search Account                                    บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(39, 16);
}

void SearchAcctMenu ()
{
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
 		 << "\n\t\t\t" << "บ                       PLM UNIFORM STORE                       บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ       [1]     Buy Again                                       บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ       [2]     See History                                     บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ       [3]     Exit                                            บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
}

//--------------------------< Idle Screens >-----------------------------------

void emptySpace()
{
	system("CLS");
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
 		 << "\n\t\t\t" << "บ                       PLM UNIFORM STORE                       บ"
 		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ"
 		 << "\n\t\t\t" << "บ                                                               บ";
}

void AcctFndMsg ()
{
	got(25, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                  Account Successfully Found!                  บ"
		 << "\n\t\t\t" << "บ               Please press any key to continue                บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(72, 16);
	system("pause > nul");
}

void AcctNotFndMsg ()
{
	got(25, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                      Account Not Found!                       บ"
		 << "\n\t\t\t" << "บ                  Press any key to try again                   บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(69, 16);
	system("pause > nul");
}

void otherOption()
{
	got(25, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ             Kindly Choose Among the Given Options             บ"
		 << "\n\t\t\t" << "บ                  Press any key to try again                   บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(69, 16);
	system("pause > nul");
}

void emptyOption()
{
	got(25, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                         Invalid Input                         บ"
		 << "\n\t\t\t" << "บ                  Press any key to try again                   บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(69, 16);
	system("pause > nul");
}

void itemUnavailible()
{
	got(25, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                 Item is Currently Unavailable                 บ"
		 << "\n\t\t\t" << "บ                  Press any key to try again                   บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(69, 16);
	system("pause > nul");
}

void purchaseMore()
{
	emptySpace();
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
	 	 << "\n\t\t\t" << "บ             Would you like to purchase more?[Y/N]             บ"
	 	 << "\n\t\t\t" << "บ  User Input:                                                  บ"
	 	 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(39, 16);
}

//--------------------------< Loading Screens >--------------------------------

void processMenu()
{
	int i = 63;
	emptySpace();
	got(25, 13);            
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                        Processing Menu                        บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
}

void CreateAcctLoadMsg()
{
	int i = 63;
	
	got(25, 13);	                 							    
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                       Creating Account                        บ"		 	
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
}

void ProcessAcctLoadMsg()
{
	int i = 63;
	got(25, 13);				   								                      
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                       Processing Account                      บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
}

void HstryLoadMsg()
{
	int i = 63;
	got(25, 13);				   										           
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                  Loading Transaction History                  บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
}

void ExitMsg ()
{
	int i = 63;
	got(25, 13);		   					
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                        Exiting Program                        บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
	cout << "\n\n\n\n\n";
	got(25, 13);				  							                
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                        Program Closed                         บ"
		 << "\n\t\t\t" << "บ                     Please press any key                      บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(66, 16);
	system("pause > nul");
}

void loadingMessage() 
{
	int i = 63;
	emptySpace();
	got(25, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                            Loading                            บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
}

void cancelOrder()
{
	int i = 63;
	got(25, 13); 
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                      Ending Transaction                       บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
	got(25, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                       Transaction Ended                       บ"
		 << "\n\t\t\t" << "บ                     Please press any key                      บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(66, 16);
	system("pause > nul");
}

void processReceipt()
{
	int i = 63;
	got(25, 13);					      								                  
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                      Processing Receipt                       บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	int j = 0;
	got(25, 16);
	while (i > j)
	{		
		cout << "þ";
		Sleep(30);
		j++;
	}
}

//--------------------------< Clothe Menus >-----------------------------------

void uniTypeMenu()
{
	system("CLS");
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
 		 << "\n\t\t\t" << "บ                       PLM UNIFORM STORE                       บ"
 		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ       [1]          Undergraduate Uniform                      บ"
		 << "\n\t\t\t" << "บ       [2]          Physical Education Uniform                 บ"
		 << "\n\t\t\t" << "บ       [3]          Architecture Uniform                       บ"
		 << "\n\t\t\t" << "บ       [4]          Physical Therapy Uniform                   บ"
		 << "\n\t\t\t" << "บ       [5]          Psychology Uniform                         บ"
		 << "\n\t\t\t" << "บ       [6]          Medicine Uniform                           บ"
		 << "\n\t\t\t" << "บ       [7]          Add-ons                                    บ"
		 << "\n\t\t\t" << "บ       [8]          End Transaction                            บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
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
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
		 << "\n\t\t\t" << "บ                    " << unifType[typeNum] << "                 บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                       Item                                    บ";
	for (count = 1; count <= cycle; count += 1) {
		cout << "\n\t\t\t" << "บ       [" << count << "]     " << clothe[count] << "                             บ";
	}
	cout << "\n\t\t\t" << "บ       [" << count << "]             Back                                    บ";
	while (spaces > 0)
	{
		cout << "\n\t\t\t" << "บ                                                               บ";
		spaces -= 1;
	}
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(39, 16);
	return (count);
}

void addons(int stocks[], int prices[])
{
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
		 << "\n\t\t\t" << "บ                            Add-ons                            บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                   Item        Price (Php)     Stocks          บ"
		 << "\n\t\t\t" << "บ       [1]        ID Lace        " << prices[0] << ".00  \t  " << stocks[0] << "     \tบ"
		 << "\n\t\t\t" << "บ       [2]        PLM Pin        " << prices[1] << ".00  \t  " << stocks[1] << "     \tบ"
		 << "\n\t\t\t" << "บ       [3]     PLM Patch (M)     " << prices[2] << ".00  \t  " << stocks[2] << "     \tบ"
		 << "\n\t\t\t" << "บ       [4]     PLM Patch (F)     " << prices[3] << ".00  \t  " << stocks[3] << "     \tบ"
		 << "\n\t\t\t" << "บ       [5]       PLM Ribbon      " << prices[4] << ".00  \t  " << stocks[4] << "     \tบ"
		 << "\n\t\t\t" << "บ       [6]         Back                                        บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(39, 16);
}

void sizeMenuTop(int clotheNum)
{
	string clotheLoop[] = {
		"       Blouse      ", "       Skirt       ", "       Polo        ", "       Pants       ", "      T-Shirt      ",
		" Garterized Shorts ", "       Blouse      ", "       Pants       ", " Plain White Blouse", "       Pleats      ",
		" Sports Collar Polo", "    White Slacks   ", " Collar-less Blouse", "    Pencil Skirt   ", "Chinese Collar Polo",
		"    White Slacks   ", " Round Neck Blouse ", "       Skirt       ", "     V-Neck Polo   ", "    White Pants    "};
			
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
		 << "\n\t\t\t" << "บ                      " << clotheLoop[clotheNum - 1]  << "                      บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                   Size        Price (Php)     Stocks          บ";
}

int sizeMenuBottom(int stocks[], int prices[], int cycle, int looper, int spaces)
{
	int count;
	
	string sizeLoop[] = {"Extra Small", "   Small   ", "  Medium   ", "   Large   ", "Extra Large", " 2X Large  ", " 3X Large  "};
	
	for (count = 1; cycle <= looper; count += 1) {
	cout << "\n\t\t\t" << "บ       [" << count << "]      " << sizeLoop[cycle - 1] << "      " << prices[count] << ".00" << "  \t  " << stocks[count] << "\t        บ";
		cycle += 1;
	}
	cout << "\n\t\t\t" << "บ       [" << count << "]         Back                                        บ";
	while (spaces > 0)
	{
		cout << "\n\t\t\t" << "บ                                                               บ";
		spaces -= 1;
	}
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(39, 16);
	return count;
}

//--------------------------< Information Processes >--------------------------

string nameInput(int x) 
{
	string fullname;
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
		 << "\n\t\t\t" << "บ               To go back, Press 'x' then enter.               บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  Enter Fullname        :                                      บ"
		 << "\n\t\t\t" << "บ                                                               บ";
	if (x == 1)
	{
	cout << "\n\t\t\t" << "บ  Enter Student ID      :                                      บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ                                                               บ";
	} else if (x == 0)
	{
	cout << "\n\t\t\t" << "บ  Enter Phone Number    :                                      บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  Enter Address (Street):                                      บ"
		 << "\n\t\t\t" << "บ                 (City) :                                      บ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ  Enter Student ID      :                                      บ";
	}
	cout << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ       Enter Fullname: (First, Middle Initial, Last)           บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
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
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ       Enter Phone Number : (Required)                         บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
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
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ       Enter Address      : (House Number, Street)             บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	got(39, 16);
	getline(cin, addressone);
	got(51, 9);
	cout << addressone;
	got(50, 13);
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ       Enter Address      : (City)                             บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
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
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ       Enter Student ID   : (Officially given by the school)   บ"
		 << "\n\t\t\t" << "บ  User Input:                                                  บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
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
	cout << "\n\t\t\t" << "บ  -----------------------------------------------------------\tบ";
}

void topReceipt()
{
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
		 << "\n\t\t\t" << "บ                       PLM UNIFORM SHOP                        บ"
   		 << "\n\t\t\t" << "บ        Gen. Luna corner Muralla St. Intramuros, Manila        บ"
 		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน" 
 		 << "\n\t\t\t" << "บ                     Customer Information                      บ"
		 << "\n\t\t\t" << "บ  Student Name     :                                           บ"
		 << "\n\t\t\t" << "บ  Student Number   :                                           บ"
		 << "\n\t\t\t" << "บ  Phone Number     :                                           บ"
		 << "\n\t\t\t" << "บ  Address/Location :                                           บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ  Date: ";
	invoiceDate();
	cout << "\t\t\t\tTime: ";
	invoiceTime();
	cout << "	บ"
	 	 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน" 
		 << "\n\t\t\t" << "บ                         Item Ordered                          บ"
	     << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ  Item Description with Price                                  บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน";
}

void bottomReceipt(int totalPrice, string fullname, string mobileNum, string address, string studentID)
{
	cout << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ  Total price: " << "Php " << totalPrice << ".00\t                                บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ             This serves as your official receipt.             บ"
		 << "\n\t\t\t" << "บ         Email us at plmuniformshopfeedback@plm.edu.ph         บ"
		 << "\n\t\t\t" << "บ            Visit us also at www.plmuniformshop.com            บ"
		 << "\n\t\t\t" << "บ                 Thank you, please shop again.                 บ"
		 << "\n\t\t\t" << "บ                 Please press any key to exit.                 บ"
		 << "\n\t\t\t" <<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
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
	cout << "\n\t\t\t" << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
		 << "\n\t\t\t" << "บ                       PLM UNIFORM SHOP                        บ"
   		 << "\n\t\t\t" << "บ        Gen. Luna corner Muralla St. Intramuros, Manila        บ"
 		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน" 
 		 << "\n\t\t\t" << "บ                 TRANSCRIPT OF HISTORY RECORDS                 บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ                     Customer Information                      บ"
		 << "\n\t\t\t" << "บ  Student Name   :                                             บ"
		 << "\n\t\t\t" << "บ  Student Number :                                             บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน"
		 << "\n\t\t\t" << "บ  Date: ";
	invoiceDate();
	cout << "\t\t\t\tTime: ";
	invoiceTime();
	cout << "	บ"
		 << "\n\t\t\t" << "ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน";
}

void totalPrice(int priceSum)
{
	cout << "\n\t\t\t" << "บ  ------------------------------------ Total - Php " << priceSum << ".00" << "\tบ"
		 << "\n\t\t\t" << "บ ============================================================= บ";
}

void allTotal(int overallTotal)
{
	cout << "\n\t\t\t" << "บ  ---------------------------- Overall Total - Php " << overallTotal << ".00" << "\tบ"
		 << "\n\t\t\t" << "บ                                                               บ"
		 << "\n\t\t\t" << "บ               Please press any key to continue                บ"
		 << "\n\t\t\t" << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
}
