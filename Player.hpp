#pragma once
#include "Game.hpp"
#include <string>

namespace coup
{
    class Player
    {
        protected:
            Game game;
            std::string name;
            int Coins;

        public:
            Player(Game&, const std::string&);
            ~Player();
            void income();
            void foreign_aid();
            int coins();
            virtual void coup(Player&);
    };
}