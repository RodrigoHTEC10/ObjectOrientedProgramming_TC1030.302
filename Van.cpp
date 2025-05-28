/*
Title: Van Cpp File
Date: May 27, 2025
Description: 
Implementation of the Van header file.
*/
#include <iostream>
#include <string>
#include "Van.h"
#include "Transport.h"

using namespace std;

/*Van() is the default constructor of the class.*/
Van::Van():Transport(){};

/*Van(string name_, string color_, string model_, vector<Station*> 
stations_) is the constructor with parameters of the class.*/
Van::Van(string name_, string color_, string model_, vector<Station*> stations_):Transport(name_, color_, model_, stations_){};

//----------------------------------------------------------
//Methods

/*getinfo() returns all the information of the Bus into a string.*/
string Van::getInfo(){
    string text = "Van Information: \n";
    text = text + "Name: "+name+"\n"+"Color: "+color+"\n"+"Model: "+model+"\n"+"Stations: \n";
    for (int i = 0; i<stations.size(); i++){
        text = text + "     "+to_string(i+1)+" "+(*stations[i]).getName()+" \n";
    }
    return text;
};