#include "Player.hpp"
/*
===============================================================
There are different roles of players, who have special skills
(the skills are similar but not the same as the original game):
===============================================================

>OperationsExpert
>Dispatcher
>Scientist
>Researcher
>Medic
>Virologist
>GeneSplicer

>FieldDoctor
*/
using namespace pandemic;

 //Possible action of each Player in the game 

	//Travel - move from the current city to a nearby city (according to the pop-up map).
    Player& Player::drive(City city_current){return *this;}

    //Direct flight - fly_direct - 
    //Transfer from the current city to the city of any card in his hand. To do this, throw the appropriate card to the city you are flying to.
  	Player& Player::fly_direct(City city_current){return *this;}
  	
  	//Build - build - build a research station in the city that is located in it. 
  	//To do this, throw the appropriate card to the city you are in. Each city can have at most one research station.
  	Player& Player::build(){return *this;}
 	
 	/*
 	Discover_cure - 
 	For a disease of a certain color.
 	To do this, you must be in a city that has a research station, and throw 5 colored cards of the disease.
	Each disease has one cure. If a cure for the disease has already been discovered, and a "drug discovery" operation for the same disease is performed again, there is no need to throw an anomaly.
 	*/
 	Player& Player::discover_cure(Color city_current){return *this;}

 	/*
 	Treat - Disease - lowering one disease cube from the city you are in (reducing the level of the disease by 1).
	If a cure for the disease has already been discovered in the color of the city, then the action of "cure the disease" removes all the disease cubes from the city that are in it (reducing the level of the disease to 0).
	If there is no infection at all in the city (the disease level is 0), then the action will throw an abnormality.
	Each action should update the board status and player position accordingly. If the operation is invalid, an appropriate exception must be thrown.
	In addition, the following methods must be practiced:
*/
	Player& Player::treat(City city_current){return *this;}

	//role - a function that returns the role of the player (see list of roles below), for display.
  	string Player::role(){return "";}
  	
  	//take_card - take a city card.
  	//This simulates the process by which the player receives cards from the pot at the beginning or during the game.
  	Player& Player::take_card(City city_current){return *this;}
  
  	//Franchise flight - fly_charter - transfer from the current city to any city.
  	// To do this, throw the appropriate card to the city you are in.
  	Player& Player::fly_charter(City city_current){return *this;}
  	
  	//Shuttle flight - fly_shuttle -
  	//If there is a research station in the current city, you can fly to any other city that has a research station.
  	Player& Player::fly_shuttle(City city_current){return *this;}
