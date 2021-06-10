// Movie Ticketing System


#include<iostream>
#include<stdlib.h>

using namespace std; 

class Node{
	public:

	// intialize node, seat number, seat status, and the buyer  
	Node* before; 
	Node* link; 
	int seatNum;
	int seatStat; 
	string cosName; 
	
};

class indoXXI{
	public:
	
	Node* first, * last, * temp;
	
	indoXXI()
	{
		first == NULL;
	}

	void addList();
	void displayAll(); 
	void seatBook();
	void cancelBook();
	void seatAvailable();
	
};

void indoXXI::addList(){
// initialize the seat starts from 1 
    int i = 1;
// total seats available
    int numSeat = 50;
    temp = new Node; 
    temp->seatNum = 1; 
    temp->seatStat = 0; 
    temp->cosName = "NULL"; 
    last = first = temp; 
    
	// for the number of seats ( 50 with 10 each rows ) 
       
    for(int i = 2; i <= numSeat; i++)
    {
    	Node *a; 
    	a = new Node;
    	a->seatNum = i;
    	a->seatStat = 0; 
    	a->cosName = "NULL";
    	
		last->link = a;
        a->before = last;
        last = a;
        last->link = first;
        first->before = last;	
	}
}

void indoXXI::displayAll()
{
    {   int i = 1;
        Node* temp;
        temp = first;
        int count = 0;
        
    // diplay the cinema seating 
		cout<<"\n ------------------------------------------------\n";
        cout<<" |               CINEMA SCREEEN                     |\n";
        cout<<"\n -------------------------------------------------\n";

	// display the seats arrangement if its less than 10 it will add 0 infront of a
	// single digit number = 1,2,3,5,6,7,8,9,10

	while(temp->link!= first){
		
        if(temp->seatNum/10 == 0)
            cout<<"0"<<temp->seatNum<<" :";
        else
            cout<<""<<temp->seatNum<<" :";

		// if the seat status is 0 or empty else is booked    
	    if(temp->seatStat ==0)
            cout<<"|___| ";
        else
            cout<<"|_TAKEN_| "; 
			count++;
        
	    if(count%5==0){
            cout<<endl;
            i++;

        }
			temp = temp->link;
        }
            cout<<""<<temp->seatNum<<" :";
            if(temp->seatStat==0)
            cout<<"|___| ";
            else
            cout<<"|_TAKEN_| ";
        
    }
}

void indoXXI::seatBook()
{
	int numSeat; 
	string initial;
	// label allows the user to be redirected the label 
	label: 
	
	cout << " Please choose your seat/s: " << endl; 
	cin >> numSeat;
	
	cout << " Initial: " << endl; 
	cin >> initial; 
	
	// if the chosen no of seat is not available,
	// less than 1 and more than 50 it will return to the label 
	
	if (numSeat<1||numSeat>50)
    {
        cout<<" The seats exceeded the availability :D, please choose other seat: ";
        goto label;
    }
    
    //for checking the status of the seats
    Node *temp;
    temp = new Node;
    temp = first;
    while(temp->seatNum!= numSeat)
    {
        temp=temp->link;
    }
    
    //booked
	if(temp->seatStat == 1)
    cout<<"Selected seats are booked";
    
    // not booked 
	else{
    temp->seatStat = 1;
    temp->cosName = initial;
    cout<<"Selected seats for "<<initial<<" successfully booked!\n";
    }
}


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

	





	
