#include<iostream>
#include<stdlib.h>
#include<D:\CSFILES\COMSCI\C++\final project dsa\Cinema-Ticketing\movie.cpp>

using namespace std;

int main(){
    int choice;
    Movie movielist[5];
    Movie avengers=Movie("Avengers","12:10","12 november 2019");
    Movie interstellar=Movie("Interstellar","13:30","12 november 2019");
    Movie kungfu_panda=Movie("Kung Fu Panda","12:30","12 november 2019");
    Movie pokemon=Movie("Pokemon","14:00","12 november 2019");
    Movie cars=Movie("Cars","13:30","12 november 2019");
    avengers.addList();
    interstellar.addList();
    kungfu_panda.addList();
    pokemon.addList();
    cars.addList();

    movielist[0]=avengers;
    movielist[1]=interstellar;
    movielist[2]=kungfu_panda;
    movielist[3]=pokemon;
    movielist[4]=cars;
    int size=sizeof(movielist)/sizeof(movielist[0]);
    int moviechoice;
    Movie movie;

    do
    {
        cout<<"Welcome to indoXXI"<<endl;
        cout<<"1. Book a Ticket"<<endl;
        cout<<"2. View schedule"<<endl;
        cout<<"3. Cancel a Ticket"<<endl;
        cout<<"4. View account information"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            movie=Movie();
            for(int i=0;i<size;i++){
                cout<<i+1<<"."<<endl;
                cout<<"Movie Name: "<<movielist[i].getTitle()<<endl;
                cout<<"Time: "<<movielist[i].getTime()<<endl;
                cout<<"Date: "<<movielist[i].getDate()<<endl;
            }

            cout<<"Enter the number displayed of the movie: "<<endl;

            cin>>moviechoice;
            if(moviechoice<=size){
                movie=movielist[moviechoice-1];
            }
            else{
                cout<<"Please enter a valid number!"<<endl;
                break;
            }

            cout<<"Movie Name: "<<movie.getTitle()<<endl;
            cout<<"Time: "<<movie.getTime()<<endl;
            cout<<"Date: "<<movie.getDate()<<endl;
            movie.displayAll();
            cout<<endl;

            cout << "1) Book seat" << endl; 
		    cout << "2) Back"<<endl;
            int subchoice;
            cin>>subchoice;
            switch(subchoice){
                case 1:
                movie.seatBook();
                break;
            }
        break;
        case 2:
        for(int i=0;i<size;i++){
                cout<<i+1<<"."<<endl;
                cout<<"Movie Name: "<<movielist[i].getTitle()<<endl;
                cout<<"Time: "<<movielist[i].getTime()<<endl;
                cout<<"Date: "<<movielist[i].getDate()<<endl;
            }
            break;
    }
        
} while (choice!=5);
    
}