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
            std::vector<std::pair<std::string,std::string>> turns; // role, action
            int numOfPlayers;
        public:
            Game();
            ~Game();
            void coup(std::string);
            std::vector<std::string> players();
            std::string turn();
            void resetTurns();
    };
}