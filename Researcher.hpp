/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/
/*
=========================================================
Person type: (Researcher) : Can carry out a "drug discovery" 
operation in any city -
 it is not necessary to find one in a research station.
=========================================================
*/
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Researcher : public Player{
    private:
    public:
    Researcher(Board& board_player_,City current_) : Player(board_player_,current_,"Researcher"){}
    Player& discover_cure(Color c_);
  };
}
