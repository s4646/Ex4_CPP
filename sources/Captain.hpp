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
            static std::string role();
            void steal(Player&);
            void block(Player&);
            virtual void validate();
            int coins_stolen() const;
    };
}