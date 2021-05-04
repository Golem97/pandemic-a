/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/
/*
==============================================================
Person type: Virologist: Can perform a "disease treatment"
operation, not only in the city in which it is located, 
but in any city in the world - by throwing a card of that city.
==============================================================
*/
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Virologist : public Player{
    private:
    public:
    Virologist(Board& board_player_,City current_) : Player(board_player_,current_,"Virologist"){}
    Player& treat(City c_);
  };
}
