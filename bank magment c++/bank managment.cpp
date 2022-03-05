/* +=++++++++++++++++++++++++++++++++++++++++++++++++++++
    HEADER FILE USED IN PROJECT
   ****************************************************** */

#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;
//Define a struct by the name bank_managment_system

struct bank_managment_system{
	int deposite;
	int acc_no;
	char f_name[20];
	char l_name[20];
	char address[20];
	int phone_no;
	char account_type;
}account;

//  FUNCTION DECLARATION

void create_account();
void deposite_witdrawal(int);
void display_account(int);
void modify_account(int);
void display_all();
void developer_info();
void depo(int);
void with_do(int);

/* *********************************************************
.                  MAIN FUNCTION
 ************************************************************
 */
 
 int main(){
 	char ch;
 	system("color 5E");
 	int num;
 	do{
 		cout<<"\t\tWELCOME TO UNITY BANK MANAGMENT SYSTEM\n";
 		cout<<"    \t\t========================================\n\n\n";
 		cout<<"\tMAIN MENU\n";
 		cout<<"\t=========\n\n";
 		cout<<"\t1. NEW ACCOUNT\n\n";
 		cout<<"\t2. DEPOSITE AMOUNT\n\n";
 		cout<<"\t3. WITHDRAW AMOUNT\n\n";
 		cout<<"\t4. BALANCE\n\n";
 		cout<<"\t5. ALL ACCOUNT LIST\n\n";
 		cout<<"\t6. MODIFY ACCOUNT\n\n";
 		cout<<"\t7. DEVELOPERS INFORMATION\n\n";
 		cout<<"\t8. EXIT\n\n";
 		cout<<"\tSELECT OPTION NEEDED: ";
 		cin>>ch;
 		system("cls");
 		switch(ch){
 			case '1':
 				create_account();
 				break;
 			case '2':
 				cout<<"\tENTER ACCOUNT NUMBER : ";cin>>num;
 				depo(num);
 				break;
 			case '3':
 				cout<<"\tENTER ACCOUNT NUMBER : ";cin>>num;
 				with_do(num);
			 	break;
			 case '4':
			 	cout<<"\tENTER ACCOUNT NUMBER : ";cin>>num;
			 	display_account(num);
			 	break;
			case '5':
				display_all();
				break;
			case '6':
				 cout<<"\tENTER ACCOUNT NUMBER : ";cin>>num;
				 modify_account(num);
				 break; 	
			 case '7':
			 	developer_info();
			 	break;
			 case '8':
			 cout<<"\n\n\tThanks for using bank managemnt system";
			 break;	
		    }
	    cin.ignore();
	   cin.get(); 
	   system("cls");}
		 while(ch!='8');
		 return 0;  
	}
	
	/* ******************************************
 .         FUNCTION DEFINATION
    ****************************************** */
    
   /* ******************************************
 .         function create account
    ****************************************** */    
void create_account(){
	ofstream outfile;
	outfile.open("account.dat",ios::binary|ios::app);
	cout<<"\t PLEASE INPUT THE FOLLOWING INFORMATION BELOW\n\n";
	cout<<"FIRST_NAME: ";cin>>account.f_name;
	cout<<"LAST_NAME: ";cin>>account.l_name;
	cout<<"ACCOUNT NUMBER: ";cin>>account.acc_no;
	cout<<"ACCOUNT TYPE (C/S): ";cin>>account.account_type;
	account.account_type=toupper(account.account_type);
	cout<<"HOW MUCH MONEY YOU WANT DEPOSITE=";
	cin>>account.deposite;
	cout<<"ADRESS: ";cin>>account.address;
	cout<<"PHONE NUMBER +251: ";cin>>account.phone_no;
	outfile.write(reinterpret_cast<char *> (&account), sizeof(bank_managment_system));
	outfile.close();
	cout<<"PRESS ANY KEY TO BACK MANE MENU";
	
}  //end of create function   

/* ******************************************
 .         function DISPLAY SINGLE USER ACCOUNT
    ****************************************** */
void display_account(int u_acc){
	ifstream infile;
	bool found=false;
	infile.open("account.dat",ios::binary);
	if(!infile){
		cout<<"the file could`t open";
		return ;
	}
	while(infile.read(reinterpret_cast<char *> (&account), sizeof(bank_managment_system))){
		if(account.acc_no==u_acc){
			cout<<"First_Name: "<<account.f_name<<endl;;
			cout<<"Last_Name: "<<account.l_name<<endl;
			cout<<"ACCOUNT NUM: "<<account.acc_no<<endl;
			cout<<"ACCOUNT TYPE: "<<account.account_type<<endl;
			cout<<"BALANCE: "<<account.deposite<<endl;
			cout<<"ADRESS: "<<account.address<<endl;
			cout<<"PHONE_NUM: "<<account.phone_no<<endl;
			found=true;
			cout<<"***PRESS ANY KEY TO START***";
		}//end of if
	}//end of while loop
	infile.close();
	if(found==false){
		cout<<"!!! SORRY SUCH ACCOUNT DOSN`T EXIST\n";
		cout<<"PRESS ANY KEY BACK TO MAIN MENU\n";
	}//end of if 
}//end of function dispaly_account

/* *************************************
*      FUNCTION TO DISPLAY ALL USER ACCOUNT
******************************************** */

void display_all(){
	system("color 3E");
	ifstream infile;
	infile.open("account.dat",ios::binary);
	if(!infile){
		cout<<"the file could`t open";
		return ;
	}// end of if()
	cout<<"**********ACCOUNT HOLDER LIST AS BELLOW**********\n/n";
	cout<<"==================================================================================\n";
     cout<<"FIRST_NAME LAST_NAME  ACC_NO ACC_TYPE BALANCE  \tADRESS  PHONE_NO\n";
	
	while(infile.read(reinterpret_cast<char *> (&account), sizeof(bank_managment_system))){
     
     cout<<account.f_name<<setw(15)<<account.l_name<<setw(6)<<account.acc_no<<setw(6)<<account.account_type<<setw(10)<<account.deposite<<setw(10)<<account.address<<setw(15)<<account.phone_no<<endl;
	}//end of while loop
	infile.close();
}//END OF FUNCTION DISPLAY_ALL()

/* ************************************************
.   FUNCTION TO DEPOSITE() AND WITHDRAWAL() 
************************************************   */ 

void depo(int u_acc){
	int money;
		bool found=false;
	fstream file;
	file.open("account.dat",ios::binary|ios::in|ios::out);
	if(!file){
		cout<<"SUCH ACCOUNT DOESN`T EXIST";
		return ;
	}//end of if()
	
	while(!file.eof() && found==false){
		file.read(reinterpret_cast<char *> (&account) , sizeof(bank_managment_system));
		if(account.acc_no==u_acc){
			cout<<"======ACCOUNT BEFORE UPDATED=======\n\n\n";
			cout<<"First_Name: "<<account.f_name<<endl;;
			cout<<"Last_Name: "<<account.l_name<<endl;
			cout<<"ACCOUNT NUM: "<<account.acc_no<<endl;
			cout<<"ACCOUNT TYPE: "<<account.account_type<<endl;
			cout<<"BALANCE: "<<account.deposite<<endl;
			
			cout<<"\n\n account update\n\n";
			cout<<"Enter Amount TO Deposite: ";
				cin>>money;
				account.deposite+=money;//end of if for deposite
				int pos=(-1)*static_cast<int>(sizeof(bank_managment_system));
	     file.seekg(pos,ios::cur);
	     file.write(reinterpret_cast<char *> (&account) , sizeof(bank_managment_system));
	     found=true;
		 cout<<"\n\n ACCOUNT UPDATED SUCCESSFULLY";
		}
	
	}//END OF WHILE LOOP
	file.close();
	if(found==false){
		cout<<"\nSUCH ACCOUNT DOSN`T EXIST"<<endl;
		cout<<"\n**PLEASE PRESS ANY KEY TO BACK!!";
	}
			
	
	
}
/* ************************************************
.   FUNCTION TO WITHDRAWAL() 
************************************************   */ 

void with_do(int u_acc){
	int money;
	bool found=false;
	fstream file;
	file.open("account.dat",ios::binary|ios::in|ios::out);
	if(!file){
		cout<<"SUCH ACCOUNT DOESN`T EXIST";
		return ;
	}//end of if()
	
	while(!file.eof() && found==false){
		file.read(reinterpret_cast<char *> (&account) , sizeof(bank_managment_system));
		if(account.acc_no==u_acc){
			cout<<"======ACCOUNT BEFORE UPDATED=======\n\n\n";
			cout<<"First_Name: "<<account.f_name<<endl;;
			cout<<"Last_Name: "<<account.l_name<<endl;
			cout<<"ACCOUNT NUM: "<<account.acc_no<<endl;
			cout<<"ACCOUNT TYPE: "<<account.account_type<<endl;
			cout<<"BALANCE: "<<account.deposite<<endl;
			
			cout<<"\n\n account update\n\n";
			cout<<"Enter Amount TO WITHDRAW: ";
				cin>>money;
				if(money>account.deposite){
			cout<<"INSUFFICIENT BALANCE\n";
			}
			else{
			
				account.deposite-=money;//end of if for deposite
			}
				int pos=(-1)*static_cast<int>(sizeof(bank_managment_system));
	     file.seekg(pos,ios::cur);
	     file.write(reinterpret_cast<char *> (&account) , sizeof(bank_managment_system));
	     found=true;
		 cout<<"\n\n ACCOUNT UPDATED SUCCESSFULLY";
		}
	
	}//END OF WHILE LOOP
	file.close();
	if(found==false){
		cout<<"\nSUCH ACCOUNT DOSN`T EXIST"<<endl;
		cout<<"\n**PLEASE PRESS ANY KEY TO BACK!!";
	}
			
	
}


/* ************************************************
.   FUNCTION TO MODIFY USER ACCOUNT()
************************************************   */ 
void modify_account(int u_acc){
	bool found=false;
	fstream file;
	file.open("account.dat",ios::binary|ios::in|ios::out);
	if(!file){
		cout<<"SUCH ACCOUNT DOESN`T EXIST";
		return ;
	}//end of if()
	
	while(!file.eof() && found==false){
		file.read(reinterpret_cast<char *> (&account) , sizeof(bank_managment_system));
		if(account.acc_no==u_acc){
			cout<<"======ACCOUNT BEFORE UPDATED=======\n\n\n";
			cout<<"First_Name: "<<account.f_name<<endl;;
			cout<<"Last_Name: "<<account.l_name<<endl;
			cout<<"ACCOUNT NUM: "<<account.acc_no<<endl;
			cout<<"ACCOUNT TYPE: "<<account.account_type<<endl;
			cout<<"BALANCE: "<<account.deposite<<endl;
			cout<<"ADRESS: "<<account.address<<endl;
			cout<<"PHONE_NUM: "<<account.phone_no<<endl<<endl;
			
		 cout<<"====== ENTER THE NEW ACCOUNT DETAILS=======\n\n\n";
		 cin.ignore();
	     cout<<"MODIFY FIRST_NAME: ";cin>>account.f_name;
	     cout<<"MODIFY LAST_NAME: ";cin>>account.l_name;
	     cout<<"MODIFY ACCOUNT NUMBER: ";cin>>account.acc_no;
	     cout<<"MODIFY ACCOUNT TYPE (C/S): ";cin>>account.account_type;
	     account.account_type=toupper(account.account_type);
	     cout<<"MODIFY ADRESS: ";cin>>account.address;
	     cout<<"MODIFY PHONE NUMBER: ";cin>>account.phone_no;
	     int pos=(-1)*static_cast<int>(sizeof(bank_managment_system));
	     file.seekg(pos,ios::cur);
	     file.write(reinterpret_cast<char *> (&account) , sizeof(bank_managment_system));
	     found=true;
		 cout<<"\n\n ACCOUNT UPDATED SUCCESSFULLY";
		}
	
	}//END OF WHILE LOOP
	file.close();
	if(found==false){
		cout<<"\nSUCH ACCOUNT DOSN`T EXIST!!!"<<endl;
		cout<<"\n**PLEASE PRESS ANY KEY TO BACK!!";
	}
}//end of modify_account()

void developer_info(){
	system("color B");
	cout<<"======SIFEN & SAMUEL SOFT_WARE DEVELOPMENT======\n\n";
	cout<<"CONTACT US ON : \n";
	cout<<"===============\n";
	cout<<"website: WWW.SAMI_SIFU @GMAIL.COM\n";
	cout<<"TWITTER: @SAMI_SIFU SOFTWARE.DEV\n";
	cout<<"INSTGRAM: @SAMI_SIFU SOFTWARE.DEV\n";
	cout<<"Phone No: +251912345678\n\n";
	cout<<"PRESS ANY KEY BACK TO MANU";
	
}//end of developer_info()



	   


