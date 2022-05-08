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
        validate();
        if(this->Coins<COUP_PAYMENT)
        {
            for (size_t i = 0; i < game.getPlayers().size(); i++)
            {
                if(game.getPlayers().at(i).getName() == other.getName())
                {
                    other.couped = true;
                    this->Coins-=3;
                    game.handleIndex();
                    return;
                }
            }
        }
        else
        {
            Player::coup(other);
            game.handleIndex();
            return;
        }
    }
}