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
#include "Medic.hpp"

namespace pandemic{
  Player& Medic::treat(City c_){return *this;}
}
