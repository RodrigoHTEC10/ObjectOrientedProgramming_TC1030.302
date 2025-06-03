/*
Title: Official Header File
Date: June 3, 2025
Description: 
The Official station class refers to those stations which were built for the purpose of being an access point to public transport
in the main avenues of the city. This class stores the specific attribute of number of recharging bus card points as well as its
specific methods.

TESTED: True

*/
#ifndef OFFICIAL_H
#define OFFICIAL_H

#include <iostream>
#include <string>
#include "Station.h"

using namespace std;

class Official : public Station{
    private:
        int noRecharge;

    public:
        //Constructors
        Official();

        Official(string name_, string description_, int noRecharge_);

        //----------------------------------------------------------
        //Methods
        string getInfo() override;

};

#endif