#include "Contessa.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Contessa::Contessa(Game& g, const string& s) : Player(g,s) {}
    Contessa::~Contessa() {}
    string  Contessa::role() {return name;}
    void Contessa::block(Player& other)
    {
        Player* ptr = nullptr;
        for (size_t i = 0; i < game.getPlayers().size(); i++)
        {
            if(game.getPlayers().at(i).getName() == other.coupedWho)
            {
                ptr = &game.getPlayers().at(i);
                (*ptr).couped = false;
                other.coupedWho.clear();
            }
        }
        throw runtime_error("Player not found");
    }
}