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
        if(Coins<COUP_PAYMENT-4)
        {
            throw runtime_error("Not enough coins.");
        }
        validate();
        if(Coins<COUP_PAYMENT && Coins > 0)
        {
            for (size_t i = 0; i < (*game).getPlayers().size(); i++)
            {
                if((*game).getPlayers().at(i)->getName() == other.getName())
                {
                    if((*game).getPlayers().at(i)->role() == other.role())
                    {
                        other.couped = true;
                        this->Coins-=3;
                        coupedWho = &other;
                        assassinate=true;
                        if((*game).getPlayers().size() == 2) {(*game).coup(other);}
                        // else {(*game).decrementPlayers();}
                        if((*game).index()==(*game).getNumOfPlayers() || (*game).getPlayers().at((size_t)(*game).index()) == this)
                        {
                            (*game).handleIndex();
                        }
                        return;
                    }
                }
            }
            if(1==1) {throw runtime_error("Player not found");} // fuck you clang-tidy
        }
        else
        {
            Player::coup(other);
            return;
        }
    }
}