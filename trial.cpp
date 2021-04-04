#include<iostream>
#include<stdlib.h>
#include<CinemaTrial.h>
    
int main (){
	indoXXI test; 
	test.addList(); 
	int x;
	char z = 'y';
	while(z == 'y'){
		test.displayAll();
		
		cout << "\nIndoXXI Cinema" << endl; 
		cout<<" Please enter your choice:\n\n";
		cout << "1) Seat Status" << endl; 
		cout << "2) Book seat "<<endl; 
		cout << "3) Available seat" << endl; 
		
		
		
		
	    cin>>x;
	    switch(x)
	    {
	        case 1:test.displayAll();
	                break;
	        case 2:	test.addList();
	                break;
	        case 3: test.seatBook();
	        		break; 
	        default: cout<<"No Choice\n";
	    }
	    cout<<"\n Please enter your choice: (y/n)\n";
	    cin>> z;
		system("clear");
    }

	return 0;
}    

	
