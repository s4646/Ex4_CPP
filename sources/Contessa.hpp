#pragma once
#include "Player.hpp"

namespace coup
{
    class Contessa : public Player
    {
        public:
            Contessa(Game&, const std::string&);
            ~Contessa();
            static std::string role();
            void block(Player&);
    };
}