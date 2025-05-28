/*
Title: Record Cpp File
Date: May 27, 2025
Description: 
Implementation of the Record Header File methods.
*/
#include <iostream>
#include <vector>
#include <string>
#include "Station.h"
#include "Official.h"
#include "Personal.h"
#include "Transport.h"
#include "Bus.h"
#include "Van.h"
#include "Record.h"

using namespace std;

/*Record() is the default contructor which creates a default object 
in each vector.*/
Record::Record(){
    Bus temporalBus = Bus();
    transports.push_back(&temporalBus);
    Official temporalOfficial = Official();
    stations.push_back(&temporalOfficial);
};

/*Record(vector <Transport*> transports_, vector <Station*> stations_) 
is the constructor with parameters that takes the elements of the 
vectors entered as parameters (transports_, stations_) and push them 
back into the storage vectors.*/
Record::Record(vector <Transport*> transports_, vector <Station*> stations_){
    for (int i = 0; i < stations_.size(); i++){
        stations.push_back(stations_[i]);
    }
        
    for (int i = 0; i < transports_.size(); i++){
        transports.push_back(transports_[i]);
    }
};

//----------------------------------------------------------
//Getters

/*getTransport(int num) returns the Transport pointer stored in the 
index num-1 of the vector transports.*/
Transport* Record::getTransport(int num){
    return transports[num-1];
};

/*getTransport() returns the vector of Transport pointers*/
vector <Transport*> Record::getTransport(){
    return transports;
};

/*getStation(int num) returns the Station pointer stored in the index 
num-1 of the vector stations.*/
Station* Record::getStation(int num){
    return stations[num-1];
};

/*getStation() returns the vector of Station pointers*/
vector <Station*> Record::getStation(){
    return stations;
};


//----------------------------------------------------------
//Setters

/*setTransports(vector <Transport*> transports_) takes the elements of
the vector entered as a parameter (transports_) and push them back
into the storage vector.*/
void Record::setTransports(vector <Transport*> transports_){
    int size = transports.size();
    for(int i = 0; i < size ; i++){
        transports.pop_back();
    }
    
    for (int i = 0; i < transports_.size(); i++){
        transports.push_back(transports_[i]);
    }
};

/*setStations(vector <Station*> stations_) takes the elements of the 
vector entered as a parameter (stations_) and push them back into 
the storage vector.*/
void Record::setStations(vector <Station*> stations_){
    int size = stations.size();
    for(int i = 0; i < size; i++){
        Record::stations.pop_back();
    }
     
    for (int i = 0; i < stations_.size(); i++){
        stations.push_back(stations_[i]);
    }
};

//----------------------------------------------------------
//Methods

/*addTransport(Transport* transport_) allows to add the transport_ 
pointer to the storage vector transports.
Returns a string that confirms the process.*/
string Record::addTransport(Transport* transport_){
    transports.push_back(transport_);
    return (*transports[transports.size()-1]).getName()+" has been succesfully added.\n";
};

/*addStation(Station* atation_) allows to add the station_ pointer
to the storage vector stations.
Returns a string that confirms the process.*/
string Record::addStation(Station* station_){
    stations.push_back(station_);
    return (*stations[stations.size()-1]).getName()+" has been succesfully added.\n";
};

/*eliminateTransport(int num) allows to erase from the storage 
vector transports, the Transport pointer located at
the num th place of the vector.
Returns a string that confirms the process.*/
string Record::eliminateTransport(int num){
    transports.erase(transports.begin()+(num-1));
    return "Tranport eliminated\n";
};

/*eliminateStation(int num) allows to erase from the storage 
vector stations, the Station pointer located at the num th place of
the vector.
Returns a string that confirms the process.*/
string Record::eliminateStation(int num){
    stations.erase(stations.begin()+(num-1));
    return "Station eliminated\n";
};

/*showAll() returs all the names of the transports and stations 
registered into a string.*/
string Record::showAll(){
    string text = "Transports registered: \n";
    for (int i = 0; i < transports.size(); i++){
        text = text +to_string(i+1)+ ". "+(*transports[i]).getName() +"\n";
    }
    text = text + "\n";
    
    text = text + "Stations registered: \n";
    for (int i = 0; i < stations.size(); i++){
        text = text + to_string(i+1)+ ". "+ (*stations[i]).getName()+"\n";
    }
    text = text + "\n";
    return text;

};

/*showAll() returs all the names of the transports or stations registered
into a string depending on the string received. If record is equal to
"Stations" will return the station names, otherwise the transport names.*/
string Record::showAll(string record){
    if(record == "Stations"){
        string text = "Stations registered: \n";
        for (int i = 0; i < stations.size(); i++){
            text = text + to_string(i+1)+ ". "+ (*stations[i]).getName()+"\n";
        }
        text = text + "\n";
        return text;
    }
    else{
        string text = "Transports registered: \n";
        for (int i = 0; i < transports.size(); i++){
            text = text +to_string(i+1)+ ". "+(*transports[i]).getName()+"\n";
        }
        text = text + "\n";
        return text;
    };
}

/*showTransportInfo(int num) returns the information of the specified 
Tranport object located in the index num-1 of the transports vector
into a string.*/
string Record::showTransportInfo(int num){
    string text = (*transports[num-1]).getInfo();
    return text;
};

/*showStationInfo(int num) returns the information of the specified 
Station object located in the index num-1 of the stations vector 
into a string.*/
string Record::showStationInfo(int num){
    string text = (*stations[num-1]).getInfo();
    return text;
};

/*transportsBtwStation(Station station1, Station station2) returns 
a string which contains all the transports which pass through the
two Station objects entered as parameters.*/
string Record::transportsBtwStation(Station* station1, Station* station2){
    vector <int> transportTrue;

    for(int i = 0; i<transports.size();i++){
        if((*transports[i]).passesBtw(station1, station2)){
            transportTrue.push_back(i);
        }
    }

    string text = "The transports that pass between "+(*station1).getName() +" and "+(*station2).getName()+":  \n";
    
    if(transportTrue.size() > 0){
        for(int i = 0; i<transportTrue.size();i++){
            text = text + to_string(i+1)+". "+(*transports[transportTrue[i]]).getName()+" \n";
        }
    }
    else{
        text = text + "None";
    }

    

    return text;
};