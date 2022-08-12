#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

 int main()
 {
 	int c;
 	cout<<"\t\t\t_______________\n\n\n";
 	cout<<"\t\t\t            welcom to login page         \n\n\n";
 	cout<<"\t\t\t______menu_________\n\n";
    cout<<"                                                  \n\n";
 	cout<<"\t| press 1 to login                         |"<<endl;
 	cout<<"\t| press 2 to register                      |"<<endl;
 	cout<<"\t| press 3 if you forget your password      |"<<endl;
 	cout<<"\t| press 4 to exit                          |"<<endl;
 	cout<<"\n\t\t\t please enter your choice:";
 	cin>>c;
 	cout<<endl;
 	
 	switch(c)
	 {
 		case 1:
 		        login();
 			    break;
 			
 		case 2:
 				registration();
 				break;
 		case 3:
		        forgot();
		        break;
		case 4:
			    cout<<"\t\t\t THANKYOU !!  \n\n";
			    break;
		default:
			system("cls");
			cout<<"\t\t\t\t please select from option given above \n"<<endl;
			main();
	 }
 	
 }
void login()
{
	int count;
	string userId, password, Id, pass;
	system("cls");
	cout<<"\t\t\t please enter the username and password:"<<endl;
	cout<<"\t\t\t USERNAME : ";
	cin>>userId;
	cout<<"\t\t\t PASSWARD : ";
	cin>>password;
	ifstream input;
	input.open("records.txt");


	while(input>>Id>>pass)
	{
		if(Id==userId && pass==password)
		{
			count = 1;
			system("cls");
			
		}
		
	}
	input.close();
	
	if(count==1)
	{
		cout<<userId<<"\n your login is successfull \n thanks for logging in! \n";
		main();
	}
	else{
		cout<<"\n login error \n please check your name and passward \n";
		main();
	}
	
}
void registration(){
	string  ruserId, rpassword, rId, rpass;
	system("cls");
	cout<<"\t\t\t enter the username: ";
	cin>>ruserId;
	cout<<" \t\t\t enter the password:";
	cin>>rpassword;
	
	ofstream f1("records.txt", ios::app);
	f1<<ruserId<<' '<<rpassword<<endl;
	system(" cls");
	cout<<"\n\t\t\t registration is successfull! \n";
	main();
}
void forgot(){
	int option;
	system("cls");
	cout<<"\t\t\t\t tou forgot the password ? no worries \n";
	cout<<"press 1 to search your id by username"<<endl;
	cout<<"press 2 to go back main menu"<<endl;
	cout<<"\t\t\t enter your choice :";
	cin>>option;
	switch(option)
	{
		case 1:
		{
			int count=0;
			string suserId, sId, spass;
			cout<<"\n\t\t enter the username which you remember:";
			cin>>suserId;
			
			ifstream f2("records.txt");
			while(f2>>sId>>spass)
			{
				if(sId==suserId)
				{
					count=1;
				}
			}
			f2.close();
			if(count==1)
			{
				cout<<"\n\n\n your account is found\n";
				cout<<"\n\\n\n your password id : "<<spass;
				main();
			}
			else{
				cout<<"\n\t sorry! your account is not found!\n";
				main();
			}
			break;
		}
		case 2:
			{
				main();
			}
			default:
				cout<<"\t\t\t woring choice ! please try again "<<endl;
				forgot();
	}
}
