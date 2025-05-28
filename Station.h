/*
Title: Station Header File (Abstract Class)
Date: May 27, 2025
Description: 
The Station class is the super class pf the Official and Personal subclasses which stores the common attributes and methods
of the registered stations. 

TESTED: True

*/
#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <string>

using namespace std;

class Station{
    protected:
        string name;
        string description;

    public:
        //Constructors
        Station();

        Station(string name_, string description_);

        //----------------------------------------------------------
        //Getters
        virtual string getName();

        string getDescription();

        //----------------------------------------------------------
        //Setters
        void setName(string name_);

        void setDescription(string description);

        //----------------------------------------------------------
        //Methods

        virtual string getInfo() = 0;
};

#endif