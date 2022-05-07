#include "Captain.hpp"
#include <stdexcept>

using namespace coup;
using namespace std;

namespace coup
{
    Captain::Captain(Game& g, const string& s) : Player(g,s) {}
    Captain::~Captain() {}
    string Captain::role() {return name;}
    void Captain::steal(Player& other)
    {
        if(other.Coins>=2 && other.Coins<=10)
        {
            this->Coins += 2;
            other.Coins -= 2;
        }
        if(other.Coins<2 && other.Coins>=0)
        {
            this->Coins += other.Coins;
            other.Coins = 0;
        }
        throw runtime_error("Cannot steal.");
    }
    void Captain::block(Player& other) {}
}