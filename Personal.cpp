/*
Title: Personal Cpp File
Date: May 27, 2025
Description: 
Implementation of the Personal header file.
*/
#include <iostream>
#include <string>
#include "Personal.h"
#include "Station.h"

using namespace std;

/*Personal() is the default constructor of the class*/
Personal::Personal():Station(){};

/*Personal(string name_, string description_) is the constructor
with parameters of the class*/
Personal::Personal(string name_, string description_):Station(name_, description_){};

//----------------------------------------------------------
//Methods

/*getinfo() returns all the information of the Personal station into 
a string.*/
string Personal:: getInfo(){
    string text = "Personal Station\n";
    text = text + "Name: "+name+"\n"+"Description: "+description+"\n";
    return text;
};


