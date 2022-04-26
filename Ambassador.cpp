#include "Ambassador.hpp"


using namespace coup;
using namespace std;

namespace coup
{
    Ambassador::Ambassador(Game& g, const string& s) : Player(g,s) {}
    Ambassador::~Ambassador() {}
    string Ambassador::role() {return "lol";}
    void Ambassador::transfer(Player& first, Player& second) {};
    void Ambassador::block(Player& other) {}
}