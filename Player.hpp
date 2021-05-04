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
#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <list>
using namespace std;
namespace pandemic{
  class Player{
    private:
      list<int> cards_game;
      string player;
        Board& board;
        City city_current;

    public:
      Player(Board& board_,City city_current_,string player_):board(board_),city_current(city_current_),player(player_){}
      Player& drive(City city_current);
      virtual Player& fly_direct(City city_current);
      virtual Player& build();
      virtual Player& discover_cure(Color city_current);
      virtual Player& treat(City city_current);

      string role();
      Player& take_card(City city_current);
      Player& fly_charter(City city_current);
      Player& fly_shuttle(City city_current);

  };
}
