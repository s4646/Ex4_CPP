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
    void Ambassador::block(Captain& other)
    {
        Player* ptr = nullptr;
        for (size_t i = 0; i < game.getPlayers().size(); i++)
        {
            if (game.getPlayers().at(i).name == other.applied)
            {
                ptr = &game.getPlayers().at(i);
            }
        }
        if(ptr==NULL) {throw runtime_error("Player not found");}
        (*ptr).Coins += other.coins_stolen();
        other.Coins -= other.coins_stolen();
    }
}