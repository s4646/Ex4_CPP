#include "Captain.hpp"

using namespace coup;
using namespace std;

namespace coup
{
    Captain::Captain(Game& g, const string& s) : Player(g,s) {}
    Captain::~Captain() {}
    string Captain::role() {return name;}
    void Captain::steal(Player& other) {}
    void Captain::block(Player& other) {}
}