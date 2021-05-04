/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/
/*
=====================================================
Person type: (OperationsExpert): 
Can perform a "build" operation in any city he is in, 
without throwing an appropriate city card.
=====================================================
*/

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace std;
//note
namespace pandemic{
  class OperationsExpert : public Player{
    private:

    public:
    OperationsExpert(Board& board_player_,City current_) : Player(board_player_,current_,"OperationsExpert"){}
    Player& build() override;
  };
}
