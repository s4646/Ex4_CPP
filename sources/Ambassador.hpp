#pragma once
#include "Player.hpp"

namespace coup
{
    class Ambassador : public Player
    {
        public:
            Ambassador(Game&, const std::string&);
            ~Ambassador();
            std::string role();
            void transfer(Player&, Player&);
            void block(Player&);
    };
}