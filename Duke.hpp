#pragma once
#include "Game.hpp"
#include "Player.hpp"

namespace coup
{
    class Duke : public Player
    {
        public:
            Duke(Game&, const std::string&);
            ~Duke();
            std::string role();
            void tax();
            void block(Player&);
    };
}