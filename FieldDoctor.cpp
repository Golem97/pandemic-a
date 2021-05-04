/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/
/*
==============================================================
Person type: Field Doctor -
 FieldDoctor: Can perform a "disease treatment" 
operation not only in the city he is in but in any city near 
the city he is in (according to the context map), 
without throwing a city card.
==============================================================
*/
#include "FieldDoctor.hpp"

namespace pandemic{
  Player& FieldDoctor::treat(City c_){return *this;}
}
