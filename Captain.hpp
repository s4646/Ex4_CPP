#pragma once
#include "Player.hpp"

namespace coup
{
    class Captain : public Player
    {
        public:
            Captain(Game&, const std::string&);
            ~Captain();
            std::string role();
            void steal(Player&);
            void block(Player&);
    };
}