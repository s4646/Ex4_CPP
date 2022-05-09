#pragma once
#include "Player.hpp"

namespace coup
{
    class Assassin : public Player
    {
        private:
            bool assassinate;
        public:
            Assassin(Game&, const std::string&);
            ~Assassin();
            static std::string role();
            virtual void coup(Player&);
            virtual void validate();
    };
}