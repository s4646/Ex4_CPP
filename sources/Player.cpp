#include "Player.hpp"
#include <stdexcept>
#include <iostream>

using namespace coup;
using namespace std;

namespace coup
{
    Player::Player(Game& g, const string& s)
    {
        this->game = &g;
        this->name = s;
        this->Coins = 0;
        this->blocked = false;
        this->couped = false;
        this->is_foreign_aid = false;
        (*game).addPlayer(*this);
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
        (*game).handleIndex();
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
        (*game).handleIndex();
    }
    int Player::coins() const{return Coins;}
    string Player::getName() {return name;}
    bool Player::isBlocked() const{return blocked;}
    bool Player::isCouped() const{return couped;}
    void::Player::coup(Player& other)
    {
        if(Coins<7) {throw runtime_error("Not enough coins for coup");}
        for (size_t i = 0; i < (*game).getPlayers().size(); i++)
        {
            if((*(*game).getPlayers().at(i)).getName() == other.getName())
            {
                other.couped = true;
                coupedWho = other.name;
                this->Coins-=COUP_PAYMENT;
                (*game).coup(other.getName());
                (*game).handleIndex();
                return;
            }
        }
        cout << (*game).index() << '\n';
        throw runtime_error("Player not found");
    }
    void Player::validate()
    {
        if((*game).getPlayers().at((size_t)(*game).index())->getName() != name)
        {
            throw runtime_error("Not your turn");
        }
        if(this->couped)
        {
            (*game).handleIndex();
            return;
        }
        if(this->Coins>=MAX_COINS) {throw runtime_error("Must coup with 10 coins");}
        if(!this->coupedWho.empty())
        {
            (*game).coup(this->coupedWho);
            this->coupedWho.clear();
        }
        if(!this->applied.empty()) {this->applied.clear();}
        if(is_foreign_aid) {is_foreign_aid = false;}
    }
}