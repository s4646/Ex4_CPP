#include "Player.hpp"
#include <stdexcept>
#include <iostream>
#include <typeinfo>

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
        coupedWho = nullptr;
        blockedWho = nullptr;
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
        // else
        // {
        //     throw runtime_error("coins limit passed.");
        // }
        (*game).handleIndex();
    }
    void Player::foreign_aid() 
    {
        validate();
        this->Coins+=2;
        is_foreign_aid = true;
        (*game).handleIndex();
    }
    int Player::coins() const{return Coins;}
    string Player::getName() {return name;}
    bool Player::isBlocked() const{return blocked;}
    bool Player::isCouped() const{return couped;}
    string Player::role() {return "Player";}
    void::Player::coup(Player& other)
    {
        if(Coins<COUP_PAYMENT) {throw runtime_error("Not enough coins for coup");}
        for (size_t i = 0; i < (*game).getPlayers().size(); i++)
        {
            if((*game).getPlayers().at(i)->getName() == other.getName())
            {
                if((*game).getPlayers().at(i)->role() == other.role())
                {
                    other.couped = true;
                    coupedWho = &other;
                    this->Coins-=COUP_PAYMENT;
                    (*game).coup(other);
                    if((*game).index()==(*game).getNumOfPlayers() || (*game).getPlayers().at((size_t)(*game).index()) == this)
                    {
                        (*game).handleIndex();
                    }
                return;
                }
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
        if(this->Coins>=MAX_COINS)
        {
            throw runtime_error("Must coup with 10 coins");
        }
        if(this->coupedWho != nullptr)
        {
            (*game).coup(*coupedWho);
            coupedWho = nullptr;
        }
        if(this->applied!=nullptr) {this->applied=nullptr;}
        if(is_foreign_aid) {is_foreign_aid = false;}
        if(!(*game).isStarted() && (*game).getPlayers().size()>1) {(*game).start();}
        if((*game).getPlayers().size()==1)
        {
            throw runtime_error("1 player cant play alone");
        }
    }
}