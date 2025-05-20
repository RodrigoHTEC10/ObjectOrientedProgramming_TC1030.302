# Integrative Project: Queretaro's Public Transport Record

---

  Date: 12 - May - 2025  
  
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
- Bus Model (Traditional, New Models, Double cabinet, Van)
- A vector of the stations that the route passes (Each route has a minimum of two stations and more can be added asking the user in specific order from start to finish).


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

**Personal Interest:**

As a daily user of public transport sometimes it is necessary to take routes out of the ordinary to arrive to a part of the city faster or simply go to a new place. Due to the big extention of all the avaliable bus routes in Queretaro, it is hard to keep a mental record of all the routes taken and the stations they visit. This could be solved through the QroBus App or Web themselves; however, it is not possible to personalize or highlight certain routes, not to mention certain problems in the web version (which I use), which led me to the idea behind the present project:

  A program where I am able to keep record of the bus routes I take and consult if one of them passes through two specific stations.


## Program decomposition

The project **Queretaro's Public Transport Record** will be composed of 7 classes:

1. Transport
   
   1.1 Bus
   
   1.2 Van

3. Station

   2.1 Official
   
   2.2 Personal

5. Record

---

Through which there will be:
- Inheritance
- Aggregation

A preliminary UML diagram of this project is presented below:

![PreliminaryDiagramProject_RodrigoHurtado](https://github.com/user-attachments/assets/8e0ea9da-342f-4a72-945c-30daf3afc4db)



