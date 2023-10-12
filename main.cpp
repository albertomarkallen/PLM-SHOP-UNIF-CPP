#include <iostream>
#include "sellerMainFunction.h"
#include "Buyersmenu-backend.h"

using namespace std;



int main(){
    system("title Pamantasang Lungsod ng Maynila: Bilihan ng damit atbp");
	cout << "\n  ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
	 	 << "\n  บ                                                           บ"
		 << "\n  บ      WELCOME TO PLM UNIFORM SHOP                          บ"
		 << "\n  บ                                                           บ"
		 << "\n  บ      [1]    Buyer                                         บ"
		 << "\n  บ                                                           บ"
		 << "\n  บ      [2]    Seller                                        บ"
		 << "\n  บ                                                           บ"
		 << "\n  บ      [3]    Exit                                          บ" 
		 << "\n  บ                                                           บ"
		 << "\n  ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
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
