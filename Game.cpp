#include "Game.hpp"
#include "Player.hpp"
#include <stdexcept>


using namespace std;
using namespace coup;

namespace coup
{
    Game::Game()
    {
        this->Players = vector<Player>();
        this->currentIndex = 0;
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
    string Game::turn()
    {
        return this->Players.at((size_t)currentIndex).getName();
    }
    void Game::addPlayer(const Player& player)
    {
        this->Players.push_back(player);
    }
    void Game::coup()
    {
        if(Players.at((size_t)currentIndex).isCouped())
        {
            Players.erase(Players.begin()+currentIndex);
        }
        else
        {
            throw runtime_error("Player cannot be couped");
        }
    }
    void Game::resetIndex()
    {
        if (currentIndex > Players.size()-1)
        {
            currentIndex = 0;
        }
    }
    vector<Player> Game::getPlayers()
    {
        return Players;
    }
}