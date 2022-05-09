#pragma once
#include "Player.hpp"
#include "Captain.hpp"

namespace coup
{
    class Ambassador : public Player
    {
        public:
            Ambassador(Game&, const std::string&);
            ~Ambassador();
            static std::string role();
            void transfer(Player&, Player&);
            void block(Captain&);
    };
}