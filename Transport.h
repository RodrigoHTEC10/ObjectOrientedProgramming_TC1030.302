/*
Title: Transport Header File (Abstract Class)
Date: May 27, 2025
Description: 
The Transport class is the super class of Bus and Van which stores the shared attributes and gives the common 
functions among the other subclasses.

TESTED: True

*/
#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <vector>
#include <string>
#include "Station.h"

using namespace std;

class Transport{
    protected:
        string name;
        string color;
        string model;
        vector <Station*> stations;

    public:
        //Constructors
        Transport();

        Transport(string name_, string color_, string model_, vector<Station*> stations_);

        //----------------------------------------------------------
        //Getters
        virtual string getName();

        string getColor();

        string getModel();

        vector<Station*> getStations();

        //----------------------------------------------------------
        //Setters
        void setName(string name_);

        void setColor(string color_);

        void setModel(string model_);

        void setStations(vector <Station*> stations_);

        //----------------------------------------------------------
        //Methods

        bool passesBtw(Station* station1, Station* station2);

        virtual string getInfo() = 0;

};

#endif