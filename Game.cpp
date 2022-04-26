#include "Game.hpp"
#include "Player.hpp"

using namespace std;
using namespace coup;

namespace coup
{
    Game::Game()
    {
        this->Players = vector<string>();
        this->turns = vector<std::pair<string,string>>();
        this->numOfPlayers = 0;
    }
    Game::~Game() {}
    void Game::coup(string name) {}
    vector<string> Game::players() {return vector<string>();}
    string Game::turn() {return "lol";}
    void Game:: resetTurns() {}
}