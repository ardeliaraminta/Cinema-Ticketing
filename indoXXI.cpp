#include<iostream>
#include<stdlib.h>
#define MAX 50

#include<iostream>
#include<stdlib.h>
#define MAX 50

using namespace std; 

//creating node class
class Node{
	public:

	// intialize node, seat number, seat status, and the customer name  
	Node* before; 
	Node* link; 	
	// seat number, seat status initially 0 == null
	int seatNum;
	int seatStat; 
	// customer initial
	string cosName; 
	
};

//creating queue class
class Queue
{
private:
    //using array for queue
	Node queue[MAX];
    //initializing front and end indices
	int front = -1, rear = -1;

public:
    //queue operations
	void insert(Node);
	void delete_element();
	void display();
};
//push operation
void Queue::insert(Node num){

    //if the alst index is MAX-1, then queue is already full
    if (rear == MAX-1 ){
        cout << "OVERFLOW" << endl; 
    //if queue is empty
    }else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = num;
    //if queue has other elements in it
    }else {
        rear += 1; 
        queue[rear] = num;
    }
}
//pop operation
 void Queue::delete_element() 
{
    Node val;
    // if queue is empty, we cannot perform the delete or pop operation
    if ( front == -1 || front > rear ) {
        cout << "UNDERFLOW" << endl;
    // if not empty then remove the item at the front index
    } else {
        val = queue[front];
        front+=1;
        cout<<"Node popped: "<<endl;
        cout<<val.cosName<<endl;
        cout<<val.seatNum<<endl;
    }
}

//displaying the elements in the queue
void Queue::display()
{
	int i;
	cout << "\n";
    //if queue is empty
	if(front == -1 || front > rear)
		cout << "\n QUEUE IS EMPTY";
    //if not empty then print elements starting from the front index to the rear index
	else
	{
		for(i = front;i <= rear;i++)
			cout<<"Nodes currently in queue: "<<endl;
            cout << queue[i].cosName<<endl;
	}
}

//creating the seating arrangement class
class indoXXI{
	public:
	//initializing pointers
	Node* first, * last, * temp;
    //initializing queue
    Queue q;
	indoXXI()
	{
        //setting the first pointer to null to create an empty linked list
		first == NULL;
	}
    //operations
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
    
    //initializing new node
    temp = new Node; 
    temp->seatNum = 1; 
    temp->seatStat = 0; 
    temp->cosName = "NULL"; 
    last = first = temp; 
    
	// for the number of seats ( 50 with 10 each rows ) 
       
    for(int i = 2; i <= numSeat; i++)
    {
    	// create a node pointer
		// and initialize a new node
    	Node *a; 
    	a = new Node;
    	
    	// set a as the new node 
    	// seat status initially 0 since its null / not booked yet
    	// "cosName" or the customer name/initial's value is initially null 
    	a->seatNum = i;
    	a->seatStat = 0; 
    	a->cosName = "NULL";
    	
    	//create the doubly circular linked list which are nodes that are created using self referential structures
    	//previous node -> next pointer ( find last )
    	
		last->link = a;
		// setting up previous and next of new node
        a->before = last;
        //set the next node
        last = a;
        // make new node next of old last
        last->link = first;
        //make last previous of new node
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

		// if the seat status is 0 or empty
		// it will display blank seat
		// if the seat status is 1     
	    if(temp->seatStat ==0)
            cout<<"|___| ";
        else
            cout<<"|_TAKEN_| "; 
			count++;
        
	    if(count%5==0){
            cout<<endl;
            i++;

        }
        //find node having searched value and next node of it
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
    
    // if the search seat number not equal to the current seat number,
	// it will keep traverse through the seat numbers
	
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
	// change the seat status == 1 
	// change the cosName into the initial entered by the user 
    temp->seatStat = 1;
    temp->cosName = initial;
   
    //enqueue the node
    q.insert(*temp);
    //display queue
    q.display();
    cout<<"Selected seats for "<<initial<<" successfully booked!\n";
    cout<<"Your seat number is: "<<temp->seatNum<<endl;
    //pop queue
    q.delete_element();

    }
}

void indoXXI::cancelBook()
{
	//initialize the seat number and initial to be cancelled
    int n;
	string in;
    
	label1:
    cout<<"Enter your seat number to cancel seat\n";
    cin>>n;
    cout<<"Enter your initial: ";
	cin>>in;
    
    // exception handling 
    // if seat number is out of range of the available seat, it will ask the user to input the correct seat number
    // between 1-50 
    
	if(n<1||n>50)
    {
        cout<<"Invalid. Enter seat number to cancel (1-50)\n";
        goto label1;
    }
    //initialize new temp node which is the head
    Node *temp;
    temp = new Node;
    temp = first;
    
    // while the pointer haven't found the search seat,
	// it will keep traversing until its found the right node of seat Number 
	while(temp->seatNum!=n){
        temp=temp->link;
    }
    
    // if the seat is null or not booked
    if(temp->seatStat==0){
        cout<<"seat not booked yet!!\n";
    }
    else{
    
    // if the cosaName == initial entered ( matched between the two data, previous and the new entry ) 
    // set the seat status = 0
	
	if(temp->cosName==in){
    temp->seatStat = 0;
    cout<<"seat cancelled!\n";
    
	}
	// wrong data / seat number entered , unable to cancel
	else
	cout<<"Seat cannot be cancelled\n";
    }
}


