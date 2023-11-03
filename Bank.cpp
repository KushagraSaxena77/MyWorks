#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class Bank_Account
{
	
	int Money_Deposit;
	char type;
	int acno;
	char name[70];
public:
	
	void report() const;
	int retMoney_Deposit() const;
	void create_Bank_Account();
	void dep(int);
	int retacno() const;
	void Display_Account() const;
	void Updation();
	char rettype() const;
	void draw(int);
};
 
 
void Bank_Account::Updation()
{
	cout<<"\n\tBank_Account No. : "<<acno;
	cout<<"\n\tUpdation Bank_Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tUpdation Type of Bank_Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tUpdation Balance Total-Money : ";
	cin>>Money_Deposit;
}
void Bank_Account::create_Bank_Account()
{
	system("CLS");
	cout<<"\n\tPlease Enter the Bank_Account No. : ";
	cin>>acno;
	cout<<"\n\n\tPlease Enter the Name of the Bank_Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tPlease Enter Type of the Bank_Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tPlease Enter The Starting Total-Money : ";
	cin>>Money_Deposit;
	cout<<"\n\n\tBank_Account Created..";
}
 
void Bank_Account::Display_Account() const
{
	cout<<"\n\tBank_Account No. : "<<acno;
	cout<<"\n\tBank_Account Holder Name : ";
	cout<<name;
	cout<<"\n\tType of Bank_Account : "<<type;
	cout<<"\n\tBalance Total-Money : "<<Money_Deposit;
}
int Bank_Account::retacno() const
{
	return acno;
}
 
 
 
char Bank_Account::rettype() const
{
	return type;
}
void Bank_Account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<Money_Deposit<<endl;
}
void Bank_Account::dep(int x)
{
	Money_Deposit+=x;
}
void Bank_Account::draw(int x)
{
	Money_Deposit-=x;
}
int Bank_Account::retMoney_Deposit() const
{
	return Money_Deposit;
}
 
 
void write_Bank_Account();
void display_sp(int);
void display_all();
 
void delete_Bank_Account(int);
void Money_Deposit_withdraw(int, int);
void Updation_Bank_Account(int);
int main()
{
	char ch;
	int num;
	do
	{
	system("CLS");
	cout<<"\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	
	cout<<"\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
 
		cout<<"\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t1. NEW Bank_Account";
		cout<<"\n\t\t2. Money_Deposit Total-Money";
		cout<<"\n\t\t3. WITHDRAW Total-Money";
		cout<<"\n\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t5. ALL Bank_Account HOLDER LIST";
		cout<<"\n\t\t6. CLOSE AN Bank_Account";
		cout<<"\n\t\t7. Updation AN Bank_Account";
		cout<<"\n\t\t8. EXIT";
		cout<<"\n\n\t\tSelect Your Option (1-8): ";
		cin>>ch;
 
		switch(ch)
		{
		case '1':
			write_Bank_Account();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Money_Deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Money_Deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			delete_Bank_Account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Updation_Bank_Account(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\tThank you  project by:: \n\tKushagra  Saxena\n\tYash Pokalwar \n\tAnushka Baskota \n\tNamit Kaul";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}