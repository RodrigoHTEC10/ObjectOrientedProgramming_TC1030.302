/*
Title: Record Header File
Date: June 3, 2025
Description: 
The Record class handles the storing, accessing and removing of the transport routes among the registered bus and van
Official and Personal stations.

TESTED: True

*/
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>
#include <string>

#include "Station.h"
#include "Official.h"
#include "Personal.h"
#include "Transport.h"
#include "Bus.h"
#include "Van.h"

using namespace std;

class Record{
    private:
        vector <Transport*> transports;
        vector <Station*> stations;

    public:
        //Constructors
        Record();
            
        Record(vector <Transport*> transports_, vector <Station*> stations_);

        //----------------------------------------------------------
        //Getters
        Transport* getTransport(int num);

        vector <Transport*> getTransport();

        Station* getStation(int num);

        vector <Station*> getStation();


        //----------------------------------------------------------
        //Methods

        string addTransport(Transport* transport_);

        string addStation(Station* station_);

        string operator-=(int num);

        string operator!=(int num);

        string operator++();

        string showAll(string record);

        string showTransportInfo(int num);

        string showStationInfo(int num);

        string transportsBtwStation(Station* station1, Station* station2);

};

#endif