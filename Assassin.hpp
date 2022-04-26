#pragma once
#include "Player.hpp"

namespace coup
{
    class Assassin : public Player
    {
        public:
            Assassin(Game&, const std::string&);
            ~Assassin();
            std::string role();
            virtual void coup(Player&);
    };
}