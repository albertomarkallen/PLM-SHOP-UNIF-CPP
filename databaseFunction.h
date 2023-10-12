#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>
#include <ctime>
using namespace std;

struct sellerDetails{
	string name;
	string address;
	string phoneNumber;
	string username;
	string password;	
}; 

struct inventoryDetails{
	string college;
	string dressCode;
	string dressType;
	string size;
	int price;
	int quantity; 
};

struct orderDetails{
	string name;
    string phoneNumber;
    string address;
    string dressCode;
    string studentNumber;
    int numberOfItems;
    string dateOfOrder;
    string dateName;
    string dateStudent;
};

string currentUser;
string currentUserName;
string currentPhoneNumber;
string currentTime;

/*Declaration of Functions*/

//Reading Functions
void readDataSellerAccounts(vector <string>& vec_name , vector <string>& vec_address , vector <string>& vec_phoneNumber , vector <string>& vec_username , vector <string>& vec_password);
void readDataSellerOrder(vector <string>& vec_buyerName, vector <string>& vec_buyerPhoneNumber, vector <string>& vec_buyerAddress, vector <string>& vec_studentNumber, vector <int>& vec_numberOfItems,vector <string>& rawDressCode,int &length);
void readDataOrderDate(vector <string>& vec_dateOfOrder,vector <string>& vec_dateName,vector <string>& vec_dateStudent);
void readDataSales(vector <string>& vec_salesDressCode, int& length);
//Writing Functions
void writeDataUserLog(int vector_position,vector <string> vec_name,vector <string> vec_username,vector <string> vec_phoneNumber,string timestamp);
void writeDataSellerAccounts(vector <string> vec_name , vector <string> vec_address , vector <string> vec_phoneNumber , vector <string> vec_username , vector <string> vec_password);
void writeDataSellerStocks(vector <string> vec_college , vector <string> vec_dressCode , vector <string> vec_dressType , vector <string> vec_size , vector <int> vec_price,vector <int> vec_quantity);
void writeDataSellerSales(vector <vector <string> > vec_splitDressCode, int orderPosition);
void writeDataSellerOrders(vector <string> vec_buyerName , vector <string> vec_buyerPhoneNumber , vector <string> vec_buyerAddress , vector <string> vec_studentNumber , vector <int> vec_numberOfItems,vector <string> rawDressCode);
void writeDataSellerDateOfOrder(vector <string> vec_dateName , vector <string> vec_dateStudent , vector <string> vec_dateOfOrder);
void writeDataSellerArchive(string arr_college[],string arr_dressCode[],int arr_quantity[],int arr_price[],vector <int> orderCounter,int toPay);
void deleteDatabase(string name);
//Database That Use Time
void getTime(string& currentTime);
void logUser(string task);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Declaration of Functions*/

//Reading Functions
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
    in_database.close();
}

void readDataSellerInventory(vector <string>& vec_college , vector <string>& vec_dressCode , vector <string>& vec_dressType , vector <string>& vec_size , vector <int>& vec_price,vector <int>& vec_quantity){
	ifstream in_database("clotheprice.txt");
	inventoryDetails stock;
	while(!in_database.eof()){
		in_database >> stock.college >> stock.dressCode >> stock.dressType >> stock.size >> stock.price >> stock.quantity;
        vec_college.push_back(stock.college);
        vec_dressCode.push_back(stock.dressCode);        
        vec_dressType.push_back(stock.dressType);
        vec_size.push_back(stock.size);
        vec_price.push_back(stock.price);
        vec_quantity.push_back(stock.quantity);  
    }
    in_database.close();
}

void readDataSellerOrder(vector <string>& vec_buyerName, vector <string>& vec_buyerPhoneNumber, vector <string>& vec_buyerAddress, vector <string>& vec_studentNumber, vector <int>& vec_numberOfItems,vector <string>& rawDressCode, int &length){
	ifstream in_orderFile ("databaseOrder.txt");
	orderDetails details;

	
	while(!in_orderFile.eof()){
        getline(in_orderFile >> ws ,details.name);
        getline(in_orderFile >> ws,details.phoneNumber);
        getline(in_orderFile >> ws, details.address);
        getline(in_orderFile >> ws ,details.studentNumber);
        in_orderFile >> details.numberOfItems;
        getline(in_orderFile >> ws,details.dressCode);
        
        vec_buyerName.push_back(details.name);
        vec_buyerPhoneNumber.push_back(details.phoneNumber);
        vec_buyerAddress.push_back(details.address);
        vec_studentNumber.push_back(details.studentNumber);
        vec_numberOfItems.push_back(details.numberOfItems);
        rawDressCode.push_back(details.dressCode);
    }
    
    in_orderFile.seekg(0, ios::end); // put the "cursor" at the end of the file
	length = in_orderFile.tellg(); // find the position of the cursor
}

void readDataOrderDate(vector <string>& vec_dateOfOrder,vector <string>& vec_dateName,vector <string>& vec_dateStudent){
	ifstream in_orderFile ("day of order.txt");
	orderDetails details;
	while(!in_orderFile.eof()){
        getline(in_orderFile >> ws,details.dateName);
        getline(in_orderFile >> ws, details.dateStudent);
        getline(in_orderFile >> ws ,details.dateOfOrder);
       
        
        vec_dateOfOrder.push_back(details.dateOfOrder);
        vec_dateName.push_back(details.dateName);
        vec_dateStudent.push_back(details.dateStudent);
    }
}

void readDataSales(vector <string>& vec_salesDressCode, int& length){
	string salesDressCode;
	ifstream in_salesFile ("databaseSales.txt");
    while(!in_salesFile.eof()){
         getline(in_salesFile >> ws ,salesDressCode);
         cout << endl;
         vec_salesDressCode.push_back(salesDressCode);
    }
    
   	in_salesFile.seekg(0, ios::end); 
	length = in_salesFile.tellg(); 
}
//Writing Functions
void writeDataUserLog(int vector_position,vector <string> vec_name,vector <string> vec_username,vector <string> vec_phoneNumber,string timestamp){
	ofstream out_userLog ("User_Log.csv",ios::app);
	out_userLog << vec_name[vector_position] << "," << vec_username[vector_position] << "," << vec_phoneNumber[vector_position] << "," << timestamp;
}

void writeDataSellerAccounts(vector <string> vec_name , vector <string> vec_address , vector <string> vec_phoneNumber , vector <string> vec_username , vector <string> vec_password){
	ofstream out_database ("databaseSellerAccounts.txt");
	for (int i = 0 ; i < vec_name.size() ; i++){
		if(i == vec_name.size() - 1){
			out_database << endl << vec_name[i] << endl << vec_address[i] << endl << vec_phoneNumber[i] << endl << vec_username[i] << endl << vec_password[i];	
		}
		else{
			out_database << endl << vec_name[i] << endl << vec_address[i] << endl << vec_phoneNumber[i] << endl << vec_username[i] << endl << vec_password[i] << endl;
		}
	}
}

void writeDataSellerStocks(vector <string> vec_college , vector <string> vec_dressCode , vector <string> vec_dressType , vector <string> vec_size , vector <int> vec_price,vector <int> vec_quantity){
	ofstream out_database ("clotheprice.txt");
	for (int i = 0 ; i < vec_college.size() ; i++){
		if(i == vec_college.size() - 1){
			out_database << endl << vec_college[i] << endl << vec_dressCode[i] << endl << vec_dressType[i] << endl << vec_size[i] << endl << vec_price[i] << endl << vec_quantity[i];	
		}
		else{
			out_database << endl << vec_college[i] << endl << vec_dressCode[i] << endl << vec_dressType[i] << endl << vec_size[i] << endl << vec_price[i] << endl << vec_quantity[i] << endl;	
		}
	}
}

void writeDataSellerSales(vector <vector <string> > vec_splitDressCode, int orderPosition){
	ofstream out_database ("databaseSales.txt",ios::app);
	int size = vec_splitDressCode[orderPosition].size();
        for (int j = 0 ; j < size ; j++){
        		out_database << endl << vec_splitDressCode[orderPosition][j];
		}
		
        
}

void writeDataSellerOrders(vector <string> vec_buyerName , vector <string> vec_buyerPhoneNumber , vector <string> vec_buyerAddress , vector <string> vec_studentNumber , vector <int> vec_numberOfItems,vector <string> rawDressCode){
	ofstream out_database ("databaseOrder.txt");
	for (int i = 0 ; i < vec_buyerName.size() ; i++){
		if(i == vec_buyerName.size() - 1){
			out_database << endl << vec_buyerName[i] << endl << vec_buyerPhoneNumber[i] << endl << vec_buyerAddress[i] << endl << vec_studentNumber[i] << endl << vec_numberOfItems[i] << endl << rawDressCode[i];	
		}
		else{
			out_database << endl << vec_buyerName[i] << endl << vec_buyerPhoneNumber[i] << endl << vec_buyerAddress[i] << endl << vec_studentNumber[i] << endl << vec_numberOfItems[i] << endl << rawDressCode[i] << endl;	
		}
	}
}
void writeDataSellerDateOfOrder(vector <string> vec_dateName , vector <string> vec_dateStudent , vector <string> vec_dateOfOrder){
	ofstream out_database ("day of order.txt");
	for (int i = 0 ; i < vec_dateName.size() ; i++){
		if(i == vec_dateName.size() - 1){
			out_database << endl << vec_dateName[i] << endl << vec_dateStudent[i] << endl << vec_dateOfOrder[i];	
		}
		else{
			out_database << endl << vec_dateName[i] << endl << vec_dateStudent[i] << endl << vec_dateOfOrder[i] << endl;	
		}
	}
}

void writeDataSellerArchive(string arr_college[],string arr_dressCode[],int arr_quantity[],int arr_price[],vector <int> orderCounter,int toPay){
	ofstream out_database ("Sales Archives.csv",ios::app);
	getTime(currentTime);
	for (int i = 0 ; i < orderCounter.size() ; i++){
        int selector = orderCounter[i];
        int toPay = arr_quantity[selector] * arr_price[selector];
        out_database << arr_college[selector] << "," << arr_dressCode[selector] << "," << arr_quantity[selector] << "," << toPay << "," << currentTime;
    }
}

void deleteDatabase(string name){
	ofstream out_database (name.c_str());
	out_database << "";
}


//Database Functions That Used Time
void getTime(string& currentTime){
			time_t present = time(0);
			char* timeNow = ctime(&present);
			currentTime =+ timeNow;
}

void logUser(string task){
	getTime(currentTime);
	ofstream out_userLogCSV ("User_Log.csv",ios::app);
	out_userLogCSV << task << "," << currentUser << "," << currentUserName << "," << currentPhoneNumber << "," << currentTime;
	out_userLogCSV.close();
	
	ofstream out_userLogTXT ("User_Log.txt",ios::app);
	out_userLogTXT << endl << task << "," << currentUser << "," << currentUserName << "," << currentPhoneNumber << "," << currentTime;
	out_userLogTXT.close();
}
