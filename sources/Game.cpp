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
    void Game::coup(const string& couped)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            if(Players.at(i).getName() == couped)
            {
                if (Players.at(i).isCouped())
                {
                    Players.erase(Players.begin()+(long)i);
                }
                else
                {
                    throw runtime_error("Player cannot be couped");
                }
            }
        }
        throw runtime_error("Player not found");
    }
    int Game::index() const{return currentIndex;}
    vector<Player> Game::getPlayers()
    {
        return Players;
    }
    void Game::handleIndex()
    {
        currentIndex++;
        if(currentIndex>=Players.size()) {currentIndex=0;}
    }
    string Game::winner()
    {
        if(Players.size()==1)
        {
            return players().at(1);
        }
        throw runtime_error("Game not done");
    }
}