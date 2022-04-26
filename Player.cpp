#include "Player.hpp"

using namespace coup;
using namespace std;

namespace coup
{
    Player::Player(Game& g, const string& s)
    {
        this->game = g;
        this->name = s;
        this->Coins = 0;
    }
    Player::~Player() {};

    void Player::income() {}
    void Player::foreign_aid() {}
    int Player:: coins() {return 0;}
    void::Player::coup(Player& other) {}
}