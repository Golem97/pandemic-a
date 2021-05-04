/*
===============================================================
>Submission 4.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>Pandemic-a
================================================================
*/

#include "doctest.h"

//============
/* INCLUDES */
//============

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;


//====================
/* PLAYERS INCLUDES */
//====================
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

//=========
/* TESTS */
//=========

//==================
/* TEST INIT BOARD*/
//==================

TEST_CASE("Initialization Game")
{
  //IsClean
  Board board;
  CHECK (board.is_clean()); //Have to be True (Board Defaulty Clean)

  board[City::Istanbul] = 2;
  CHECK (!board.is_clean()); //Now Have to be False (Istanbul contain Deseas)

}

//=======================
/* TEST PLAYER ACTIONS */
//=======================

TEST_CASE("PLAYER ACTIONS")
{
  //INIT BOARD/PLAYER
  Board board;
	OperationsExpert p1 {board, City::Cairo};
	OperationsExpert p2 {board, City::Mumbai};
	OperationsExpert p3 {board, City::Kinshasa};
  OperationsExpert p4 {board, City::HongKong};
  OperationsExpert p5 {board, City::Taipei};
  OperationsExpert p6 {board, City::StPetersburg};


  //DRIVE (Connected or not)
  CHECK_THROWS  (p1.drive(City::Bogota));  // CAIR not connected to BOGOTA 
  CHECK_NOTHROW (p1.drive(City::Algiers)); // CAIR connected to ALGIERS
   
  //FLY DIRECT
  p2.take_card(City::BuenosAires);
  CHECK_NOTHROW (p2.fly_direct(City::BuenosAires));  //p2 have the card of BuenoAires (So can Fly)
  CHECK_THROWS  (p2.fly_direct(City::Johannesburg)); //p2 don't have card of Johannesburg (So Can't Fly)
  
  //FLY CHARTER
  p3.take_card(City::Khartoum);
  CHECK_NOTHROW (p3.fly_charter(City::Johannesburg));
  CHECK_THROWS  (p3.fly_charter(City::Jakarta));
  
  //FLY SHUTTLE
  p4.take_card(City::HongKong);
  p4.build();
  CHECK_THROWS(p4.fly_shuttle(City::Kinshasa));   //No research staion at Kinshasa
  p3.build();                                     //p4 build research station
  CHECK_NOTHROW(p4.fly_shuttle(City::Kinshasa));  //now reseach station exist at Kinshasa

  //BUILD
  CHECK_THROWS( p3.build());  //Already Research Station at Kinshasah
  CHECK_NOTHROW(p4.build());  //Not Exist Research Station at HongKong

  //DISCOVER CURE
  p5.take_card(City::SanFrancisco);
  p5.take_card(City::Jakarta);
  p5.take_card(City::Atlanta);
  p5.take_card(City::Khartoum);
  CHECK_THROWS(p5.discover_cure(Color::Red));//Must have 5 Card to find cure
  p5.take_card(City::SaoPaulo);
  CHECK_NOTHROW(p5.discover_cure(Color::Red));//Cure is founded

  //TREAT
  CHECK_THROWS(p6.treat(City::KePasio)); //KePasio Is clean so can't be treated
  board[City::Chicago] = 1;
  CHECK_NOTHROW(p6.treat(City::KePasio)); //KePasio lvl 1 so can be treated
  
  //ROLE
  CHECK_EQ (p6.role(),"OperationsExpert");

}
TEST_CASE("TEST PLAYER TYPE")
{   
    Board board ;

    //OperationsExpert
    OperationsExpert op_exp {board, City::Jakarta};
    CHECK_NOTHROW   (op_exp.build());                //Can build even without card
    CHECK(op_exp.role() == "OperationsExpert");

    //Dispatcher
    Dispatcher d {board, City::Kinshasa};
    CHECK_NOTHROW(d.fly_direct(City::Bangkok)); //Can fly because their is Station in Kinshasa
    CHECK(d.role() == "Dispatcher");

    //Scientist
    Scientist s {board, City::London,4};
    s.take_card(City::SanFrancisco);
    s.take_card(City::Jakarta);
    s.take_card(City::Atlanta);
    s.take_card(City::Khartoum);
    CHECK_NOTHROW(s.discover_cure(Color::Blue)); //Find with only 4 card
    CHECK(s.role() == "Scientist");

    Scientist s2 {board, City::London,4};
    s2.take_card(City::Lima);
    s2.take_card(City::LosAngeles);
    s2.take_card(City::NewYork);
    CHECK_NOTHROW(s2.discover_cure(Color::Blue));//Can't without n=3
    CHECK(s2.role() == "Scientist");


    //Researcher
    Researcher r {board, City::London};

    r.take_card(City::Delhi);
    r.take_card(City::Karachi);
    r.take_card(City::Khartoum);
    r.take_card(City::Kinshasa);
    r.take_card(City::Paris);
    CHECK_NOTHROW(r.discover_cure(Color::Yellow)); //Discover without station 
    CHECK(r.role() == "Researcher");
    
    //Medic
    Medic m {board, City::Istanbul};
    m.take_card(City::Shanghai);
    CHECK_NOTHROW(m.fly_direct(City::Shanghai)); 
    board[City::Shanghai] = 3 ;
    CHECK(!board.is_clean());
    CHECK_NOTHROW(m.treat(City::Shanghai)); //Treat all curse even without cure
    CHECK(board.is_clean());
     CHECK(m.role() == "Medic");

    //Virologist
    Virologist v(board, City::Jakarta);
    CHECK_THROWS(v.treat(City::Jakarta)); //Ipouss Jakarta deases (lvl 0)
    v.take_card(City::Lagos);
    CHECK_THROWS(v.treat(City::Lagos));   //Lagos level =0
    board[City::Delhi] = 3 ;
    CHECK(!board.is_clean());
    CHECK_NOTHROW(v.treat(City::Lagos));
    CHECK(board.is_clean());
    CHECK(v.role() == "Virologist");
    
    //GeneSplicer
    GeneSplicer g(board,City::Paris);     
    CHECK_THROWS(g.treat(City::Paris));  //Ipouss deases
    OperationsExpert op(board,City::Paris);
    CHECK_NOTHROW(op.build());           //Buid station 
    board[City::Paris] = 3 ;
    g.take_card(City::LosAngeles); //yellow
    g.take_card(City::StPetersburg);//blue
    g.take_card(City::Tokyo); //red 
    g.take_card(City::MexicoCity); //yellow
    g.take_card(City::Essen);//blue
    CHECK_NOTHROW(g.discover_cure(Color::Blue)); //Work without 5 Blue
    g.treat(City::Paris);
    CHECK(board.is_clean());
    CHECK(g.role() == "GeneSplicer");
     
     //FieldDoctor
        FieldDoctor f(board, City::Seoul);
        CHECK_THROWS(f.treat(City::Seoul)); 
        CHECK(board.is_clean());
        CHECK(f.role() == "GeneSplicer");





}


