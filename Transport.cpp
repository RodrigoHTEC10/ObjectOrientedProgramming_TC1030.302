/*
Title: Transport Cpp File
Date: May 27, 2025
Description: 
Implementation of the Transport header file.
*/
#include <iostream>
#include <string>
#include "Transport.h"
#include "Station.h"
#include "Official.h"

using namespace std;

//Constructors
/*Transport() is the default constructor of the class.*/
Transport::Transport(){
    name = "";
    color = "Black";
    model = "";
    Official officialSta = Official();
    stations.push_back(&officialSta);

};

/*Transport(string name_, string color_, string model_, vector<Station*> 
stations_) stores the parameters as the protected attributes of 
the class.*/
Transport::Transport(string name_, string color_, string model_, vector<Station*> stations_){
    name = name_;
    color = color_;
    model = model_;
    for (int i = 0; i < stations_.size(); i++)
        stations.push_back(stations_[i]);
};

//----------------------------------------------------------
//Getters

/*getName() returns the name of the transport as a string.*/
string Transport::getName(){
    return name;
}


/*getColor() returns the color of the transport as a string.*/
string Transport::getColor(){
    return color;
};

/*getModel() returns the model of the transport as a string.*/
string Transport::getModel(){
    return model;
};

/*getStations() return the vector of Station pointers that the transport
passed.*/
vector<Station*> Transport::getStations(){
    return stations;
};

//----------------------------------------------------------
//Setters

/*setName(string name_) sets the name of the Tranport as the string
name_.*/
void Transport::setName(string name_){
    name = name_;
};

/*setColor(string color_) sets the color of the Tranport as the string
color_.*/
void Transport::setColor(string color_){
    color = color_;
};

/*setModel(string model_) sets the model of the Tranport as the string
model_.*/
void Transport::setModel(string model_){
    model = model_;
};

/*setStations(vector <Station*> stations_) sets the stations of the 
Tranport as elements of the stations_ vector.*/
void Transport::setStations(vector<Station*> stations_){
    int size = stations.size();
    for(int i = 0; i < size; i++){
        stations.pop_back();
    }
    
    for (int i = 0; i < stations_.size(); i++)
        stations.push_back(stations_[i]);
};

//----------------------------------------------------------
//Methods

/*passesBtw(Station* station1, Station* station2) returns a bool in case
the transport passes through the two Stations pointers entered as parameters.*/
bool Transport::passesBtw(Station* station1, Station* station2){
    bool station1Part = false;
    bool station2Part = false;
    for(int i = 0; i < stations.size(); i++){
        if((*station1).getName() == (*stations[i]).getName()){
            station1Part = true;
        }
        if((*station2).getName() == (*stations[i]).getName()){
            station2Part = true;
        }
    }

    if(station1Part == true && station2Part == true){
        return true;
    }
    else{
        return false;
    }
};
