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
        validate();
        if(this->Coins>COUP_PAYMENT)
        {
            throw runtime_error("coins limit passed.");
        }
        this->Coins+=3;
        game.handleIndex();
    }
    void Duke::block(Player& other)
    {
        if(!other.is_foreign_aid)
        {
            throw runtime_error("Cannot block 'foreign aid'");
        }
        other.Coins-=3;
    }
}