/*
Title: Van Header File
Date: May 27, 2025
Description: 
The Van class is a sub class of the Transport class, specific methods of Van are defined in this class.

TESTED: True

*/
#ifndef VAN_H
#define VAN_H

#include <iostream>
#include <string>
#include "Transport.h"

using namespace std;

class Van : public Transport{

    public:
        //Constructors
        Van();

        Van(string name_, string color_, string model_, vector<Station*> stations_);

        //----------------------------------------------------------
        //Methods
        string getInfo() override;

};

#endif