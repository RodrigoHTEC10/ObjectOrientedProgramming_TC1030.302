/*
Title: Transport Header File
Date: May 27, 2025
Description: 
The Transport class is the super class of Bus and Van which stores the shared attributes and gives the common 
functions among the other subclasses.

TESTED: True

*/
#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <string>
#include "Transport.h"

using namespace std;

class Bus : public Transport{

    private:
        int noEntries;

    public:
        //Constructors
        Bus();

        Bus(string name_, string color_, string model_, vector<Station*> stations_, int noEntries_);

        //----------------------------------------------------------
        //Getters
        int getNoEntries();

        //----------------------------------------------------------
        //Setters
        void setNoEntries(int noEntries_);

        //----------------------------------------------------------
        //Methods
        string getInfo() override;

};

#endif