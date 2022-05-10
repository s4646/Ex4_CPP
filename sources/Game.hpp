#pragma once
#include <string>
#include <vector>
#define MAX_PLAYERS 6
namespace coup
{
    class Player;
    class Game
    {
        private:
            std::vector<Player*> Players;
            int currentIndex;
            int numOfPlayers;
            bool started;
        public:
            Game();
            ~Game();
            std::vector<std::string> players();
            std::string turn();
            void addPlayer(Player&);
            void coup(Player&);
            int index() const;
            std::vector<Player*> getPlayers();
            void handleIndex();
            void resetIndex();
            void decrementPlayers();
            void incrementPlayers();
            bool isStarted() const;
            void start();
            int getNumOfPlayers() const;
            std::string winner();
    };
}