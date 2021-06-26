#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

// implementation of register and login of user
// not yet combined 

class Account {
private:
	int count;
    string user,password,usr,pwd;
    string regUser,regPass,ru,rp;
    
public:
	void accRegister();
    void accLogin();
    
};
    
    
void Account::accLogin(){
    
	system("cls");
    cout<<"Please enter"<<endl;
    cout<<"Username :";
    cin>>user;
    cout<<"Password :";
    cin>>password;
    
    ifstream input("customerData.txt");
    while(input>>usr>>pwd)
    {
            if(usr==user && pwd==password)
    
            {
                    count=1;
                    system("cls");
            }
    }
    
	input.close();
    if(count==1)
    {
            cout<<"Hi there "<<user<<"\n Login Successful.\n";
            cin.get();
            cin.get();
    }
    else
    {
            cout<<"\n Login Unsuccessful. ";
    }
}
		
void Account::accRegister(){
    system("cls");
    cout<<"Enter the username :";
    cin>>regUser;
    cout<<"\nEnter the password :";
    cin>>regPass;
    
    ofstream reg("customerData.txt",ios::app);
    reg<<regUser<<' '<<regPass<<endl;
    system("cls");
    cout<<"\nRegistration Sucessful\n";
}
    
        


int main(){
	int choice;
	
	Account acc;
	
	
	do{
		cout<<"Account Registration and Login"<<endl;
		cout<<"1. Log in"<<endl;
		cout<<"2. Register "<<endl;
		cout<<"3. Exit "<<endl;
		cout<<"\nEnter your choice :";
		
		cin>>choice;
	    cout<<endl;
	    
		switch(choice){
		case 1:
			acc.accLogin();
            break;
        case 2:
            acc.accRegister();
            break;
        case 3:
        	return 0;	
        default:
            system("cls");
            cout<<"You've made a mistake , give it a try again\n"<<endl; 
            break;
        }

    } while (choice!=4);
    
}

