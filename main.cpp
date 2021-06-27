#include<iostream>
#include<stdlib.h>
#include "movie.cpp"
#include "loginregister.cpp"

using namespace std;
int main(){
    //initialize int variable to store the user's choice for navigation
    int choice;
    
	//creating list for Movie objects
    Movie movielist[5];
    //creating movie objects
    Movie avengers=Movie("Avengers","12:10","12 november 2019");
    Movie interstellar=Movie("Interstellar","13:30","12 november 2019");
    Movie kungfu_panda=Movie("Kung Fu Panda","12:30","12 november 2019");
    Movie pokemon=Movie("Pokemon","14:00","12 november 2019");
    Movie cars=Movie("Cars","13:30","12 november 2019");
    
	//creating seating arrangements for each movie
    avengers.addList();
    interstellar.addList();
    kungfu_panda.addList();
    pokemon.addList();
    cars.addList();
    
	//adding movie objects to the list
    movielist[0]=avengers;
    movielist[1]=interstellar;
    movielist[2]=kungfu_panda;
    movielist[3]=pokemon;
    movielist[4]=cars;
    
	//storing size of movie array
    int size=sizeof(movielist)/sizeof(movielist[0]);
    //for choosing the movie
    int moviechoice;
    //to store the wanted movie chosen by the user
    Movie movie;
    // initiaze new instance to call methods from loginregister.cpp
    Account newAcc;
	 
    	label3:
    	//login main menu 
		do	{
		cout<<"Account Registration and Login"<<endl;
		cout<<"1. Log in"<<endl;
		cout<<"2. Register "<<endl;
		cout<<"3. Exit "<<endl;
		cout<<"\nEnter your choice :";
		
		cin>>choice;
	    cout<<endl;
	    
	    // for login validation
	    bool validation = false; 
	    
		switch(choice){
		case 1:
			// check if the login successful or else it will go to the break label
			validation = newAcc.accLogin();
			break;
        case 2:
        	//register new account 
            newAcc.accRegister();
            break;
        case 3:
        	return 0;	
        default:
            system("cls");
            cout<<"You've made a mistake , give it a try again\n"<<endl; 
            break;
            // if login successful proceed to the booking 
        } if (validation == true){
        	break; 
		}

    } while (choice!=4);
    
	
    do
    {
        //MAIN MENU
        cout<<"Welcome to indoXXI"<<endl;
        cout<<"1. Book and Cancel a Ticket"<<endl;
        cout<<"2. View schedule"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;

        switch (choice)
        {
        //Booking a ticket
        case 1:
            //setting the movie variable into an object without any attributes
            movie=Movie();
            //displaying the movies
            for(int i=0;i<size;i++){
                cout<<i+1<<"."<<endl;
                cout<<"Movie Name: "<<movielist[i].getTitle()<<endl;
                cout<<"Time: "<<movielist[i].getTime()<<endl;
                cout<<"Date: "<<movielist[i].getDate()<<endl;
            }
            //choosing movie
            cout<<"Enter the number displayed of the movie: "<<endl;
            cin>>moviechoice;
            //setting the movie variable to the movie object chosen by the user
            //subtract 1 because indices start at 0
            if(moviechoice<=size){
                movie=movielist[moviechoice-1];
            }
            else{
                cout<<"Please enter a valid number!"<<endl;
                break;
            }
			//showing the seating arrangement of the movie
            cout<<endl;
            cout<<"Movie Name: "<<movie.getTitle()<<endl;
            cout<<"Time: "<<movie.getTime()<<endl;
            cout<<"Date: "<<movie.getDate()<<endl;
            movie.displayAll();
            cout<<endl;
            //booking the seat
            cout << "1) Book seat" << endl; 
		    cout << "2) Cancel Book"<<endl;
		    cout << "3) Main Menu"<<endl;
            int subchoice;
            cin>>subchoice;
            switch(subchoice){
                case 1:
                //calling the seatBook function to book seat for the user
                movie.seatBook();
                break;
                case 2:
                movie.cancelBook();
                break;
            }
        break;
        //displaying the schedule of movies
        case 2:
        for(int i=0;i<size;i++){
                cout<<i+1<<"."<<endl;
                cout<<"Movie Name: "<<movielist[i].getTitle()<<endl;
                cout<<"Time: "<<movielist[i].getTime()<<endl;
                cout<<"Date: "<<movielist[i].getDate()<<endl;
            }
            break;
    }
        
} while (choice!=4);
    
}
