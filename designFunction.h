#include "accessoryFunction.h"

using namespace std;



/*Declaration of Functions*/

//Design Functions Main
void displayBox(int title);
void mainPageHeader(int page);
void mainPageFooter(int page);
void mainPageBody();
void headerFooterFull(int page);

//Design Function Account
void boxAcount(int page);
//Design Function Inventory
void inventoryBody(int& page);
//Design Function Order
void orderBody(int page);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Definition of Functions*/

//Design Functions Main

void displayBox(int title){
	//gridGuide();
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
		gotoxy(upperx + 42 ,uppery + 3);cout << "Username";
		gotoxy(upperx + 76 ,uppery + 3);cout << "  Name";
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
		gotoxy(upperx + 52 ,uppery + 21);cout << "[3] Back to Main Menu";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[4] Exit Program";
		gotoxy(upperx + 28 ,uppery + 24);cout << "Please choose a menu in the selection: ";
	}
	if(page == 2){
		gotoxy(upperx + 28 ,uppery + 21);cout << "[1] Save Sales";
		gotoxy(upperx + 28 ,uppery + 22);cout << "[2] Print Sales";
		gotoxy(upperx + 52 ,uppery + 21);cout << "[3] Back to Main Menu";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[4] Exit Program";
		gotoxy(upperx + 28 ,uppery + 24);cout << "Please choose a menu in the selection: ";
	}
	if(page == 3){
		gotoxy(upperx + 26 ,uppery + 21);cout << "[1] Edit Stocks";
		gotoxy(upperx + 26 ,uppery + 22);cout << "[2] Edit Price";
		gotoxy(upperx + 26 ,uppery + 23);cout << "[3] Go To Next page";
		gotoxy(upperx + 52 ,uppery + 21);cout << "[4] Go To Previous Page";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[5] Back to Main Menu";
		gotoxy(upperx + 52 ,uppery + 23);cout << "[6] Exit Program";
		gotoxy(upperx + 28 ,uppery + 24);cout << "Please choose a menu in the selection: ";
	}
	if(page == 4){
		gotoxy(upperx + 28 ,uppery + 21);cout << "[1] Add Account";
		gotoxy(upperx + 28 ,uppery + 22);cout << "[2] Edit Account";
		gotoxy(upperx + 52 ,uppery + 21);cout << "[3] Go Back";
		gotoxy(upperx + 52 ,uppery + 22);cout << "[4] Exit Program";
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

void headerFooterFull(int page){
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

//Design Function Account
void boxAccount(int page){
	if(page == 1){
		displayBox(4);
		gotoxy(34,5); cout << "-    A  D  D  I  N  G       A  C  C  O  U  N  T    -";
	}
	if(page == 2){
		displayBox(4);
		gotoxy(34,5); cout << "-   E  D  I  T  I  N  G      A  C  C  O  U  N  T   -";
	}
}

//Design Function Inventory
void inventoryBody(int& page){
	
	if (page == 0){
		gotoxy(upperx + 2 ,uppery + 3);cout << "  -    U   N   D   E   R   G   R   A   D   U   A   T   E       U   N   I   F   O   R   M   -";
		gotoxy(upperx + 8 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 15 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 30 ,uppery + 5);cout << "Stocks Left";
		gotoxy(upperx + 58 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 65 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 80,uppery + 5);cout << "Stocks Left";
		int y = 6;
		for(int i = 1; i <= 7 ; i++){
			gotoxy(upperx + 8,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 19,uppery + y); cout << vec_dressCode[i-1];
			gotoxy(upperx + 35,uppery + y); cout << vec_quantity[i-1];
			y++;
		}
		y = 6;
		for(int i = 8; i <= 15 ; i++){
			gotoxy(upperx + 58,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 69,uppery+ y); cout << vec_dressCode[i-1];
			gotoxy(upperx + 85,uppery+ y); cout << vec_quantity[i-1];
			y++;
		}
	}
	
	else if (page == 1){
		int count = 16;
		gotoxy(upperx + 2 ,uppery + 3);cout << "               -      P    E            U    N    I    F    O    R    M     -";	
		gotoxy(upperx + 8 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 15 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 30 ,uppery + 5);cout << "Stocks Left";
		gotoxy(upperx + 58 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 65 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 80,uppery + 5);cout << "Stocks Left";
		int y = 6;
		for(int i = 1; i <= 6 ; i++){
			gotoxy(upperx + 8,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 18,uppery + y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 34,uppery + y); cout << vec_quantity[count - 1];
			count++;
			y+=2;
		}
		y = 6;
		for(int i = 7; i <= 12 ; i++){
			gotoxy(upperx + 58,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 68,uppery+ y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 84,uppery+ y); cout << vec_quantity[count - 1];
			count++;
			y+=2;
		}
	}
	
	else if (page == 2){
		int count = 28;
		gotoxy(upperx + 2 ,uppery + 3);cout << "  -     A   R   C   H   I   T   E   C   T   U   R   E        U   N   I   F   O   R   M     -";	
		gotoxy(upperx + 8 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 15 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 30 ,uppery + 5);cout << "Stocks Left";
		gotoxy(upperx + 58 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 65 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 80,uppery + 5);cout << "Stocks Left";
		int y = 6;
		for(int i = 1; i <= 5 ; i++){
			gotoxy(upperx + 8,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 18,uppery + y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 34,uppery + y); cout << vec_quantity[count - 1];
			count++;
			y+=2;
		}
		y = 6;
		for(int i = 6; i <= 9 ; i++){
			gotoxy(upperx + 58,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 68,uppery+ y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 84,uppery+ y); cout << vec_quantity[count - 1];
			count++;
			y+=2;
		}
	}
	
	else if (page == 3){
		int count = 37;
		gotoxy(upperx + 2 ,uppery + 3);cout << "     -      P  H  Y  S  I  C  A  L      T  H  E  R  A  P  Y      U  N  I  F  O  R  M     -";	
		gotoxy(upperx + 8 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 15 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 30 ,uppery + 5);cout << "Stocks Left";
		gotoxy(upperx + 58 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 65 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 80,uppery + 5);cout << "Stocks Left";
		int y = 6;
		for(int i = 1; i <= 8 ; i++){
			gotoxy(upperx + 8,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 18,uppery + y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 34,uppery + y); cout << vec_quantity[count - 1];
			count++;
			y++;
		}
		y = 6;
		for(int i = 9; i <= 15 ; i++){
			gotoxy(upperx + 58,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 68,uppery+ y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 84,uppery+ y); cout << vec_quantity[count - 1];
			count++;
			y++;
		}	
	}
	
	else if (page == 4){
		int count = 52;
		
		gotoxy(upperx + 2 ,uppery + 3);cout << "  -    P   S   Y   C   H   O   L   O   G   Y          U   N   I   F   O   R   M     -";	
		gotoxy(upperx + 8 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 15 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 30 ,uppery + 5);cout << "Stocks Left";
		gotoxy(upperx + 58 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 65 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 80,uppery + 5);cout << "Stocks Left";
		int y = 6;
		for(int i = 1; i <= 8 ; i++){
			gotoxy(upperx + 8,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 18,uppery + y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 34,uppery + y); cout << vec_quantity[count - 1];
			count++;
			y++;
		}
		y = 6;
		for(int i = 9; i <= 15 ; i++){
			gotoxy(upperx + 58,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 68,uppery+ y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 84,uppery+ y); cout << vec_quantity[count - 1];
			count++;
			y++;
		}	
	}
	
	else if (page == 5){
		int count = 67;
		gotoxy(upperx + 2 ,uppery + 3);cout << "     -       M   E   D   I   C   I   N   E             U   N   I   F   O   R   M        -";	
		gotoxy(upperx + 8 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 15 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 30 ,uppery + 5);cout << "Stocks Left";
		gotoxy(upperx + 58 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 65 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 80,uppery + 5);cout << "Stocks Left";
		int y = 6;
		for(int i = 1; i <= 8 ; i++){
			gotoxy(upperx + 8,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 18,uppery + y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 34,uppery + y); cout << vec_quantity[count - 1];
			count++;
			y++;
		}
		y = 6;
		for(int i = 9; i <= 15 ; i++){
			gotoxy(upperx + 58,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 68,uppery+ y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 84,uppery+ y); cout << vec_quantity[count - 1];
			count++;
			y++;
		}	
	}
	
	else if (page == 6){
		int count = 82;
		
		gotoxy(upperx + 2 ,uppery + 3);cout << "        -          A       D       D           O       N       S	          -";	
		gotoxy(upperx + 28 ,uppery + 5);cout << "No.";
		gotoxy(upperx + 40 ,uppery + 5);cout << "Dress Code";
		gotoxy(upperx + 55 ,uppery + 5);cout << "Stocks Left";
		int y = 7;
		for(int i = 1; i <= 5 ; i++){
			gotoxy(upperx + 28,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 43,uppery + y); cout << vec_dressCode[count - 1];
			gotoxy(upperx + 60,uppery + y); cout << vec_quantity[count - 1];
			count++;
			y+=2;
		}
			
	}
	
	
}

//Design Function Order
void orderBody(int page){
	if(page==0){
		gotoxy(upperx + 13 ,uppery + 3);cout << "NO.";
		gotoxy(upperx + 35 ,uppery + 3);cout << "Name";
		gotoxy(upperx + 55 ,uppery + 3);cout << "#Items";
		gotoxy(upperx + 77 ,uppery + 3);cout << "Order Date";
		
		int y = 5;
		for(int i = 1; i <= vec_buyerName.size() ; i++){
			gotoxy(upperx + 13,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 32,uppery + y); cout << vec_buyerName[i-1];
			gotoxy(upperx + 58,uppery + y); cout << vec_numberOfItems[i-1];
			gotoxy(upperx + 77,uppery + y); cout << vec_dateOfOrder[i-1];
			y++;
		}
	}
}		

