#include "Game.hpp"
#include "Player.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>


using namespace std;
using namespace coup;

namespace coup
{
    Game::Game()
    {
        this->Players = vector<Player*>();
        this->currentIndex = 0;
        this->numOfPlayers = 0;
        this->started=false;
    }
    Game::~Game() {}
    vector<string> Game::players()
    {
        vector<string> ret;
        for (size_t i = 0; i < Players.size(); i++)
        {
            if(!(*Players.at(i)).isCouped())
            {
                ret.push_back((*Players.at(i)).getName());
            }
        }
        return ret;
    }
    string Game::turn()
    {
        return this->Players.at((size_t)currentIndex)->getName();
    }
    void Game::addPlayer(Player& player)
    {
        if(started)
        {
            throw runtime_error("game started");
        }
        if(Players.size()>=MAX_PLAYERS)
        {
            throw runtime_error("maximum players");
        }
        Players.push_back(&player);
        numOfPlayers++;
    }
    void Game::coup(Player& couped)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            if(Players.at(i)->getName() == couped.getName())
            {
                if(Players.at(i)->role() == couped.role())
                {
                    if ((*Players.at(i)).isCouped())
                    {
                        Players.erase(Players.begin()+(long)i);
                        numOfPlayers--;
                        return;
                    }
                }
            }
        }
        // throw runtime_error("Player cannot be couped");
    }
    int Game::index() const{return currentIndex;}
    vector<Player*> Game::getPlayers()
    {
        return Players;
    }
    void Game::handleIndex()
    {
        currentIndex++;
        if(currentIndex>=Players.size()) {currentIndex=0;}
        while(Players.at((size_t)currentIndex)->isCouped())
        {
            currentIndex++;
            if(currentIndex>=Players.size()) {currentIndex=0;}
        }
    }
    string Game::winner()
    {
        if(Players.size()==1)
        {
            return players().at(0);
        }
        throw runtime_error("Game not done");
    }
    bool Game::isStarted() const{return started;}
    void Game::start() {started=true;}
    void Game::incrementPlayers() {numOfPlayers++;}
    void Game::decrementPlayers() {numOfPlayers--;}
}