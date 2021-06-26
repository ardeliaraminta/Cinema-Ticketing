// Movie Ticketing System
#include<iostream>
#include<stdlib.h>
#include<D:\CSFILES\COMSCI\C++\final project dsa\Cinema-Ticketing\indoXXI.cpp>

using namespace std; 


int main (){
	
	indoXXI test;
	test.addList(); 
	int x;
	char z = 'y';
	while(z == 'y'){
		test.displayAll();
		
		cout << "\n\n IndoXXI Cinema" << endl; 
		cout<<" Please enter your choice:\n\n";
		cout << "1) Seat Status" << endl; 
		cout << "2) Book seat "<<endl; 
		cout << "3) Available seat" << endl; 
		
	    cin>>x;
	    switch(x)
	    {
	        case 1:test.displayAll();
	                break;
	        case 2:	test.seatBook();
	                break;
	        case 3: test.addList();
	        		break; 
	        default: cout<<"No Choice\n";
	    }
    }

	return 0;
}    

	





	
