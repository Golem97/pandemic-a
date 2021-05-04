/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/
/*
==============================================================
Person type: GeneSplicer: 
Can perform a "drug discovery" operation with the 
help of 5 cards - not necessarily from the color of the disease.
==============================================================
*/
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class GeneSplicer : public Player{
    private:
    public:
    GeneSplicer(Board& board_player_,City current_) : Player(board_player_,current_,"GeneSplicer"){}
    Player& discover_cure(Color c_);
  };
}
