#include <iostream>
#include "sellerMainFunction.h"
#include "Buyersmenu-backend.h"

using namespace std;



int main(){
    system("title Pamantasang Lungsod ng Maynila: Bilihan ng damit atbp");
	cout << "\n  �����������������������������������������������������������ͻ"
	 	 << "\n  �                                                           �"
		 << "\n  �      WELCOME TO PLM UNIFORM SHOP                          �"
		 << "\n  �                                                           �"
		 << "\n  �      [1]    Buyer                                         �"
		 << "\n  �                                                           �"
		 << "\n  �      [2]    Seller                                        �"
		 << "\n  �                                                           �"
		 << "\n  �      [3]    Exit                                          �" 
		 << "\n  �                                                           �"
		 << "\n  �����������������������������������������������������������ͼ"
		 << endl << endl
		 << "   Select the type of user: ";
	int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1){
		buyerMenu();
    }
    
    else if (choice == 2){
        login();
		sellersMenu();
    }
    
    else if (choice == 3){
        exitProgram();
    }
    
    else{
        main();
    }
    return 0;
}
