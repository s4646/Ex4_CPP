#include "Game.hpp"
#include "Player.hpp"

using namespace std;
using namespace coup;

namespace coup
{
    Game::Game()
    {
        this->Players = vector<Player>();
        this->turns = vector<std::pair<string,string>>();
        this->numOfPlayers = 0;
    }
    Game::~Game() {}
    vector<string> Game::players()
    {
        vector<string> ret;
        for (size_t i = 0; i < Players.size(); i++)
        {
            ret.push_back(Players.at(i).getName());
        }
        return ret;
    }
    string Game::turn() {return "lol";}
    void Game:: resetTurns() {}
}