#include "Assassin.hpp"

using namespace coup;
using namespace std;

namespace coup
{
    Assassin::Assassin(Game& g, const string& s) : Player(g,s) {}
    Assassin::~Assassin() {}
    string Assassin::role() {return "lol";}
    void Assassin::coup(Player& other) {}
}