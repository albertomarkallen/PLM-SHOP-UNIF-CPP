#include<vector>
#include "databaseFunction.h"
#include "designFunction.h"

using namespace std;

//Main Functions Declaration(Pass to Main CPP)
void sellersMenu();
void login();


//Account Page Functions Declaration
void mainAccountFunction();
void accountBody(int page);
void adminCredentials();
void refreshAccountVector();
void addingAccountFunction();
void editingAccountFunction();

//Inventory Page Functions Declaration
void mainInventoryFunction();
void refreshInventoryVector();
void editingStocks();
void editingPrice();
void refreshVectorInventory();

//Order Page Function
void mainOrderFunction();
void confirmOrder();
void refreshVectorOrder();
void editOrder();
void editOrderBody(int position);
void editInfo(int toEdit,int position);

//Sales Page Function
void mainSalesFunctions();
void salesBody(int page);
void refreshVectorSales();
void printSalesReport(string arr_college[],string arr_dressCode[],int arr_quantity[],int arr_price[],vector <int> orderCounter,int toPay,int totalItems, int totalSales);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Main Functions Definition(Pass to Main CPP)
void login(){
	string username, password;
	vector <string> vec_name;
    vector <string> vec_address;
    vector <string> vec_phoneNumber;
    vector <string> vec_username;
    vector <string> vec_password;
    readDataSellerAccounts(vec_name,vec_address,vec_phoneNumber,vec_username,vec_password);
    a:
	clrscr();
	setColor("B","DC");
	gotoxy(55,12);
	cout << "LOGIN\n";
	gotoxy(40,13);
	cout << "ษอออออออออออออออออออออออออออออออออป\n";
	gotoxy(40,14);
	cout << "บUsername: \t\t\t  บ";
	gotoxy(40,15);
	cout << "บ\t\t\t\t  บ";
	gotoxy(40,16);
	cout << "บPassword: \t\t\t  บ";
	gotoxy(40,17);
	cout << "ศอออออออออออออออออออออออออออออออออผ";
	gotoxy(50,14);
	setColor("B","LW");
	cin >> username;
	gotoxy(50,16);
	password = passwordMasker();
	int	position = searchVector(vec_username,username);
	if(position > -1 && password == vec_password[position]){
		currentUser = vec_name[position];
		currentUserName = vec_username[position];
		currentPhoneNumber = vec_phoneNumber[position];
		logUser("Logged In");
	}
	else{
		gotoxy(40,18);
		cout << "Entered Invalid Username Or Password";
		gotoxy(40,19);
		cout << "Press X to Exit and Or Press Any Key to Try Agin: ";
		char choice = getch();
		switch(choice){
			case 'x':
				exitProgram();
				break;
			case 'X':
				exitProgram();
				break;
			default:
				goto a;
				break;
		}
		
	}
}

void sellersMenu(){
	clrscr();
	headerFooterFull(0);
	gotoxy(upperx + 61 ,uppery + 22);
	char choice = getch();
	switch(choice){
		case '1':
			mainOrderFunction();
			break;
		case '2':
			mainSalesFunctions();
			break;
		case '3':
			mainInventoryFunction();
			break;
		case '4':
			mainAccountFunction();
			break;
		case '5':
			exitProgram();
			break;
		default:
			setColor("B","DR");
			gotoxy(upperx + 20 ,uppery + 22);cout << "Invalid Input. Pleasy Try Again. ";
			pause();
			setColor("B","LW");
			sellersMenu();
			break;
	}
}


//Account Page Functions Definition
void mainAccountFunction(){
	refreshAccountVector();
    readDataSellerAccounts(vec_name,vec_address,vec_phoneNumber,vec_username,vec_password);
    clrscr();
	headerFooterFull(4);
	accountBody(0);
	gotoxy(upperx + 67 ,uppery + 24);
	char choice = getch();
	switch(choice){
		case '1':
			addingAccountFunction();
			sellersMenu();
			break;
		case '2':
			editingAccountFunction();
			break;
		case '3':
			sellersMenu();
			break;
		case '4':
			exitProgram();
			break;
		default:
			setColor("B","DR");
			gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
			pause();
			setColor("B","LW");
			mainAccountFunction();
			break;
	}
}

void accountBody(int page){
	if (page == 0){
		int y = 5;
		for(int i = 1; i <= vec_name.size() ; i++){
			gotoxy(upperx + 15,uppery + y); cout << "[" << i << "]";
			gotoxy(upperx + 40,uppery + y); cout << vec_username[i-1];
			gotoxy(upperx + 72,uppery + y); cout << vec_name[i-1];
			y++;
		}
	}
	if (page == 1){
		boxAccount(1);
	}
	if (page == 2){
		boxAccount(2);
	}
}

void adminCredentials(){
	string username,password;
	gotoxy(upperx + 1 , uppery + 6);cout << "Please Enter Admin Credentials...";
	gotoxy(upperx + 1 , uppery + 8);cout << "Enter Username: ";
	gotoxy(upperx + 1 , uppery + 9);cout << "Enter Password: ";
	gotoxy(upperx + 16 , uppery + 8);cin >> username;
	gotoxy(upperx + 16 , uppery + 9);password = passwordMasker();
	gotoxy(upperx + 1,uppery + 11); cout << "Verifying Credentials"; dotMaker();
	if(username == vec_username[0] && password == vec_password[0]){
		setColor("B","DG");
		gotoxy(upperx + 34 , uppery + 22);cout << "-Credentials   Accepted-"; 
		gotoxy(upperx + 32 , uppery + 23);pause();
		setColor("B","LW");
	}
	else{
		setColor("B","LR");
		gotoxy(upperx + 34 , uppery + 22);cout << "-Credentials   Rejected-"; 
		setColor("B","LW");
		gotoxy(upperx + 28 , uppery + 23);cout << "[1] Go Back";
		gotoxy(upperx + 46 , uppery + 23);cout << "[2] Exit Program";
		gotoxy(upperx + 25 ,uppery+24);cout << "Please Choose A Menu In The Selection: ";
		char choice = getch();
		switch(choice){
			case '1':
				mainAccountFunction();
				break;
			case '2':
				exitProgram();
				break;
			default:
				setColor("B","LR");
				gotoxy(upperx + 20 , uppery +24); "Invalid Input. Please Try Again! ";
				pause();
				setColor("B","LW");
				adminCredentials();
				break;
				
		}
	}
}

void refreshAccountVector(){
	refreshVector(vec_name);
	refreshVector(vec_address);
	refreshVector(vec_phoneNumber);
	refreshVector(vec_username);
	refreshVector(vec_password);
}

void addingAccountFunction(){
	string username,password,retypePassword,name,address,phoneNumber;
	clrscr();
	boxAccount(1);
	adminCredentials();
	cin.ignore();
	clrscr();
	boxAccount(1);
	gotoxy(upperx + 1 , uppery + 6);cout << "Adding A New Account...";
	gotoxy(upperx + 1 , uppery + 8);cout << "Enter Username: ";
	gotoxy(upperx + 16 , uppery + 8);getline(cin,username);
	int result = searchVector(vec_username,username);
	if(result > -1){
		setColor("B","LR");
		gotoxy(upperx + 34 , uppery + 22);cout << "Account Already Exist!"; 
		gotoxy(upperx + 32 , uppery + 23);pause();
		setColor("B","LW");
		mainAccountFunction();
		
	}
	else{
		gotoxy(upperx + 1 , uppery + 9);cout << "Enter Full Name: ";
		gotoxy(upperx + 1 , uppery + 10);cout << "Enter Address: ";
		gotoxy(upperx + 1 , uppery + 11);cout << "Enter Phone Number: ";
		gotoxy(upperx + 1 , uppery + 12);cout << "Enter Password: ";
		gotoxy(upperx + 1 , uppery + 13);cout << "Retype Password: ";
		gotoxy(upperx + 17 , uppery + 9);getline(cin >> ws ,name);
		gotoxy(upperx + 15 , uppery + 10);getline(cin,address);
		gotoxy(upperx + 20 , uppery + 11);cin >> phoneNumber;
		gotoxy(upperx + 16 , uppery + 12);password = passwordMasker();
		gotoxy(upperx + 17 , uppery + 13);retypePassword = passwordMasker();
		
		if(password != retypePassword){
		setColor("B","LR");
		gotoxy(upperx + 32 , uppery + 22);cout << "Password Did Not Match"; 
		gotoxy(upperx + 32 , uppery + 23);pause();
		setColor("B","LW");
		mainAccountFunction();
		}
		else{
        	vec_name.push_back(name);
			vec_address.push_back(address);
			vec_phoneNumber.push_back(phoneNumber);
			vec_username.push_back(username);
			vec_password.push_back(password);
			writeDataSellerAccounts(vec_name,vec_address,vec_phoneNumber,vec_username,vec_password);
			logUser("Add Account");
			setColor("B","LG");
			loadingBar("Adding...");
			setColor("B","LW");
		}
	}
}

void editingAccountFunction(){
	string username,password,retypePassword,name,address,phoneNumber;
	clrscr();
	boxAccount(2);
	adminCredentials();
	cin.ignore();
	clrscr();
	boxAccount(2);
	gotoxy(upperx + 1 , uppery + 6);cout << "Please Enter Username To Be Edited";
	gotoxy(upperx + 1 , uppery + 8);cout << "Enter Username: ";
	gotoxy(upperx + 16 , uppery + 8);getline(cin,username);
	int position = searchVector(vec_username, username);
	if(position > -1){
		clrscr();
		boxAccount(2);
		setColor("B","DG");
		gotoxy(upperx + 39 ,uppery + 12);cout << "Account  Found!";
		setColor("B","LW");
		gotoxy(upperx + 29 ,uppery+24);pause();
		clrscr();
		boxAccount(2);
		
		gotoxy(upperx + 18,uppery + 9); cout << "Name:  ";
		cout << vec_name[position];
		gotoxy(upperx + 18,uppery + 11); cout << "Address:  "; 
		cout << vec_address[position];
		gotoxy(upperx + 18,uppery + 13); cout << "Phone Number: "; 
		cout << vec_phoneNumber[position];
		gotoxy(upperx + 54,uppery + 9); cout << "Username: "; 
		cout << vec_username[position];
		gotoxy(upperx + 18, uppery + 15);cout << "Press E to Edit or Press D to Delete: ";
		char editDeleteChoice = getch();
		switch(editDeleteChoice){
			case 'e':
				a:
				clearConsole();
				gotoxy(upperx + 26, uppery + 21);cout << "[1] Name";
				gotoxy(upperx + 26, uppery + 22);cout << "[2] Address";
				gotoxy(upperx + 26, uppery + 23);cout << "[3] Phone Number";
				gotoxy(upperx + 52, uppery + 21);cout << "[4] Username";
				gotoxy(upperx + 52, uppery + 22);cout << "[5] Save Information";
				gotoxy(upperx + 52, uppery + 23);cout << "[6] Cancel";
				gotoxy(upperx + 26, uppery + 24);cout << "What Are You Going To Edit: ";
				int editChoice;
				cin >> editChoice;
				clearConsole();
				 if(editChoice == 1){
					gotoxy(upperx + 26, uppery + 23);cout << "Enter New Name: ";
					cin.ignore();
					getline(cin,name);
					vec_name[position] = name;
					goto a;
				}
				else if(editChoice == 2){
					gotoxy(upperx + 26, uppery + 23);cout << "Enter New Address: ";
					cin.ignore();
					getline(cin,address);
					vec_address[position] = address;
					goto a;
				}
				else if(editChoice == 3){
					gotoxy(upperx + 26, uppery + 23);cout << "Enter New Phone Number: ";
					cin.ignore();
					getline(cin,phoneNumber);
					vec_phoneNumber[position] = phoneNumber;
					goto a;
				}
				else if(editChoice == 4){
					gotoxy(upperx + 26, uppery + 23);cout << "Enter New Username: ";
					cin.ignore();
					getline(cin,username);
					vec_username[position] = username;
					goto a;
				}
				else if(editChoice == 5){
					gotoxy(upperx + 26, uppery + 22);cout << "Enter Your Password: ";
					password = passwordMasker();
					if(password == vec_password[position]){
			            setColor("B","LY");
			            logUser("Changed Accounts Information");
						loadingBar("Saving...");
						setColor("B","LW");
						writeDataSellerAccounts(vec_name,vec_address,vec_phoneNumber,vec_username,vec_password);
						mainAccountFunction();
			            
					}
					else{
						setColor("B","DR");
						gotoxy(upperx + 26, uppery + 23);cout << "Password Did Not Match!";
						gotoxy(upperx + 26, uppery + 24);pause();
						setColor("B","LW");
						mainAccountFunction();
					}
				}
				else{
					mainAccountFunction();
				}
				break;
			case 'd':
				gotoxy(upperx + 26, uppery + 22);cout << "Enter Your Password: ";
				password = passwordMasker();
				if(password == vec_password[position]){
					for (int i = position + 1 ; i < vec_name.size() ; i++){
		                vec_name[i-1] = vec_name[i];
		                vec_address[i-1] = vec_address[i];
		                vec_phoneNumber[i-1] = vec_phoneNumber[i];
		                vec_username[i-1] = vec_username[i];
		                vec_password[i-1] = vec_password[i];
		            }
		            vec_name.pop_back();
		            vec_address.pop_back();
		            vec_phoneNumber.pop_back();
		            vec_username.pop_back();
		            vec_password.pop_back();
		            writeDataSellerAccounts(vec_name,vec_address,vec_phoneNumber,vec_username,vec_password);
					logUser("Delete Account");	
		            setColor("B","LR");
					loadingBar("Deleting...");
					setColor("B","LW");
					editingAccountFunction();
				}
				else{
				setColor("B","DR");
				gotoxy(upperx + 26, uppery + 23);cout << "Password Did Not Match!";
				gotoxy(upperx + 26, uppery + 24);pause();
				setColor("B","LW");
				mainAccountFunction();
				}
				break;
			default:
				setColor("B","LR");
				gotoxy(upperx + 20 , uppery +24); cout << "Invalid Input. Please Try Again! ";
				pause();
				setColor("B","LW");
				editingAccountFunction();
				break;
		}
	}
	else{
		clrscr();
		boxAccount(2);
		setColor("B","DR");
		gotoxy(upperx + 38 ,uppery + 12);cout << "Account Not Found!";
		setColor("B","LW");
		gotoxy(upperx + 28 , uppery + 23);cout << "[1] Go Back";
		gotoxy(upperx + 46 , uppery + 23);cout << "[2] Exit Program";
		gotoxy(upperx + 25 ,uppery+24);cout << "Please Choose A Menu In The Selection: ";
		char choice = getch();
		switch(choice){
			case '1':
				mainAccountFunction();
				break;
			case '2':
				exitProgram();
				break;
			default:
				setColor("B","LR");
				gotoxy(upperx + 20 , uppery +24); cout << "Invalid Input. Please Try Again! ";
				pause();
				setColor("B","LW");
				adminCredentials();
				break;
				
		}
	}
}



//Inventory Page Functions Definition
void mainInventoryFunction(){
	readDataSellerInventory(vec_college,vec_dressCode,vec_dressType,vec_size,vec_price,vec_quantity);
	int currentPage = 0;
	a:
	clrscr();
	headerFooterFull(3);
	inventoryBody(currentPage);
	gotoxy(upperx + 67 ,uppery + 24);
	char choice = getch();
	switch(choice){
		case '1':
			editingStocks();
			mainInventoryFunction();
			break;
		case '2':
			editingPrice();
			mainInventoryFunction();
			break;
		case '3':
			currentPage++;
			if(currentPage > 6){
				setColor("B","LR");
				gotoxy(upperx + 20 ,uppery + 24);cout << "This Is The Last Page. ";
				pause();
				setColor("B","LW");
				currentPage--;
			}
			inventoryBody(currentPage);
			goto a;
			break;
		case '4':
			currentPage--;
			if(currentPage < 0){
				setColor("B","LR");
				gotoxy(upperx + 20 ,uppery + 24);cout << "This Is The First Page. ";
				pause();
				setColor("B","LW");
				currentPage++;
			}
			inventoryBody(currentPage);
			goto a;
			break;
		case '5':
			sellersMenu();
			break;
		case '6':
			exitProgram();
			break;
		default:
			setColor("B","DR");
			gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
			pause();
			setColor("B","LW");
			mainInventoryFunction();
			break;
	}
	pause();
}

void editingStocks(){
	int stockChange, position;
	string dressCode;
	string editChoice;
	clearConsole();
	gotoxy(upperx + 25 ,uppery + 21);cout << "Where Do You Want to Edit Stock: ";
	cin >> dressCode;
	position = searchVector(vec_dressCode,dressCode);
	if(position > -1){
		clearConsole();
		gotoxy(upperx + 30 ,uppery + 21);cout << "[1] Add Stocks";
		gotoxy(upperx + 30 ,uppery + 22);cout << "[2] Remove Stocks";
		gotoxy(upperx + 30 ,uppery + 23);cout << "[3] Exit Program";
		gotoxy(upperx + 25 ,uppery + 24);cout << "Please Choose A Menu:";
		char choice = getch();
		switch(choice){
			case '1':
				clearConsole();
				gotoxy(upperx + 30 ,uppery + 21);cout << "DressCode: " << vec_dressCode[position];
				gotoxy(upperx + 30 ,uppery + 22);cout << "Current Stock: "<< vec_quantity[position];;
				gotoxy(upperx + 30 ,uppery + 23);cout << "How Many Stocks Do You Want to Add: ";
				cin >> stockChange;
				if(cin.fail()){
					setColor("B","LR");
					loadingBar("Error...");
					setColor("B","LW");
					exitProgram();
				}
				gotoxy(upperx + 30 ,uppery + 24);cout << "Are You Sure You Want To Add " << stockChange << " stocks[Y/N]: ";
				cin >> editChoice;
				if(editChoice == "Y" || editChoice == "y"){
					clearConsole();
					vec_quantity[position]+=stockChange;
					writeDataSellerStocks(vec_college,vec_dressCode,vec_dressType,vec_size,vec_price,vec_quantity);
					logUser("Add Stocks");
					setColor("B","LG");
					loadingBar("Adding...");
					setColor("B","LW");
					mainInventoryFunction();
				}
				else if(editChoice == "N" || editChoice == "n"){
					mainInventoryFunction();
				}
				else{
					setColor("B","DR");
					gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
					pause();
					setColor("B","LW");
				}
				break;
			case '2':
					clearConsole();
					if( vec_quantity[position] == 0 ){
						setColor("B","LR");
						gotoxy(upperx + 30 ,uppery + 22);cout << "There is Already None in The Stock";
						gotoxy(upperx + 30 ,uppery + 23);pause();
						setColor("B","LW");
						mainInventoryFunction();
					}
					gotoxy(upperx + 30 ,uppery + 21);cout << "DressCode: " << vec_dressCode[position];
					gotoxy(upperx + 30 ,uppery + 22);cout << "Current Stock: "<< vec_quantity[position];;
					gotoxy(upperx + 30 ,uppery + 23);cout << "How Many Stocks Do You Want to Remove: ";
					cin >> stockChange;
					if( vec_quantity[position] < stockChange ){
						setColor("B","LR");
						gotoxy(upperx + 30 ,uppery + 23);cout << "Cannot Remove More Than the Stock                                             ";
						gotoxy(upperx + 30 ,uppery + 24);pause();
						setColor("B","LW");
						mainInventoryFunction();
					}
					if(cin.fail()){
						setColor("B","LR");
						loadingBar("Error...");
						setColor("B","LW");
						exitProgram();
					}
					gotoxy(upperx + 30 ,uppery + 24);cout << "Are You Sure You Want To Remove " << stockChange << " stocks[Y/N]: ";
					cin >> editChoice;
					if(editChoice == "Y" || editChoice == "y"){
						clearConsole();
						vec_quantity[position]-=stockChange;
						writeDataSellerStocks(vec_college,vec_dressCode,vec_dressType,vec_size,vec_price,vec_quantity);
						logUser("Removed Stocks");
						setColor("B","LR");
						loadingBar("Removing...");
						setColor("B","LW");
						mainInventoryFunction();
					}
					else if(editChoice == "N" || editChoice == "n"){
						mainInventoryFunction();
					}
					else{
						setColor("B","DR");
						gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
						pause();
						setColor("B","LW");
					}
					break;
			case '3':
				exitProgram();
				break;
			default:
				setColor("B","DR");
				gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
				pause();
				setColor("B","LW");
				mainInventoryFunction();
				break;
		}
	}
	else{
		clearConsole();
		setColor("B","DR");
		gotoxy(upperx + 20 ,uppery + 24);cout << "Dresscode Entered Invalid! ";
		pause();
		setColor("B","LW");
		mainInventoryFunction();
	}
}

void editingPrice(){
	int priceChange, position;
	string dressCode,editChoice;
	clearConsole();
	gotoxy(upperx + 25 ,uppery + 21);cout << "Where Do You Want to Edit Price: ";
	cin >> dressCode;
	position = searchVector(vec_dressCode,dressCode);
	if(position > -1){
		clearConsole();
		gotoxy(upperx + 25 ,uppery + 21);cout << "Dresscode: " << vec_dressCode[position];
		gotoxy(upperx + 25 ,uppery + 22);cout << "Current Price: " << vec_price[position];
		gotoxy(upperx + 25 ,uppery + 23);cout << "Enter New Price: ";
		cin >> priceChange;
		if(cin.fail()){
			setColor("B","LR");
			loadingBar("Error...");
			setColor("B","LW");
			exitProgram();
		}
		else{
			gotoxy(upperx + 25 ,uppery + 24);cout << "Are You Sure You Want to Make the Price (" << priceChange << ") [Y/N]: ";
			cin >> editChoice;
			if(editChoice == "Y" || editChoice == "y"){
					clearConsole();
					vec_price[position] = priceChange;
					writeDataSellerStocks(vec_college,vec_dressCode,vec_dressType,vec_size,vec_price,vec_quantity);
					logUser("Changed Price");
					setColor("B","LG");
					loadingBar("Changing...");
					setColor("B","LW");
					mainInventoryFunction();
				}
				else if(editChoice == "N" || editChoice == "n"){
					mainInventoryFunction();
				}
				else{
					setColor("B","DR");
					gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
					pause();
					setColor("B","LW");
			}
		}
	}
	else{
		clearConsole();
		setColor("B","DR");
		gotoxy(upperx + 20 ,uppery + 24);cout << "Dresscode Entered Invalid! ";
		pause();
		setColor("B","LW");
		mainInventoryFunction();
	}
}

//Order Page Function
void mainOrderFunction(){
	clrscr();
	refreshVectorOrder();
	readDataSellerOrder(vec_buyerName, vec_buyerPhoneNumber, vec_buyerAddress, vec_studentNumber, vec_numberOfItems, rawDressCode,length);
	
	if(length < 0){
		displayBox(1);
		gotoxy(upperx + 13 ,uppery + 3);cout << "NO.";
		gotoxy(upperx + 35 ,uppery + 3);cout << "Name";
		gotoxy(upperx + 55 ,uppery + 3);cout << "#Items";
		gotoxy(upperx + 77 ,uppery + 3);cout << "Order Date";
		setColor("B","LR");
		gotoxy(upperx + 33 ,uppery + 12);cout << "The Database is Empty Of Orders!";
		setColor("B","LW");
		gotoxy(upperx + 33 ,uppery + 23);pause();	
		sellersMenu();
	}
	readDataOrderDate(vec_dateOfOrder,vec_dateName,vec_dateStudent);
	//Split Strings Phrase into Individual Strings
	vec_DressCode.clear();
    splitPhrase(vec_DressCode);
    orderBody(0);
	headerFooterFull(1);
	gotoxy(upperx + 67 ,uppery + 24);
	char choice = getch();
	switch(choice){
		case '1':
			confirmOrder();
			break;
		case '2':
			editOrder();
			break;
		case '3':
			sellersMenu();
			cin.clear();
			break;
		case '4':
			exitProgram();
			break;
		default:
			setColor("B","DR");
			gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
			pause();
			setColor("B","LW");
			mainOrderFunction();
			break;
	}
	
}

void confirmOrder(){
	clearConsole();
	gotoxy(upperx + 25 , uppery + 22);cout << "Please Choose a Number to be Confrim: ";
	int orderPosition;
	cin >> orderPosition;
	if(orderPosition > vec_buyerName.size() || orderPosition == 0){
		setColor("B","DR");
		gotoxy(upperx + 25 , uppery + 23);cout << "Invalid Input. Please Try Again.";
		gotoxy(upperx + 25 , uppery + 24);pause();
		setColor("B","LW");
		mainOrderFunction();
	}
	gotoxy(upperx + 25 , uppery + 23);cout << "Are You Sure You Want To Confirm Order (" << orderPosition << ") [Y/N]: ";
	string confirmChoice;
	cin >> confirmChoice;
	orderPosition--;
	if (confirmChoice == "y" || confirmChoice == "Y"){
      	writeDataSellerSales(vec_DressCode,orderPosition);
        cout << endl;
        for (int i = orderPosition + 1 ; i < vec_buyerName.size() ; i++){
            vec_buyerName[i-1] = vec_buyerName[i];
            vec_buyerPhoneNumber[i-1] = vec_buyerPhoneNumber[i];
            vec_buyerAddress[i-1] = vec_buyerAddress[i];
            vec_studentNumber[i-1] = vec_studentNumber[i];
            vec_numberOfItems[i-1] = vec_numberOfItems[i];
            rawDressCode[i-1] = rawDressCode[i];
            vec_dateOfOrder[i-1] = vec_dateOfOrder[i];
            vec_dateName[i-1] = vec_dateName[i];
            vec_dateStudent[i-1] = vec_dateStudent[i];
        }
        vec_buyerName.pop_back();
        vec_buyerPhoneNumber.pop_back();
        vec_buyerAddress.pop_back();
        vec_studentNumber.pop_back();
        vec_numberOfItems.pop_back();
    	rawDressCode.pop_back();
    	vec_dateName.pop_back();
    	vec_dateStudent.pop_back();
    	vec_dateOfOrder.pop_back();
    	writeDataSellerOrders(vec_buyerName,vec_buyerPhoneNumber,vec_buyerAddress,vec_studentNumber,vec_numberOfItems,rawDressCode);
    	writeDataSellerDateOfOrder(vec_dateName,vec_dateStudent,vec_dateOfOrder);
    	clearConsole();
    	logUser("Confirm Order");
    	setColor("B","LG");
    	loadingBar("Confirming...");
    	setColor("B","LW");
    	sellersMenu();
	}
	else if (confirmChoice == "n" || confirmChoice == "N"){
		mainOrderFunction();
	}
	else{
		clearConsole();
		setColor("B","LR");
		loadingBar("Error...");
		setColor("B","LW");
		exitProgram();
	}
	pause();
}
void refreshVectorOrder(){
 refreshVector(vec_buyerName);
 refreshVector(vec_buyerPhoneNumber);
 refreshVector(vec_buyerAddress);
 refreshVector(vec_studentNumber);
 refreshVector(rawDressCode);
 refreshVector(vec_dateOfOrder);
 refreshVector(vec_dateName);
 refreshVector(vec_dateStudent);
 refreshIntVector(vec_numberOfItems);

}

void editOrder(){
	clearConsole();
	int position,editChoice,toEdit;
	string confirmChoice, newInfo,editInfoDecision;
	gotoxy(upperx + 25 , uppery + 22);cout << "Please Choose A Number You Want To View/Edit: ";
	cin >> position;
	position--;
	if(position >= vec_buyerName.size()){
		setColor("B","DR");
		gotoxy(upperx + 25,uppery + 23);cout << "Invalid Input. Pleasy Try Again. ";
		gotoxy(upperx + 25,uppery + 24);pause();
		setColor("B","LW");
		mainOrderFunction();
	}
	else if(cin.fail()){
		clearConsole();
		setColor("B","LR");
		loadingBar("Error...");
		setColor("B","LW");
		exitProgram();
	}
	else{
		editOrderBody(position);
		cin >> editChoice;
		switch(editChoice){
			case 1:
				clearConsole();
				gotoxy(upperx + 24,uppery + 21);cout << "[1] Name";
				gotoxy(upperx + 24,uppery + 22);cout << "[2] Phone Number";
				gotoxy(upperx + 24,uppery + 23);cout << "[3] Address";
				gotoxy(upperx + 50,uppery + 21);cout << "[4] Student Number";
				gotoxy(upperx + 50,uppery + 22);cout << "[5] Go Back";
				gotoxy(upperx + 50,uppery + 23);cout << "[6] Exit Program";
				gotoxy(upperx + 24,uppery + 24);cout << "Please Choose Information to Edit: ";
				cin >> toEdit;
				editInfo(toEdit,position);
				break;
			case 2:
				setColor("B","LR");
				gotoxy(upperx + 24 , uppery + 23);cout << "Are You Sure You Want To Delete Order (" << position + 1 << ") [Y/N]: ";
				setColor("B","LW");
				cin >> confirmChoice;
				if (confirmChoice == "y" || confirmChoice == "Y"){
			        for (int i = position + 1 ; i < vec_buyerName.size() ; i++){
			            vec_buyerName[i-1] = vec_buyerName[i];
			            vec_buyerPhoneNumber[i-1] = vec_buyerPhoneNumber[i];
			            vec_buyerAddress[i-1] = vec_buyerAddress[i];
			            vec_studentNumber[i-1] = vec_studentNumber[i];
			            vec_numberOfItems[i-1] = vec_numberOfItems[i];
			            vec_dateOfOrder[i-1] = vec_dateOfOrder[i];
			            vec_dateName[i-1] = vec_dateName[i];
			            vec_dateStudent[i-1] = vec_dateStudent[i];
			        }
			        vec_buyerName.pop_back();
			        vec_buyerPhoneNumber.pop_back();
			        vec_buyerAddress.pop_back();
			        vec_studentNumber.pop_back();
			        vec_numberOfItems.pop_back();
			    	rawDressCode.pop_back();
			    	vec_dateName.pop_back();
			    	vec_dateStudent.pop_back();
			    	vec_dateOfOrder.pop_back();
			    	writeDataSellerOrders(vec_buyerName,vec_buyerPhoneNumber,vec_buyerAddress,vec_studentNumber,vec_numberOfItems,rawDressCode);
			    	writeDataSellerDateOfOrder(vec_dateName,vec_dateStudent,vec_dateOfOrder);
			    	clearConsole();
			    	logUser("Delete Order");
	    			setColor("B","LR");
	    			loadingBar("Deleting...");
	    			setColor("B","LW");
	    			mainOrderFunction();
	    		}
	    		else if (confirmChoice == "n" || confirmChoice == "N"){
					mainOrderFunction();
				}
				else{
					clearConsole();
					setColor("B","LR");
					loadingBar("Error...");
					setColor("B","LW");
					exitProgram();
				}
				break;
			default:
				setColor("B","DR");
				gotoxy(upperx + 24,uppery + 24);cout << "Invalid Input. Pleasy Try Again                                     ";
				gotoxy(upperx + 25,uppery + 24);pause();
				setColor("B","LW");
				mainOrderFunction();
				break;
		}
		gotoxy(20,30);pause();
	}
	
}

void editOrderBody(int position){
	clrscr();
	displayBox(1);
	gotoxy(upperx + 2 , uppery + 3); cout << "                -     E   D   I   T   I   N   G        O   R   D   E    R     -            ";
	gotoxy(upperx + 38,uppery + 5);cout << "Order Details "; 
	gotoxy(upperx + 3,uppery + 6);cout << "Name: ";cout << vec_buyerName[position];
	gotoxy(upperx + 3,uppery + 8);cout << "Phone Number: ";cout << vec_buyerPhoneNumber[position];
	gotoxy(upperx + 3,uppery + 10);cout << "Address: ";cout << vec_buyerAddress[position];
	gotoxy(upperx + 3,uppery + 12);cout << "Student Number: ";cout << vec_studentNumber[position];
	gotoxy(upperx + 3,uppery + 14);cout << "Number of Items Bought: ";cout << vec_numberOfItems[position];
	gotoxy(upperx + 3,uppery + 16);cout << "Orders: ";cout << rawDressCode[position];
	gotoxy(upperx + 3,uppery + 18);cout << "Date Of Order: ";cout << vec_dateOfOrder[position];
	gotoxy(upperx + 24,uppery + 21);cout << "[1] Edit Order";
	gotoxy(upperx + 50,uppery + 21);cout << "[3] Go Back";
	gotoxy(upperx + 24,uppery + 22);cout << "[2] Delete Order";
	gotoxy(upperx + 24,uppery + 23);cout << "Please Choose A Menu in the Selection: ";
}

void editInfo(int toEdit,int position){
	string newInfo,editInfoDecision;
	if(toEdit == 1){
		clearConsole();
		gotoxy(upperx + 19,uppery + 21);cout << "Enter New Name:";
		cin.ignore();
		getline(cin,newInfo);
		gotoxy(upperx + 15 , uppery + 23);cout << "Are You Sure You Want to Change the Name to (" << newInfo << ") [Y/N]: ";
		cin >> editInfoDecision;
		if (editInfoDecision == "y" || editInfoDecision == "Y"){
			vec_buyerName[position] = newInfo;
			writeDataSellerOrders(vec_buyerName,vec_buyerPhoneNumber,vec_buyerAddress,vec_studentNumber,vec_numberOfItems,rawDressCode);
			clearConsole();
			logUser("Edit Name");
			setColor("B","LY");
			loadingBar("Editing...");
			setColor("B","LW");
			mainOrderFunction();
		}
		else if (editInfoDecision == "n" || editInfoDecision == "N"){
			mainOrderFunction();
		}
		else{
			clearConsole();
			setColor("B","LR");
			loadingBar("Error...");
			setColor("B","LW");
			exitProgram();
		}
	}
	
	else if(toEdit == 2){
		clearConsole();
		gotoxy(upperx + 19,uppery + 21);cout << "Enter New Phone Number:";
		cin.ignore();
		getline(cin,newInfo);
		gotoxy(upperx + 15 , uppery + 23);cout << "Are You Sure You Want to Change the Phone Number to (" << newInfo << ") [Y/N]: ";
		cin >> editInfoDecision;
		if (editInfoDecision == "y" || editInfoDecision == "Y"){
			vec_buyerPhoneNumber[position] = newInfo;
			writeDataSellerOrders(vec_buyerName,vec_buyerPhoneNumber,vec_buyerAddress,vec_studentNumber,vec_numberOfItems,rawDressCode);
			clearConsole();
			logUser("Edit Phone Number");
			setColor("B","LY");
			loadingBar("Editing...");
			setColor("B","LW");
			mainOrderFunction();
		}
		else if (editInfoDecision == "n" || editInfoDecision == "N"){
			mainOrderFunction();
		}
		else{
			clearConsole();
			setColor("B","LR");
			loadingBar("Error...");
			setColor("B","LW");
				exitProgram();
		}
	}
	
	else if(toEdit == 3){
		clearConsole();
		gotoxy(upperx + 19,uppery + 21);cout << "Enter New Address:";
		cin.ignore();
		getline(cin,newInfo);
		gotoxy(upperx + 15 , uppery + 23);cout << "Are You Sure You Want to Change the Address to (" << newInfo << ") [Y/N]: ";
		cin >> editInfoDecision;
		if (editInfoDecision == "y" || editInfoDecision == "Y"){
			vec_buyerAddress[position] = newInfo;
			writeDataSellerOrders(vec_buyerName,vec_buyerPhoneNumber,vec_buyerAddress,vec_studentNumber,vec_numberOfItems,rawDressCode);
			clearConsole();
			logUser("Edit Address");
			setColor("B","LY");
			loadingBar("Editing...");
			setColor("B","LW");
			mainOrderFunction();
		}
		else if (editInfoDecision == "n" || editInfoDecision == "N"){
			mainOrderFunction();
		}
		else{
			clearConsole();
			setColor("B","LR");
			loadingBar("Error...");
			setColor("B","LW");
			exitProgram();
		}
	}
	
	else if (toEdit == 4){
		clearConsole();
		gotoxy(upperx + 19,uppery + 21);cout << "Enter New Student Number:";
		cin.ignore();
		getline(cin,newInfo);
		gotoxy(upperx + 15 , uppery + 23);cout << "Are You Sure You Want to Change the Student Number to (" << newInfo << ") [Y/N]: ";
		cin >> editInfoDecision;
		if (editInfoDecision == "y" || editInfoDecision == "Y"){
			vec_studentNumber[position] = newInfo;
			writeDataSellerOrders(vec_buyerName,vec_buyerPhoneNumber,vec_buyerAddress,vec_studentNumber,vec_numberOfItems,rawDressCode);
			clearConsole();
			logUser("Edit Student Number");
			setColor("B","LY");
			loadingBar("Editing...");
			setColor("B","LW");
			mainOrderFunction();
		}
		else if (editInfoDecision == "n" || editInfoDecision == "N"){
			mainOrderFunction();
		}
		else{
			clearConsole();
			setColor("B","LR");
			loadingBar("Error...");
			setColor("B","LW");
				exitProgram();
		}
	}
	else if (toEdit == 5){
		mainOrderFunction();
	}
	else if(toEdit == 6){
		exitProgram();
	}
	else{
		clearConsole();
		setColor("B","LR");
		loadingBar("Error...");
		setColor("B","LW");
		exitProgram();
	}
}

//Sales Functions
void mainSalesFunctions(){
	refreshVectorSales();
	clrscr();
	readDataSales(vec_salesDressCode,length);
	if(length <= 0){
		displayBox(2);
		gotoxy(upperx + 6,uppery + 3);cout << "No.";
		gotoxy(upperx + 19 ,uppery + 3);cout << "College";
		gotoxy(upperx + 36 ,uppery + 3);cout << "Dresscode";
		gotoxy(upperx + 53 ,uppery + 3);cout << "Qty";
		gotoxy(upperx + 66 ,uppery + 3);cout << "Price";
		gotoxy(upperx + 81,uppery + 3);cout << "Total Price";
		setColor("B","LR");
		gotoxy(upperx + 33 ,uppery + 12);cout << "The Database is Empty Of Sales!";
		setColor("B","LW");
		gotoxy(upperx + 33 ,uppery + 23);pause();	
		sellersMenu();
	}
	headerFooterFull(2);
	salesBody(3);
	gotoxy(upperx + 67 ,uppery + 24);
	char choice = getch();
	switch(choice){
		case '1':
			salesBody(0);
			break;
		case '2':
			salesBody(1);
			break;
		case '3':
			sellersMenu();
			break;
		case '4':
			exitProgram();
			break;
		default:
			setColor("B","DR");
			gotoxy(upperx + 20 ,uppery + 24);cout << "Invalid Input. Pleasy Try Again. ";
			pause();
			setColor("B","LW");
			mainOrderFunction();
			break;
	}
}

void salesBody(int page){
	vector <int> orderCounter;
    int totalItems = 0;
    int numberOfItems = 0;
    int totalSales = 0;
    
	gotoxy(upperx + 6,uppery + 3);cout << "No.";
	gotoxy(upperx + 19 ,uppery + 3);cout << "College";
	gotoxy(upperx + 36 ,uppery + 3);cout << "Dresscode";
	gotoxy(upperx + 53 ,uppery + 3);cout << "Qty";
	gotoxy(upperx + 66 ,uppery + 3);cout << "Price";
	gotoxy(upperx + 81,uppery + 3);cout << "Total Price";
	
	string arr_college[] = {"Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate","Undergraduate",
    "PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform","PE Uniform",
    "Arcithecture","Arcithecture","Arcithecture","Arcithecture","Arcithecture","Arcithecture","Arcithecture","Arcithecture","Arcithecture",
    "Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy","Physical Therapy",
    "Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology","Psychology",
    "Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine","Medicine",
    "-Add Ons-","-Add Ons-","-Add Ons-","-Add Ons-","-Add Ons-"};
    
    string arr_dressCode[] = {"FB02","FB03","FB04","FB05","FS01","FS02","FS03","FS04","FS05","MP02","MP03","MP04","P02","P03","P04","TS02","TS03","TS04","TS05","TS06","TS07",
    "GS02","GS03","GS04","GS05","GS06","GS07","BL02","BL03","BL04","BL05","PA01","PA02","PA03","PA04","PA05","WB02","WB03","WB04","WB05","PT01","PT02","PT03","PT04","PT05",
    "SC02","SC03","SC04","WS02","WS03","WS04","CL02","CL03","CL04","CL05","PS01","PS02","PS03","PS04","PS05","CC02","CC03","CC04","PW02","PW03","PW04","RB02","RB03","RB04",
    "RB05","S01","S02","S03","S04","S05","VN02","VN03","VN04","WP02","WP03","WP04","IL08","PP08","PPF08","PPM08","PR08"};
    
    int arr_quantity[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int arr_price[] = {370,370,370,380,300,300,300,300,310,420,420,420,370,370,370,195,195,195,205,215,225,195,195,195,205,215,225,370,370,370,380,300,300,300,300,310,370,370,370,380,
    300,300,300,300,310,420,420,420,370,370,370,370,370,370,380,300,300,300,300,310,420,420,420,370,370,370,370,370,370,380,300,300,300,300,310,420,420,420,370,370,370,75,50,45,50,20};
    
    
	for (int i = 0 ; i < vec_salesDressCode.size() ; i++){
        for(int j = 0 ; j < 86 ; j++){
            if (vec_salesDressCode[i] == arr_dressCode[j]){
                arr_quantity[j]++;
                orderCounter.push_back(j);
            }
        }
    }
        //remove duplicate element
        std::sort(orderCounter.begin(), orderCounter.end());
        orderCounter.erase(std::unique(orderCounter.begin(), orderCounter.end()), orderCounter.end());
	
	int y = 6;
    for (int i = 0 ; i < orderCounter.size() ; i++){
    	int selector = orderCounter[i];
    	int toPay = arr_quantity[selector] * arr_price[selector];
    	numberOfItems++;
  		totalSales+=toPay;
        gotoxy(upperx + 6 ,uppery + y);cout << "[" << i + 1 << "]";
        gotoxy(upperx + 15 ,uppery + y);cout << arr_college[selector];
        gotoxy(upperx + 38 ,uppery + y);cout << arr_dressCode[selector];
        gotoxy(upperx + 54 ,uppery + y);cout << arr_quantity[selector];
        gotoxy(upperx + 65 ,uppery + y);cout << "P" << arr_price[selector] << ".00";
        gotoxy(upperx + 83 ,uppery + y);cout << "P" << toPay << ".00";
        y++;
    }
    for(int i = 0 ; i < sizeof(arr_quantity)/sizeof(arr_quantity[0]) ; i++){
        totalItems = totalItems + arr_quantity[i];
    }
    if(page == 0){
    	clearConsole();
    	writeDataSellerArchive(arr_college,arr_dressCode,arr_quantity,arr_price,orderCounter,toPay);
    	deleteDatabase("databaseSales.txt");
    	logUser("Archive Sales");
    	setColor("B","LG");
    	loadingBar("Saving...");
    	setColor("B","LW");
    	sellersMenu();
	}
	if(page == 1){
	ofstream toPrint ("Sales Report.rtf");
	totalSales= 0;
	int totalItems = 0;
 int numberOfItems = 0;
	getTime(currentTime);
	toPrint << "อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
	toPrint << " -   -   -   S   A   L   E   S       R   E   P   O   R   T   -   -   -";
	toPrint << "อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
	toPrint << "Archived Date: " << currentTime;
	toPrint << endl << "Archived By: " << currentUser;
	toPrint << endl << "Username: " << currentUserName;
	toPrint << endl << "Phone Number: " << currentPhoneNumber << endl;
	
	for (int i = 0 ; i < orderCounter.size() ; i++){
    	int selector = orderCounter[i];
    	int toPay = arr_quantity[selector] * arr_price[selector];
  		totalSales+=toPay;
  		numberOfItems++;
    	toPrint << arr_college[selector] << "[ " << arr_dressCode[selector] << " ]  " << arr_quantity[selector] << "  -  " << toPay;
		toPrint << endl << endl;
    }
     for(int i = 0 ; i < sizeof(arr_quantity)/sizeof(arr_quantity[0]) ; i++){
        totalItems = totalItems + arr_quantity[i];
    }
    
    toPrint << "Total Number of Items: " << totalItems << endl;
    toPrint << "Total Sales: " << totalSales << endl << endl << endl;
    toPrint << endl << endl << endl << endl;
    toPrint << "      ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ               ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ" << endl;
    toPrint << "      Managers Signature Over               Employees Signarture Over" << endl;
    toPrint << "           Printed Name                            Printed Name" << endl;
	clearConsole();
	logUser("Printed Sale");
		setColor("B","LY");
		loadingBar("Printing...");
		setColor("B","LW");
		sellersMenu();
	}
}

void refreshVectorSales(){
 refreshVector(vec_salesDressCode);
}
