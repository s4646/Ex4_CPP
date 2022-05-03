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
            bool blocked, couped;

        public:
            Player(Game&, const std::string&);
            ~Player();
            void income();
            void foreign_aid();
            int coins();
            std::string getName();
            bool isBlocked();
            bool isCouped();
            virtual void coup(Player&);
    };
}