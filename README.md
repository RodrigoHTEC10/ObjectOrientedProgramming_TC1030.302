# Integrative Project: Queretaro's Public Transport Record

---

  Date: 9 - June - 2025  
  
---

## Description
**Identified Problematic:** 

Since 2005 the public transport system in Queretaro has experienced several changes, making it difficult for people to remember if a route passed or not between two stations (which may or may not have an official name). This brings up the problem of lacking a personal record of the routes taken and the stations it passed.

<p align="center">
<img src="https://www.iqt.gob.mx/wp-content/uploads/2017/10/QueEsQrobus_001.png" width="300" />
</p>


**Objective of the project:**

Offer people who use the public transport system of Queretaro an alternative to have a digital record of the routes taken, in which they can consult the information of a previously registered route or look for the routes that pass between two stations previously defined.

The taken routes can be registered specifing:

- Route Name (T-01)
- Color of the route (Orange)
- Bus Model (Old model,Medium Model,Modern Model, Van)
- A vector of the stations that the route passes (Each route has a minimum of one stations and more can be added asking the user in specific order from start to finish).


<p align="center">
<img src="https://tribunadequeretaro.com/wp-content/uploads/2023/09/qrobus_nuevo_2023.jpeg" width="300" />
</p>


Additionally the user will be able to create an specific station (official or personalized) completing the following information:

- Name of the Station
- Direction of the Station

<p align="center">
<img src="https://informequeretano.com/wp-content/uploads/2024/07/Picsart_24-07-17_14-16-41-725-scaled.jpg" width="300" />
</p>


Such station will be added to the stations avaliable to register a route.

This project allows to tackle a need for those who use public transport, that despite being able to memorize the routes taken daily, sometimes it is necessary to take a different route that you may or may nor have taken before: which can be opportunaly consulted on the *Queretaro's Public Transport Record*.
<br></br>

**Personal Interest:**

As a daily user of public transport sometimes it is necessary to take routes out of the ordinary to arrive to a part of the city faster or simply go to a new place. Due to the big extention of all the avaliable bus routes in Queretaro, it is hard to keep a mental record of all the routes taken and the stations they visit. This could be solved through the QroBus App or Web themselves; however, it is not possible to personalize or highlight certain routes, not to mention certain problems in the web version (which I use), which led me to the idea behind the present project:

  A program where I am able to keep record of the bus routes I take and consult if one of them passes through two specific stations.
<br></br>

## Program decomposition

The project **Queretaro's Public Transport Record** is composed of 7 classes:

1. Transport

Abstract super class of the Bus and Van subclasses. This class stores the common attributes and methods of the official public transports in Queretaro.

  1.1  Bus
  
  Subclass of Transport which has the additional attribute of number of entries to the Bus. This class represents the bus routes that travel through the city of Queretaro, which routes are known to be longer, traveling through several stations.

  1.2 Van

  Subclass of Transport which has no additional attributes of the previously mentioned. This class represents the van routes that travel through specific parts of the city of Queretaro, which are shorter compared to buses.

<br></br>
2. Station

Abstract super class of the Personal and Official subclasses. This class stores the common attributes of bus stations, both official and personal (declared by the user).

   2.1 Official
    
  Subclass of Station which contains the specific attribute: number of recharge points. This class represents the official stations located in main avenues that have at least one machine to recharge the bus cards and personalized infrastructure.

   
   2.2 Personal

  Subclass of Station which does not have an additional attribute to the previously defined ones.  This class represents the stations that are not officially recognized by the Public Transport Secretary of Queretaro; however, are assumed as stations because transports stop at those locations.

<br></br>
3. Record

Class responsible for the collection and storage of Transports and Stations subclasses pointers into two vectors, allowing to implement specific methods of each subclass while traversing the common vectors (polymorphism). This class contains all the functionalities detailed in the *program usage* section.


---

Through which there will be an implementation of:
- Inheritance
- Aggregation
- Polymorfism
- Abstract classes
- Overloading and Overriding Methods
- Overloading Operators

The UML diagram of this project is presented below:


![DiagramProject](https://github.com/user-attachments/assets/2a72731c-efa6-4bba-9a02-c1486c2974ad)



---
## Program Usage:

The program has a series of default Transports and Stations defined. Within the program there is a menu which shows the seven functionalities of the program which allows the user to:

1. Review all Stations and Transports.
2. Review all Stations or Transports.
3. Add a new Station or Transport.
4. Eliminate a Station or Transport.
5. Get the information of a specific Station or Transport.
6. Check Transports between two Stations.
7. Change a Station or Transport name. 
8. Exit.
   
The user will enter a number in the console depending on the function it wants the program to implement and follow the instructions of each, which may vary depending on the chosen option as it may ask to: choose specific created objects (options 2, 4, 5 and 6), enter information related to the creation or modification of objects (options 3 and 7), or none (option 1 and 8).

It is important for the user to pay special attention to the inputs the program asks in each section, which will clearly indicate a data type accepted as “numeric value” or “text” in case of names and descriptions. If the user enters a number that does not belong to the available options, the program will return to the main menu.
<br></br>

---
## Program Vulnerabilities:

After testing the program, the following vulnerability was identified:

In case of entering a different input type of the expected from the user (entering a word instead of a number) the program will begin looping itself, in which case it must be forced to stop by canceling the process in the console or IDE being used.

As a precaution measure, the instructions that guide the user through the program usage state more clearly the data types required to enter

