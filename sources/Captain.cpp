#include "Captain.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Captain::Captain(Game& g, const string& s) : Player(g,s), stolen_coins(0) {}
    Captain::~Captain() {}
    string Captain::role() {return name;}
    void Captain::steal(Player& other)
    {
        Captain::validate();
        if(other.Coins>=2 && other.Coins<=MAX_COINS)
        {
            this->Coins += 2;
            other.Coins -= 2;
            stolen_coins = 2;
            game.handleIndex();
        }
        if(other.Coins<2 && other.Coins>=0)
        {
            this->Coins += other.Coins;
            stolen_coins = other.Coins;
            other.Coins = 0;
            game.handleIndex();
        }
        throw runtime_error("Cannot steal.");
    }
    void Captain::validate()
    {
        if(stolen_coins!=0) {stolen_coins=0;}
        Player::validate();
    }
    void Captain::block(Captain& other)
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
        (*ptr).Coins += stolen_coins;
        other.Coins -= stolen_coins;
    }
    int Captain::coins_stolen() const {return stolen_coins;}
}