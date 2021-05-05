#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic {

    class Board {

        

        public:
            Board() {}
            int& operator[](City c);
            bool is_clean();
            friend std::ostream& operator<<(std::ostream& out, const Board& b);
            void remove_cures();
    };
}