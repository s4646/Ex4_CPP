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
            void coup(const std::string&);
            int index() const;
            std::vector<Player> getPlayers();
            void handleIndex();
            std::string winner();
    };
}