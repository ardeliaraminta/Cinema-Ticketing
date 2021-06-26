#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<list>
#include "indoXXI.cpp"

using namespace std;

//class for Movie Object 
class Movie:public indoXXI{
    public:
    string title;
    string time;
    string date;
    //main constructor
    Movie(string title_entry,string time_entry,string date_entry){
        title=title_entry;
        this->time=time_entry;
        this->date=date_entry;
    };
    //null constructor
    Movie(){

    };

    string getTitle();
    string getTime();
    string getDate();
    void setTitle(string title);
    void setTime(string time);
    void setDate(string date);


};

//getters

string Movie::getTitle(){
  return title;
}

string Movie::getTime(){
  return time;
}

string Movie::getDate(){
  return date;
}

//setters

void Movie::setTitle(string title){
  this->title=title;
}

void Movie::setTime(string time){
  this->time=time;
}

void Movie::setDate(string date){
  this->date=date;
}


  