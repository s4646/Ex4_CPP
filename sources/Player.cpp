#include "Player.hpp"
#include <stdexcept>

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
        this->is_foreign_aid = false;
        game.addPlayer(*this);
    }
    Player::~Player() {};

    void Player::income() 
    {
        validate();
        if(Coins<MAX_COINS)
        {
            this->Coins++;
        }
        else
        {
            throw runtime_error("coins limit passed.");
        }
        game.handleIndex();
    }
    void Player::foreign_aid() 
    {
        validate();
        if(Coins<MAX_COINS-1)
        {
            this->Coins+=2;
            is_foreign_aid = true;
        }
        else
        {
            throw runtime_error("coins limit passed.");
        }
        game.handleIndex();
    }
    int Player::coins() const{return Coins;}
    string Player::getName() {return name;}
    bool Player::isBlocked() const{return blocked;}
    bool Player::isCouped() const{return couped;}
    void::Player::coup(Player& other)
    {
        for (size_t i = 0; i < this->game.getPlayers().size(); i++)
        {
            if(game.getPlayers().at(i).getName() == other.getName())
            {
                other.couped = true;
                coupedWho = other.name;
                this->Coins-=COUP_PAYMENT;
                return;
            }
        }
        throw runtime_error("Player not found");
    }
    void Player::validate()
    {
        if(game.players().at((size_t)game.index()) != name) {throw runtime_error("Not your turn");}
        if(this->couped) {return;}
        if(this->Coins>=MAX_COINS) {throw runtime_error("Must coup with 10 coins");}
        if(!this->coupedWho.empty())
        {
            game.coup(this->coupedWho);
            this->coupedWho.clear();
        }
        if(!this->applied.empty()) {this->applied.clear();}
        if(is_foreign_aid) {is_foreign_aid = false;}
    }
}