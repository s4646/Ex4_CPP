#pragma once
#include "Player.hpp"

namespace coup
{
    class Contessa : public Player
    {
        public:
            Contessa(Game&, const std::string&);
            ~Contessa();
            std::string role();
            void block(const Player&);
    };
}