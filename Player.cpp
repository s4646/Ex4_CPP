#include "Player.hpp"
#include <stdexcept>
#include <typeinfo>

using namespace coup;
using namespace std;

namespace coup
{
    Player::Player(Game& g, const string& s)
    {
        this->game = g;
        this->name = s;
        this->Coins = 0;
        this->blocked = false;
        this->couped = false;
        g.addPlayer(*this);
    }
    Player::~Player() {};

    void Player::income() 
    {
        if(Coins<10)
        {
            this->Coins++;
        }
        else
        {
            throw runtime_error("Has 10 coins already");
        }
    }
    void Player::foreign_aid() 
    {
        if(Coins<9)
        {
            this->Coins+=2;
        }
        else
        {
            throw runtime_error("Has 9+ coins already");
        }
    }
    int Player:: coins() {return Coins;}
    string Player::getName() {return name;}
    bool Player::isBlocked() {return blocked;}
    bool Player::isCouped() {return couped;}
    void::Player::coup(Player& other)
    {
        for (size_t i = 0; i < this->game.getPlayers().size(); i++)
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