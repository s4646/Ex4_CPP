#include "Ambassador.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Ambassador::Ambassador(Game& g, const string& s) : Player(g,s) {}
    Ambassador::~Ambassador() {}
    string Ambassador::role() {return name;}
    void Ambassador::transfer(Player& first, Player& second) 
    {
        validate();
        if(first.coins()>0 && second.coins()<MAX_COINS)
        {
            first.Coins--;
            second.Coins++;
            game.handleIndex();
        }
        else
        {
            throw runtime_error("Cannot transfer coins.");
        }
    }
    void Ambassador::block(Player& other) {}
}