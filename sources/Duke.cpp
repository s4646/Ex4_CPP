#include "Duke.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Duke::Duke(Game& g, const string& s) : Player(g,s) {}
    Duke::~Duke() {}
    string Duke::role() {return name;}
    void Duke::tax()
    {
        if(this->Coins>7)
        {
            throw runtime_error("coins limit passed.");
        }
        this->Coins+=3;
    }
    void Duke::block(Player& other) {}
}