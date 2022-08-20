// Project 
//Computer PRogramming
//Bilal Shah
//Ehtisham Ali

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


void add_acc();					// function for "Add A New Account"
void dep_amo();					// function for "Deposite Amount"
void wit_amo();					// function for "Withdraw Amount"
void bal_enq();					// function for "Balance Enquiry Of An Account"
void lis_acc();					// function for "List Of All Accounts"
void clo_acc();					// function for "Close An Account"
void mod_acc();					// function for "Modify An Account"



int main(){						// Main Function
	
	int desire;					// initialize an integer Variable
	
	do{																		// Start a Loop
		system("CLS");														// Clearing Console Screen After Every Loop
		
		cout << "\n              MENU \n\n";								//
		
		cout << "	1. ADD NEW ACCOUNT. \n";								//
		cout << "	2. DEPOSIT AMOUNT. \n";									//
		cout << "	3. WITHDRAW AMOUNT. \n";								//
		cout << "	4. BALANCE ENQUIRY. \n";								//		MENU
		cout << "	5. LIST OF ALL ACCOUNT HOLDERS IN BANK. \n";			//
		cout << "	6. CLOSE AN ACCOUNT. \n";								//
		cout << "	7. MODIFY DETAILS OF AN ACCOUNT. \n";					//
		cout << "	8. EXIT. \n\n";											//
		
		cout << " Enter The Desire Sr. No:  ";
		cin >> desire;														// Taking Input (Required Task)
		
		if ( desire == 1 ){						// Checking Condition for Add Acount
				
				add_acc();						// Calling Function for Add Acount
				
				system("pause");
			}
		if ( desire == 2 ){						// Checking Condition for Deposite Amount
				
				dep_amo();						// Calling Function for Deposite Amount
				
				system("pause");
			}
		if ( desire == 3 ){						// Checking Condition for Withdraw Amount
				
				wit_amo();						// Calling Function for Withdraw Amount
				
				system("pause");
			}
		if ( desire == 4 ){						// Checking Condition for Balance Enquiry
				
				bal_enq();						// Calling Function for Balance Enquiry
				
				system("pause");
			}
		if ( desire == 5 ){						// Checking Condition for List Of All Accounts
				
				lis_acc();						// Calling Function for List Of All Accounts
				
				system("pause");
			}
		if ( desire == 6 ){						// Checking Condition for Close An Account
				
				clo_acc();						// Calling Function for Close An Account
				
				system("pause");
			}
		if ( desire == 7 ){						// Checking Condition for Modify An Account
				
				mod_acc();						// Calling Function for Modify An Account
				
				system("pause");
			}
		if ( desire >= 9 || desire <= 0 ){		// Checking Condition for Wrong Input
				
				cout << "\n. . . . Wrong Input . . . .\n" << endl;
				
				system("pause");
			}
	}
	while ( desire != 8 );
	
	cout << "\n	SYSTEM EXIT";
	
	return 0;
}









//										*****	Defining function for "Add A New Account"	*****

void add_acc(){
	
	int amount, a=0;
	string NAME, PIN, cat, cat2, amount_var, pin_var, name_var, name_var2, pin_var2;
	
	ifstream infile;
	ofstream outfile;
	
	infile.open( "Bank_File.txt", ios::in );
	outfile.open( "temp.txt", ios::out );
	
	
	cout << endl << "	Enter The UserName: ";
	cin >> NAME;
	cout << endl << "	Enter A 4-Digit PIN: ";
	cin >> PIN;
	
	while ( infile >> name_var ){
		
		infile >> name_var2 >> pin_var >> pin_var2 >> amount_var >> amount;
		
		if ( NAME.compare( name_var2 ) != 0  ){
			
			outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount << endl;
		}
		else{
			
			outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount << endl;
			a++;
		}
	}
	
	if ( a == 1 ){
		
		cout << endl << "	Account Already Exist. . .  Change UserName Please....!!!\n" << endl;
	}
	else{
		
		outfile << "UserName:" << " " << NAME << " " << "PIN:" << " " << PIN << " " << "Amount:" << " " << 1000 << endl;
		cout << endl << "	New Account Added Successfully....!!!\n" << endl;
	}
	
	infile.close();
	outfile.close();
	
	system("del Bank_File.txt");
	system("ren temp.txt Bank_File.txt");
	
}



//											*****	Defining function for "Deposite Amount"	*****

void dep_amo(){
	
	int new_amount, amount, a=0;
	string NAME, PIN, cat, cad, amount_var, pin_var, name_var, name_var2, pin_var2;
	
	ifstream infile;
	ofstream outfile;
	
	infile.open( "Bank_File.txt", ios::in );
	outfile.open( "temp.txt", ios::out );
	
	cout << endl << "	Enter The UserName: ";
	cin >> NAME;
	cout << endl << "	Enter The 4-Digit PIN: ";
	cin >> PIN;
	
	cat = NAME + PIN;
	
	while ( infile >> name_var ){
		
		infile >> name_var2 >> pin_var >> pin_var2 >> amount_var >> amount;
		
		cad = name_var2 + pin_var2;
		
		if ( cat.compare( cad ) != 0  ){
			
			outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount << endl;
		}
		else{
			
			cout << endl << "	Enter The Amount: ";
			cin >> new_amount;
				
			new_amount = abs(new_amount);
			
			outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount+new_amount << endl;
			cout << endl << "	Amount Added Successfully....!!!\n" << endl;
			a++;
		}
	}
	
	if ( a == 0 ){
		
		cout << endl << "	No Account Found. . .  Invalid UserName OR PIN....!!!\n" << endl;
	}
	
	infile.close();
	outfile.close();
	
	system("del Bank_File.txt");
	system("ren temp.txt Bank_File.txt");
}


//											*****	Defining function for "Withdraw Amount"	*****

void wit_amo(){
	
	int new_amount, amount, a=0;
	string NAME, PIN, cat, cad, amount_var, pin_var, name_var, name_var2, pin_var2;
	
	cout << endl << "	Enter The UserName: ";
	cin >> NAME;
	cout << endl << "	Enter The 4-Digit PIN: ";
	cin >> PIN;
	cout << endl << "	Enter The Amount In Multiple Of 500: ";
	cin >> new_amount;
	
	new_amount = abs(new_amount);
	
	cat = NAME + PIN;
	
	if ( new_amount % 500 == 0 ){
		
		ifstream infile;
		ofstream outfile;
	
		infile.open( "Bank_File.txt", ios::in );
		outfile.open( "temp.txt", ios::out );
	
		while ( infile >> name_var ){
		
			infile >> name_var2 >> pin_var >> pin_var2 >> amount_var >> amount;
			
			cad = name_var2 + pin_var2;
			
			if ( cat.compare( cad ) != 0  ){
				
				outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount << endl;
			}
			else{
				
				if ( new_amount <= amount ){
				
				outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount-new_amount << endl;
				cout << endl << "	Amount Withdarwn Successfully....!!!\n" << endl;
				a++;
				}
				else{
					
					outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount << endl;
					cout << endl << "	Insufficient Amount To Withdraw. . . . !!!\n" << endl;
					a++;
				}
			}
		}
		
		infile.close();
		outfile.close();
		
		system("del Bank_File.txt");
		system("ren temp.txt Bank_File.txt");
	}
	else{
		
		cout << endl << "	Withdraw Amount Should Be Multiple Of 500 . . . !!!\n" << endl;
		goto label_w;
	}
	
	if ( a == 0 ){
		
		cout << endl << "	No Account Found. . .  Invalid UserName OR PIN....!!!\n" << endl;
	}
	
	label_w:
		a = a;
}


//							*****	Defining function for "Balance Enquiry Of An Account"	*****

void bal_enq(){
	
	int new_amount, amount, a=0;
	string NAME, PIN, cat, cad, amount_var, pin_var, name_var, name_var2, pin_var2;
	
	ifstream infile;
	ofstream outfile;
	
	infile.open( "Bank_File.txt", ios::in );
	
	cout << endl << "	Enter The UserName: ";
	cin >> NAME;
	cout << endl << "	Enter The 4-Digit PIN: ";
	cin >> PIN;
	
	cat = NAME + PIN;
	
	while ( infile >> name_var ){
		
		infile >> name_var2 >> pin_var >> pin_var2 >> amount_var >> amount;
		
		cad = name_var2 + pin_var2;
		
		if ( cat.compare( cad ) == 0  ){
			
			cout << endl << "	Amount You Have In Your Account: " << amount << endl << endl;
			a++;
		}
	}
	
	if ( a == 0 ){
		
		cout << endl << "	No Account Found. . .  Invalid UserName OR PIN....!!!\n" << endl;
	}
	
	infile.close();
}


//									*****	Defining function for "List Of All Accounts"	*****

void lis_acc(){
	
	int amount, a=1;
	string amount_var, pin_var, name_var, name_var2, pin_var2;
	
	ifstream infile;
	
	infile.open( "Bank_File.txt", ios::in );
	
	cout << endl;
	while ( infile >> name_var ){
		
		infile >> name_var2 >> pin_var >> pin_var2 >> amount_var >> amount;
		
		cout << "	" << a << ". " << name_var2 << endl;
		a++;
	}
	
	cout << endl;
	infile.close();
}


//										*****	Defining function for "Close An Account"	*****

void clo_acc(){
	
	int amount, a=0;
	string NAME, PIN, cat, cad, amount_var, pin_var, name_var, name_var2, pin_var2;
	
	ifstream infile;
	ofstream outfile;
	
	infile.open( "Bank_File.txt", ios::in );
	outfile.open( "temp.txt", ios::out );
	
	cout << endl << "	Enter The UserName: ";
	cin >> NAME;
	cout << endl << "	Enter The 4-Digit PIN: ";
	cin >> PIN;
	
	cat = NAME + PIN;
	
	while ( infile >> name_var ){
		
		infile >> name_var2 >> pin_var >> pin_var2 >> amount_var >> amount;
		
		cad = name_var2 + pin_var2;
		
		if ( cat.compare( cad ) != 0  ){
			
			outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount << endl;
		}
		else{
			
			a++;
			cout << endl << "	Account Closed Successfully. . . !!!\n" << endl;
		}
	}
	
	if ( a == 0 ){
		
		cout << endl << "	No Account Found. . .  Invalid Username OR PIN....!!!\n" << endl;
	}
		
	infile.close();
	outfile.close();
	
	system("del Bank_File.txt");
	system("ren temp.txt Bank_File.txt");
	
}


//										*****	Defining function for "Modify An Account"	*****

void mod_acc(){
	
	int amount, a=0;
	string NAME, PIN, cat, cad, amount_var, pin_var, name_var, name_var2, pin_var2, NEW_NAME, NEW_PIN;
	
	ifstream infile;
	ofstream outfile;
	
	infile.open( "Bank_File.txt", ios::in );
	outfile.open( "temp.txt", ios::out );
	
	cout << endl << "	Enter OLD UserName: ";
	cin >> NAME;
	cout << endl << "	Enter OLD 4-Digit PIN: ";
	cin >> PIN;
	
	cout << endl << "	Enter NEW UserName: ";
	cin >> NEW_NAME;
	cout << endl << "	Enter NEW 4-Digit PIN: ";
	cin >> NEW_PIN;
	
	cat = NAME + PIN;
	
	while ( infile >> name_var ){
		
		infile >> name_var2 >> pin_var >> pin_var2 >> amount_var >> amount;
		
		cad = name_var2 + pin_var2;
		
		if ( cat.compare( cad ) != 0  ){
			
			outfile << name_var << " " << name_var2 << " " << pin_var << " " << pin_var2 << " " << amount_var << " " << amount << endl;
		}
		else{
			
			outfile << name_var << " " << NEW_NAME << " " << pin_var << " " << NEW_PIN << " " << amount_var << " " << amount << endl;
			cout << endl << "	Account Modified Successfully....!!!\n" << endl;
			a++;
		}
	}
	
	if ( a == 0 ){
		
		cout << endl << "	No Account Found. . .  Invalid OLD UserName OR PIN....!!!\n" << endl;
	}
	
	infile.close();
	outfile.close();
	
	system("del Bank_File.txt");
	system("ren temp.txt Bank_File.txt");
}
