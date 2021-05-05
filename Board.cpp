#include "Board.hpp"

using namespace std;
using namespace pandemic;
 std::map<City, int> diseas_amount;

int& Board::operator[](City c) {
    return diseas_amount[c];
}
bool Board::is_clean() {
    return true;
}
std::ostream& pandemic::operator<<(std::ostream& out, const Board& b) {
    return out;
}
void Board::remove_cures(){}