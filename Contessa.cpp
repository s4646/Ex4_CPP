#include "Contessa.hpp"

using namespace coup;
using namespace std;

namespace coup
{
    Contessa::Contessa(Game& g, const string& s) : Player(g,s) {}
    Contessa::~Contessa() {}
    string  Contessa::role() {return "lol";}
    void Contessa::block(const Player& other) {}
}