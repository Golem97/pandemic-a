/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/
//BOARD CPP
#include "Board.hpp"

using namespace pandemic;

  void Board::remove_cures(){}
  int & Board::operator[]( City city){
    return this->level_cures[city];
  }
  bool Board::is_clean(){return true;}
  std::ostream& pandemic::operator<<(std::ostream& out,const Board& b){return out;}
