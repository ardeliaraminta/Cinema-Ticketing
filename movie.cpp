#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<list>
#include<D:\CSFILES\COMSCI\C++\final project dsa\Cinema-Ticketing\indoXXI.cpp>

using namespace std;

class Movie:public indoXXI{
    public:
    string title;
    string time;
    string date;

    Movie(string title_entry,string time_entry,string date_entry){
        title=title_entry;
        this->time=time_entry;
        this->date=date_entry;
    };

    Movie(){

    };

    string getTitle();
    string getTime();
    string getDate();
    void setTitle(string title);
    void setTime(string time);
    void setDate(string date);


};

string Movie::getTitle(){
  return title;
}

string Movie::getTime(){
  return time;
}

string Movie::getDate(){
  return date;
}

void Movie::setTitle(string title){
  this->title=title;
}

void Movie::setTime(string time){
  this->time=time;
}

void Movie::setDate(string date){
  this->date=date;
}


  