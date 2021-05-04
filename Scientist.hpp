/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/
/*
==============================================================
Person type: Scientist: Can perform a "drug discovery" 
operation using only n cards
(instead of 5), with the n parameter passed to the constructor 
(in the original game n = 4).
==============================================================
*/

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Scientist : public Player{
    private:
      int amount;
    public:
    Scientist(Board& board_player_,City current_,int amount_) : Player(board_player_,current_,"Scientist"),amount(amount_){}
    Player& discover_cure(Color c_);
  };
}
