/*
Title: Personal Header File
Date: May 27, 2025
Description: 
The Personal station class refers to those smaller stations around the city which are registered by the user. 
This class stores the specific methods of the Personal Stations.

TESTED: True
*/
#ifndef PERSONAL_H
#define PERSONAL_H

#include <iostream>
#include <string>
#include "Station.h"

using namespace std;

class Personal : public Station{

    public:
        //Constructors
        Personal();

        Personal(string name_, string description_);

        //----------------------------------------------------------
        //Methods
        string getInfo() override;

};

#endif