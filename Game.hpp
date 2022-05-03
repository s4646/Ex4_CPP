#pragma once
#include <string>
#include <vector>
namespace coup
{
    class Player;
    class Game
    {
        private:
            std::vector<Player> Players;
            int currentIndex;
            int numOfPlayers;
        public:
            Game();
            ~Game();
            std::vector<std::string> players();
            std::string turn();
            void addPlayer(const Player&);
            void coup();
            void resetIndex();
            std::vector<Player> getPlayers();
    };
}