#pragma once
#include <string>
#include <vector>
namespace coup
{
    class Player;
    class Game
    {
        private:
            std::vector<Player*> Players;
            int currentIndex;
            int numOfPlayers;
        public:
            Game();
            ~Game();
            std::vector<std::string> players();
            std::string turn();
            void addPlayer(Player&);
            void coup(const std::string&);
            int index() const;
            std::vector<Player*> getPlayers();
            void handleIndex();
            void decrementPlayers();
            void incrementPlayers();
            std::string winner();
    };
}