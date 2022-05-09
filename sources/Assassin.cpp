#include "Assassin.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Assassin::Assassin(Game& g, const string& s) : Player(g,s), assassinate(false){}
    Assassin::~Assassin() {}
    string Assassin::role() {return "Assassin";}
    void Assassin::validate()
    {
        if(assassinate) {assassinate=false;}
        Player::validate();
    }
    void Assassin::coup(Player& other) 
    {
        if(Coins<3) {throw runtime_error("Not enough coins.");}
        validate();
        if(this->Coins<COUP_PAYMENT)
        {
            for (size_t i = 0; i < (*game).getPlayers().size(); i++)
            {
                if((*(*game).getPlayers().at(i)).getName() == other.getName())
                {
                    other.couped = true;
                    this->Coins-=3;
                    coupedWho = other.name;
                    assassinate=true;
                    (*game).decrementPlayers();
                    (*game).handleIndex();
                    return;
                }
            }
        }
        else
        {
            Player::coup(other);
            (*game).handleIndex();
            return;
        }
    }
}