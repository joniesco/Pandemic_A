#include <iostream>
#include "doctest.h"   
#include <stdexcept>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "Medic.hpp"
#include "GeneSplicer.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <string>
using namespace std; 
using namespace pandemic;

Board board; 
TEST_CASE("operator []"){
	
	board[City::MexicoCity] = 4;      
	board[City::MexicoCity] = 1;      
	board[City::London] = 2;   
	board[City::Madrid] = 0;
	board[City::BuenosAires] = 1;
    board[City::HongKong] = 2;
    CHECK_EQ(board[London] , 2); 
    CHECK_EQ(board[HongKong] , 2);
    CHECK_EQ(board[Madrid] , 0);
    CHECK_EQ(board[London] ,board[HongKong]); 
    CHECK_NE(board[MexicoCity] , 4); 
}

TEST_CASE("OperationsExpert"){
    //-----------------making sure no cards were spent----------
    
     OperationsExpert x{board, Madrid};
     int size_before_build=x.cards.size();
     x.build();
    int size_after_build= x.cards.size();
     CHECK_EQ(size_before_build,size_after_build);
     x.build();
    CHECK_EQ(x.cards.size(),size_after_build);
}
TEST_CASE("Dispatcher"){
        //-----------------making sure no cards were spent----------

    Dispatcher x{board,Madrid};
    int size_before_flight=x.cards.size();
    x.fly_direct(London);
    int size_after_flight=x.cards.size();
     CHECK_EQ(size_before_flight,size_after_flight);
     x.fly_direct(Istanbul);
    CHECK_EQ(x.cards.size(),size_after_flight);
}
TEST_CASE("Scientist"){
    Board b;
    Scientist x{b,Seoul,1};
    int size_before_cure=x.cards.size();
    x.discover_cure(Red);
    int size_after_cure=x.cards.size();
    CHECK_EQ(size_before_cure-size_after_cure,1);
    x.fly_direct(Shanghai);
    x.discover_cure(Red);
    int new_size=x.cards.size();
    CHECK_EQ(size_before_cure-new_size,3);
}
TEST_CASE("Researcher"){
    //Assuming cairo and algeir has no research station
    Board b;
    Researcher x{b,Cairo};
    
    CHECK_NOTHROW(x.discover_cure(Black));
    x.fly_direct(Algiers);
    CHECK_NOTHROW(x.discover_cure(Black));
}
TEST_CASE("Medic"){
    Board b;
    board[City::Bogota] = 4;
    board[City::BuenosAires] = 2;
    Medic x{b,Bogota};
    x.treat(Bogota);
    CHECK_EQ(board[Bogota] , 0);
    x.take_card(BuenosAires);
    x.fly_direct(BuenosAires);
    x.treat(BuenosAires);
    CHECK_EQ(board[BuenosAires] , 0);
}
TEST_CASE("Virologist"){
    Board b;
    Virologist x{b,Tokyo};
    CHECK_NOTHROW(x.treat(BuenosAires));
    CHECK_NOTHROW(x.treat(Riyadh));
}
TEST_CASE("GeneSplicer"){
    Board b;
    GeneSplicer x{b,NewYork};
    int size=x.cards.size();
    CHECK_NOTHROW(x.discover_cure(Red));//despite newyork is black
    int new_size=x.cards.size();
    CHECK_EQ(new_size+5,size);
}
TEST_CASE("FieldDoctor"){
    Board b;
    FieldDoctor x{b,Delhi};
    int size=x.cards.size();
    CHECK_NOTHROW(x.treat(Mumbai));
    CHECK_NOTHROW(x.treat(Chennai));
    CHECK_NOTHROW(x.treat(Kolkata));
    int size_after_cure=x.cards.size();
    CHECK_EQ(size,size_after_cure);
}















    
    








    


