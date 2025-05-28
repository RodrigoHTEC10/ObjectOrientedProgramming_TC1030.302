/*
Title: Official Cpp File
Date: May 27, 2025
Description: 
Implementation of the Official header file.
*/
#include <iostream>
#include <string>
#include "Official.h"
#include "Station.h"

using namespace std;

/*Official() is the default constructor of the class*/
Official::Official():Station(){
    noRecharge = 0;
};

/*Official(string name_, string description_, int noRecharge_) is the 
constructor with parameters of the class*/
Official::Official(string name_, string description_, int noRecharge_):Station(name_,  description_){
    noRecharge = noRecharge_;
};

//----------------------------------------------------------
//Getters

/*getNoRecharge() returns the number of recharge points of the Official
station as an integer.*/
int Official::getNoRecharge(){
    return noRecharge;
}

//----------------------------------------------------------
//Setters

/*setNoRecharge(int num) sets the number of recharge points of the Official
station as num*/
void Official::setNoRecharge(int num){
    noRecharge = num;
}

//----------------------------------------------------------
//Methods

/*getinfo() returns all the information of the Official station into 
a string.*/
string Official::getInfo(){
    string text = "Official Station\n";
    text = text + "Name: "+name+"\n"+"Description: "+description+"\n" + "Number of Recharge points: "+to_string(noRecharge)+"\n";
    return text;
};
