/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/

/*
=================================================================
Person type: (Dispatcher)
While in a research station, he can perform a "direct flight" 
operation to any city of his choice,without throwing a city card.
=================================================================
*/

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Dispatcher : public Player{
    private:

    public:
    Dispatcher(Board& board_player_,City current_) : Player(board_player_,current_,"Dispatcher"){}
    Player& fly_direct(City c_);
  };
}
