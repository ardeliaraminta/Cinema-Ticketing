#include<iostream>
#include<stdlib.h>

// Movie Ticketing System 
// i use . instead of -> becoz im confused, later will be chanegd 


using namespace std; 

class Node{
	public:

	// intialize node, seat number, seat status, and name of the buyer  
	Node* before; 
	Node* link; 
	int seatNum;
	int seatStat; 
	string cosName; 
	
};

class indoXXI{
	public:
	Node* first, *last, *temp;
	
	indoXXI()
	{
		first == nullptr;
	}

	void addList();
	void displayAll(); 
	void seatBook();
	void cancelBook():
	void seatAvailable(); 
	
};

void indoXXI::addList()
{
       
    int i = 1;
    int numSeat = 50
    temp = new Node; 
    temp.seatNum = 1; 
    temp.seatStat = 0; 
    temp.Name = "NULL"; 
    last = first = temp; 
    
	// for the number of seats ( 50 with 10 each rows ) 
       
    for(int i = 2; i <= numSeat; i++)
    {
    	Node *a; 
    	a = new Node;
    	a.seatNum = i;
    	a.seatStat = 0; 
    	a.cosName = "NULL";
    	
	last.link = a;
        a.before = last;
        last = a;
        last.link = first;
        first.before = last;	
	}
}


void indoXXI::displayAll()
{
    {   int i = 1;
        Node* temp;
        temp = first;
        int count = 0;
        
		// diplay the cinema seating 
		cout<<"\n------------------------------------------------------------------------------------\n";
        cout<<"                                CINEMA SCREEEN :P                   	                 \n";
        cout<<"------------------------------------------------------------------------------------\n";
        
		while(temp.link!= first)
        {
            if(temp.seatNum/10 ==0)
            cout<<"0"<<temp.seatNum<<" :";
            else
            cout<<""<<temp.seatNum<<" :";
            
			if(temp.seatStat ==0)
            cout<<"|___| ";
            else
            cout<<"|_TAKEN_| ";
            count++;
            
			if(count%5==0)
            {
            cout<<endl;
            i++;

            }

            temp = temp.link;
        }
            cout<<"S"<<temp->seatNum<<" :";
            if(temp.seatStat==0)
            cout<<"|___| ";
            else
            cout<<"|_TAKEN_| ";

    }
}
	



