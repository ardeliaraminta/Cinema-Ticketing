#include<iostream>
#include<stdlib.h>
#define MAX 50

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

class Queue
{
private:
	Node queue[MAX];
	int front = -1, rear = -1;

public:
	void insert(Node);
	void delete_element();
	void peek();
	void display();
};

void Queue::insert(Node num){

    //your code
    if (rear == MAX-1 ){
        cout << "OVERFLOW" << endl; 

    }else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = num;
    }else {
        rear += 1; 
        queue[rear] = num;
    }
}

 void Queue::delete_element() 
{
    Node val;
    // your code
    if ( front == -1 || front > rear ) {
        cout << "UNDERFLOW" << endl;
    } else {
        val = queue[front];
        front+=1;
        cout<<"Node popped: "<<endl;
        cout<<val.cosName<<endl;
        cout<<val.seatNum<<endl;
    }
}

void Queue::peek()
{
	if(front==-1 || front>rear)
	{
		cout << "\n QUEUE IS EMPTY";
	}
	else
	{
		 cout<<queue[front].cosName<<endl;
	}
}

void Queue::display()
{
	int i;
	cout << "\n";
	if(front == -1 || front > rear)
		cout << "\n QUEUE IS EMPTY";
	else
	{
		for(i = front;i <= rear;i++)
			cout<<"Nodes currently in queue: "<<endl;
            cout << queue[i].cosName<<endl;
	}
}

class indoXXI{
	public:
	
	Node* first, * last, * temp;
    Queue q;
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
	if(temp->seatStat == 1){
        cout<<"Selected seats are booked";
    }
    
    // not booked 
	else{
    temp->seatStat = 1;
    temp->cosName = initial;
    q.insert(*temp);
    q.display();
    cout<<"Selected seats for "<<initial<<" successfully booked!\n";
    cout<<"Your seat number is: "<<temp->seatNum<<endl;
    q.delete_element();

    }
}

