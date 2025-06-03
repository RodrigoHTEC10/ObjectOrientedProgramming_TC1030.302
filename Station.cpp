/*
Title: Station Cpp File
Date: June 3, 2025
Description: 
Implementation of the Station header file.
*/
#include <iostream>
#include <string>
#include "Station.h"

using namespace std;

//Constructors

/*Station() is the default constructor of the class.*/
Station::Station(){
    name = "";
    description = "";
};

/*Station(string name_, string description_) is the constructor
 with parameters of the class.*/
Station::Station(string name_, string description_){
    name = name_;
    description = description_;
};

//----------------------------------------------------------
//Getters

/*getName() returns the name of the Station as a string.*/
string Station::getName(){
    return name;
}

//----------------------------------------------------------
//Setters

/*setName(string name_) sets the name of the Station as name_.*/
void Station::setName(string name_){
    name = name_;
};

