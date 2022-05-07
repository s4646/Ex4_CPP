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
        if(first.coins()>0 && second.coins()<10)
        {
            first.Coins--;
            second.Coins++;
        }
        else
        {
            throw runtime_error("Cannot transfer coins.");
        }
    }
    void Ambassador::block(Player& other) {}
}