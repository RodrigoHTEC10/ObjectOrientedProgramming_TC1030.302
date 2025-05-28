/*
Title: Main Cpp File
Date: May 28, 2025
Description: 
The present file is the core of the user interaction and will use
every single class created and declared below. Additionally, the 
addition of polymorfism and adaptation of the workspace.
*/
#include <iostream>
#include <vector>
#include <string>

#include "Station.cpp"
#include "Official.cpp"
#include "Personal.cpp"
#include "Transport.cpp"
#include "Bus.cpp"
#include "Van.cpp"
#include "Record.cpp"

using namespace std;

//---------------------------------------------------
//Auxiliar functions

/*mainMenu() is a function that prints the principal option menu of the
program and receives an integer as an input with returns.*/
int mainMenu(){
    int election;
    cout<<""<<endl;
    cout<<"---Main Menu----"<<endl;
    cout<<"Choose one of the following options:"<<endl;
    cout<<""<<endl;
    cout<<"1. Review all Stations and Transports."<<endl;
    cout<<"2. Review all Stations or Transports."<<endl;
    cout<<"3. Add a new Station or Transport."<<endl;
    cout<<"4. Eliminate a Station or Transport."<<endl;
    cout<<"5. Get the information of a specific Station or Transport."<<endl;
    cout<<"6. Check Transports between two Stations."<<endl;
    cout<<"7. Exit."<<endl;
    cout<<""<<endl;
    cout<<"Enter the chosen option number:"<<endl;
    cin>>election;
    cout<<""<<endl;
    return election;
};

/*selectStationsBtw(Record record) allows the implementation of choosing two stations and continue
with the printing of the return of transportsBtwStation() by accessing the stations stored in the
Record object needed as a parameter.*/
void selectStationsBtw(Record record){
    vector <Station*> currentSta = record.getStation();
    int station1;
    int station2;
        
    cout<<"Avaliable stations: "<<endl;
    for(int i =0; i<currentSta.size();i++){
        cout<<i+1<<". "+(*currentSta[i]).getName()<<endl;
    }

    cout<<" "<<endl;
    cout<<"Enter the number of the first station to add it: "<<endl;
    cin>>station1;
    if(station1 > 0 && station1 < record.getStation().size()){
        cout<<" "<<endl;
        cout<<"Enter the number of the first station to add it: "<<endl;
        cin>>station2;

        if(station2 > 0 && station2 < record.getStation().size()+1){
            cout<<" "<<endl;
            cout<<record.transportsBtwStation(record.getStation(station1), record.getStation(station2))<<endl;
        }
        else{
            cout<<"Invalid Option. Coming back to Main Menu."<<endl;
        }
    }
    else{
        cout<<"Invalid Option. Coming back to Main Menu."<<endl;
    } 
}


/*selectStations(Record record) allows to choose the stations of a 
specific transport based on the avaliable stations at the Record
object, returning a vector of Pointers referring to the chosen
stations.*/
vector <Station*> selectStations(Record record){
    vector <Station*> selection;
    vector <Station*> currentSta = record.getStation();

    int num;
    bool done = false;
        
    cout<<" "<<endl;
    cout<<"Avaliable stations: "<<endl;
    for(int i =0; i<currentSta.size();i++){
        cout<<i+1<<". "+(*currentSta[i]).getName()<<endl;
    }
    cout<<" "<<endl;
    cout<<"Enter the number of a station to add it: "<<endl;

    while(done == false){
        cin>>num;
        cout<<" "<<endl;
        if(num == 0){
            done = true;
        }
        else{
            if(num > 0 && num < record.getStation().size()+1){
                selection.push_back(record.getStation(num));
                cout<<"Enter another number of a station to add it: (To stop adding stations type 0)"<<endl;
            }
            else{
                cout<<"Invalid Option: Try Again "<<endl;
                cout<<"Enter another number of a station to add it: (To stop adding stations type 0)"<<endl;
            }
        }
    }

    return selection;
};


/*selectModels(int num) returns a string corresponding to the selection 
of a specific model by the user.*/
string selectModels(int num){
    if(num==2){
        return "Van";
    }
    else{
        int selection;
        vector <string> models = {"Old model","Medium Model","Modern Model"};

        cout<<"Choose one of the following models:"<<endl;
        for(int i=0; i<models.size();i++){
            cout<<i+1<<". "+models[i]<<endl;
        }
        cout<<" "<<endl;
        cout<<"Enter your selection number: "<<endl;
        cin>>selection;
        cout<<" "<<endl;
        string t = models[selection-1];
        return t;
    }
    
    return "No Model";
};



//---------------------------------------------------
/*main() method contain the overall interactions with the user
with the support of other functions declared in the present file.
At the end, it returns a 0.*/
int main(){
    bool finish = false;


    //Default Stations Declaration
    Official ejercito_revolucionario("Station Ejercito Revolucionario", "Station located in front of Plaza de las Americas in Constituyentes avenue.",2);
    Official el_pocito("Station El Pocito","Station located over Constituyentes avenue before the golf course.",0);
    Personal tec("Station Soriana-Tec","Station next to the North entry to the Tec.");
    Personal hidalgo("Station Hidalgo's Market","Station located next to the market at Hidalgo and Ocampo streets.");

    vector<Station*> stat = {&ejercito_revolucionario, &el_pocito, &tec, &hidalgo};

    //Default Transports Declaration
    vector<Station*> t01est = {&ejercito_revolucionario,&el_pocito};
    vector<Station*> c21est = {&el_pocito};
    vector<Station*> t07est = {&tec, &hidalgo};
    vector<Station*> van07 = {&ejercito_revolucionario};

    Bus t01("T01","Orange","Modern Model",t01est,3);
    Bus c21("C21","Green","Modern Model",c21est,3);
    Bus t07("T07","Orange","Old model",t07est,2);
    Van v07("Van 07","Green","Van",van07);

    vector<Transport*> transp = {&t01, &c21, &t07, &v07};

    //Creation of the record Object
    Record official = Record(transp, stat);

    //Introduction to the program
    cout<<"Welcome to you Personal Queretaro's Public Transport Record"<<endl;
    cout<<" "<<endl;
    cout<<"The current registered stations and transports are the following: "<<endl;
    cout<<official.showAll()<<endl;


    /*Cycle of the functionalities of the program, depending on the 
    decision taken, the functionalities of each case in the switch will
    be implemented. */
    while(finish == false){

        int decision = mainMenu();

        switch (decision) {


        /*Review all Stations and Transports.*/
//----------------------------------------------------------------------
        case 1:{
            cout<<" "<<endl;
            cout<<official.showAll()<<endl;
            cout<<" "<<endl;
        }break;

        /*Review all Stations or all Transports.*/
//----------------------------------------------------------------------
        case 2:{
            int decision;
            cout<<" "<<endl;
            cout<<"Choose which option to review: "<<endl;
            cout<<"1. Stations."<<endl;
            cout<<"2. Transports."<<endl;
            cin >>decision;
            cout<<" "<<endl;
            
            switch (decision)
            {
            case 1:{
                cout<<official.showAll("Stations")<<endl;
                cout<<" "<<endl;
            }break;

            case 2:{
                cout<<official.showAll("Transports")<<endl;
                cout<<" "<<endl;
            }break;
            
            default:{
                cout<<"Invalid Option. Coming back to Main Menu."<<endl;
            }break;
            }

        }break;

        /*Add a new Station or Transport*/
//----------------------------------------------------------------------
        case 3:{

            int decision;
            cout<<" "<<endl;
            cout<<"Choose which option to add: "<<endl;
            cout<<"1. Stations."<<endl;
            cout<<"2. Transports."<<endl;
            cout<<"Enter the number of your selection: "<<endl;
            cin >>decision;
            cout<<" "<<endl;
            
            switch (decision)
            {
            
            /*Choosing a Station type*/
            //********************************************************************** */
            case 1:{
                string name;
                string description;

                cout<<" "<<endl;
                cout<<"Choose which type of Station would you like to add: "<<endl;
                cout<<"1. Official."<<endl;
                cout<<"2. Personal."<<endl;
                cout<<"Enter the number of your selection: "<<endl;
                cin >>decision;
                cout<<" "<<endl;
                
                switch (decision)
                {
                /*Adding an Official Station*/
                // =====================================================================
                case 1:{
                    
                    int rechargePoints;

                    cout<<"Enter your Station name: "<<endl;
                    cin.ignore();
                    getline(cin, name);

                    cout<<"Enter your Station description: "<<endl;
                    getline(cin, description);

                    cout<<"Enter the avaliable recharge points at the station: (Numeric value)"<<endl;
                    cin>>rechargePoints;

                    Official *off = new Official(name, description, rechargePoints);
                    cout<<official.addStation(off)<<endl;

                }break;

                /*Adding a Personal Station*/
                // =====================================================================
                case 2:{
                    cout<<"Enter your Station name: "<<endl;
                    cin.ignore();
                    getline(cin, name);

                    cout<<"Enter your Station description: "<<endl;
                    getline(cin, description);

                    Personal *person = new Personal(name, description);
                    cout<<official.addStation(person)<<endl;

                }break;
                // =====================================================================
                default:{
                    cout<<"Invalid Option. Coming back to Main Menu."<<endl;
                }break;
                }

            }break;

            /*Choosing a Transport type*/
            //********************************************************************** */
            case 2:{
                string name;
                string color;
                string model;
                vector <Station*> stations;

                cout<<" "<<endl;
                cout<<"Choose which type of Transport would you like to add: "<<endl;
                cout<<"1. Bus."<<endl;
                cout<<"2. Van."<<endl;
                cin >>decision;
                cout<<" "<<endl;
                
                switch (decision)
                {
                /*Adding a Bus Transport*/
                // =====================================================================
                case 1:{
                    int entries;

                    cout<<"Enter your Transport name: "<<endl;
                    cin.ignore();
                    getline(cin, name);

                    cout<<"Enter your Transport color: "<<endl;
                    getline(cin, color);
                    model = selectModels(decision);
                    cout<<model<<endl;
                    stations = selectStations(official);

                    cout<<"Enter the avaliable entries of the Bus: (Numeric value)"<<endl;
                    cin>>entries;

                    Bus *bus = new Bus(name, color, model, stations, entries);
                    cout<<official.addTransport(bus)<<endl;

                }break;

                /*Adding a Van Transport*/
                // =====================================================================
                case 2:{

                    cout<<"Enter your Transport name: "<<endl;
                    cin.ignore();
                    getline(cin, name);

                    cout<<"Enter your Transport color: "<<endl;
                    getline(cin, color);
                    model = selectModels(decision);
                    stations = selectStations(official);


                    Van *van = new Van(name, color, model, stations);
                    cout<<official.addTransport(van)<<endl;

                }break;
                // =====================================================================
                default:{

                    cout<<"Invalid Option. Coming back to Main Menu."<<endl;

                }break;
                }
                
            }break;
            //********************************************************************** */
            default:{
                cout<<"Invalid Option. Coming back to Main Menu."<<endl;
            }break;
            }

        }break;
        
        /*Eliminating an object*/
//----------------------------------------------------------------------
        case 4:{
            
            int decision;
            cout<<" "<<endl;
            cout<<"Choose which type of element would you like to remove: "<<endl;
            cout<<"1. Stations."<<endl;
            cout<<"2. Transports."<<endl;
            cout<<"Enter the number of your selection: "<<endl;
            cin >>decision;
            cout<<" "<<endl;

            switch (decision)
            {
            /*Eliminate a chosen Station*/
            //********************************************************************** */
            case 1:{

                cout<<"Which of the following stations would you like to remove: "<<endl;
                cout<<official.showAll("Stations")<<endl;
                cout<<" "<<endl;
                cout<<"Enter the number of the station to remove: "<<endl;
                cin>>decision;
                cout<<" "<<endl;
                if(decision > 0 && decision < official.getStation().size()+1){
                    official.eliminateStation(decision);
                }
                else{
                    cout<<"Invalid Option. Coming back to Main Menu."<<endl;
                }
                

            }break;
            /*Eliminate a chosen Transport*/
            //********************************************************************** */
            case 2:{

                cout<<"Which of the following transports would you like to remove: "<<endl;
                cout<<official.showAll("Transports")<<endl;
                cout<<" "<<endl;
                cout<<"Enter the number of the transport to remove: "<<endl;
                cin>>decision;
                cout<<" "<<endl;
                if(decision > 0 && decision < official.getTransport().size()+1){
                    official.eliminateTransport(decision);
                }
                else{
                    cout<<"Invalid Option. Coming back to Main Menu."<<endl;
                }

            }break;
            //********************************************************************** */
            default:{
                cout<<"Invalid Option. Coming back to Main Menu."<<endl;
            }break;

            }

        }break;

        /*Reviewing the specific information of a Station or Transport*/
//----------------------------------------------------------------------
        case 5:{

            int decision;
            cout<<" "<<endl;
            cout<<"Choose which type of element would you like to get more information about: "<<endl;
            cout<<"1. Stations."<<endl;
            cout<<"2. Transports."<<endl;
            cout<<"Enter the number of your selection: "<<endl;
            cin >>decision;
            cout<<" "<<endl;

            switch (decision)
            {

            /*Specific Station Information*/
            //********************************************************************** */
            case 1:{

                cout<<"Which of the following stations would you like get detailed information: "<<endl;
                cout<<official.showAll("Stations")<<endl;
                cout<<" "<<endl;
                cout<<"Enter the number of the station to review: "<<endl;
                cin>>decision;
                cout<<" "<<endl;

                if(decision > 0 && decision < official.getStation().size()+1){
                    cout<<official.showStationInfo(decision)<<endl;
                }
                else{
                    cout<<"Invalid Option. Coming back to Main Menu."<<endl;
                }

            }break;

            /*Specific Transport Information*/
            //********************************************************************** */
            case 2:{

                cout<<"Which of the following transports would you like get detailed information: "<<endl;
                cout<<official.showAll("Transports")<<endl;
                cout<<" "<<endl;
                cout<<"Enter the number of the transport to review: "<<endl;
                cin>>decision;
                cout<<" "<<endl;

                if(decision > 0 && decision < official.getTransport().size()+1){
                    cout<<official.showTransportInfo(decision)<<endl;
                }
                else{
                    cout<<"Invalid Option. Coming back to Main Menu."<<endl;
                }
                
            }break;
            //********************************************************************** */
            default:{
                cout<<"Invalid Option. Coming back to Main Menu."<<endl;
            }break;

            }

        }break;

        /*Consulting all the transports that pass between two chosen stations*/
//----------------------------------------------------------------------
        case 6:{

            selectStationsBtw(official);

        }break;

        /*Exiting the while cycle*/
//----------------------------------------------------------------------
        case 7:{
            cout<<""<<endl;
            cout<<"Have a good day!"<<endl;
            finish = true;
        }break;

        default:{
            cout<<"Invalid Option"<<endl;
        }break;

        }
    }
    return 0;
}