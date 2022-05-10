#include "Contessa.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Contessa::Contessa(Game& g, const string& s) : Player(g,s) {}
    Contessa::~Contessa() {}
    string  Contessa::role() {return "Contessa";}
    void Contessa::block(Player& other)
    {
        Player* ptr = nullptr;
        if (other.coupedWho == nullptr) {throw runtime_error("Cannot block");}
        for (size_t i = 0; i < (*game).getPlayers().size(); i++)
        {
            if((*game).getPlayers().at(i)->getName() == other.coupedWho->name)
            {
                if((*game).getPlayers().at(i)->role() == other.coupedWho->role())
                {
                ptr = (*game).getPlayers().at(i);
                (*ptr).couped = false;
                other.coupedWho = nullptr;
                // (*game).incrementPlayers();
                return;
                }
            }
        }
        throw runtime_error("Player not found");
    }
}