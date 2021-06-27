#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>


using namespace std;

class Account {
private:
	// create variables of user, password, user authentication
    int count;
	// login
    string user,password,usr,pwd;
    //register
    string regUser,regPass,ru,rp;
    
public:
    void accRegister();
    bool accLogin();
    
};
    
bool Account::accLogin(){
    // user name and password
	system("cls");
    cout<<"Please enter"<<endl;
    cout<<"Username :";
    cin>>user;
    cout<<"Password :";
    cin>>password;
    
    //read the text file and compare the user entry and the existing text file
    // for both username and password
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
	
	// then it notifies the customer if the login is unsuccessful or success
    if(count==1)
    {
            cout<<"Hi there "<<user<<"\n Login Successful.\n";
            
            return true;
    }
    else
    {
            cout<<"\n Login Unsuccessful. ";
            return false; 
    }
}
		
void Account::accRegister(){
    system("cls");
    
	cout<<"Enter the username :";
    cin>>regUser;
    
	cout<<"\nEnter the password :";
    cin>>regPass;
    
    // write the data into the text file 
    ofstream reg("customerData.txt",ios::app);
    reg<<regUser<<' '<<regPass<<endl;
    system("cls");
    cout<<"\nRegistration Sucessful\n";
}

        

