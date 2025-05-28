/*
Title: Bus Cpp File
Date: May 27, 2025
Description: 
Implementation of the Bus header file.
*/
#include <iostream>
#include <string>
#include "Bus.h"
#include "Transport.h"

using namespace std;

/*Bus() is the default constructor of the class.*/
Bus::Bus():Transport(){
    noEntries = 0;
};

/*Bus(string name_, string color_, string model_, vector<Station*> 
stations_, int noEntries_) is the constructor with parameters*/
Bus::Bus(string name_, string color_, string model_, vector<Station*> stations_, int noEntries_):Transport(name_, color_, model_, stations_){
    noEntries = noEntries_;
};

//----------------------------------------------------------
//Getters

/*getNoEntries() returns the number of entries the bus has as an int.*/
int Bus::getNoEntries(){
    return noEntries;
};

//----------------------------------------------------------
//Setters

/*setNoEntries(int noEntries_) sets the number of entries the bus as the 
noEntries_ integer.*/
void Bus::setNoEntries(int noEntries_){
    noEntries = noEntries_;
};

//----------------------------------------------------------
//Methods


/*getinfo() returns all the information of the Bus into a string.*/
string Bus::getInfo(){
    string text = "Bus Information: \n";
    text = text +"Name: "+name+"\n"+"Color: "+color+"\n"+"Model: "+model+"\n"+"Stations: \n";
    for (int i = 0; i<stations.size(); i++){
        text = text + "     "+to_string(i+1)+" "+(*stations[i]).getName()+" \n";
    }
    text = text + "Number of Entries to the Bus: "+to_string(noEntries)+"\n";
    return text;
};
