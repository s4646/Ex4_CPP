#include "Duke.hpp"

using namespace coup;
using namespace std;

namespace coup
{
    Duke::Duke(Game& g, const string& s) : Player(g,s) {}
    Duke::~Duke() {}
    string Duke::role() {return "lol";}
    void Duke::tax() {}
    void Duke::block(Player& other) {}
}