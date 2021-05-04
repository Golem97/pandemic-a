#pragma once
#include "City.hpp"
#include <unordered_map>

namespace pandemic{
  class Board{
    private:
      std::unordered_map<City,int> level_cures;
    public:

      void remove_cures();
      int & operator[]( City city);
      bool is_clean();
      friend std::ostream& operator<<(std::ostream& out,const Board& b);
  };
}
