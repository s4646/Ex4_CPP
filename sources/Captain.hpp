#pragma once
#include "Player.hpp"

namespace coup
{
    class Captain : public Player
    {
        private:
            int stolen_coins;
        public:
            Captain(Game&, const std::string&);
            ~Captain();
            std::string role();
            void steal(Player&);
            void block(Captain&);
            virtual void validate();
            int coins_stolen() const;
    };
}