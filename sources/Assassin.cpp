#include "Assassin.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Assassin::Assassin(Game& g, const string& s) : Player(g,s) {}
    Assassin::~Assassin() {}
    string Assassin::role() {return name;}
    void Assassin::coup(Player& other) 
    {
        if(this->Coins>=7)
        {
            Player::coup(other);
            return;
        }
        else
        {
            for (size_t i = 0; i < game.getPlayers().size(); i++)
            {
                if(game.getPlayers().at(i).getName() == other.getName())
                {
                    other.couped = true;
                    this->Coins-=7;
                    return;
                }
            }
            throw runtime_error("Player not found");
        }
    }
}