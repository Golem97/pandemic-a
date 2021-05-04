/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/

/*
=================================================================
Person type: Paramedic - Medic: When he performs a "disease
 treatment" operation, he removes all the disease cubes from the 
 city he is in, and not just one.
=================================================================
*/
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Medic : public Player{
    private:
    public:
    Medic(Board& board_player_,City current_) : Player(board_player_,current_,"Medic"){}
    Player& treat(City c_);
  };
}
