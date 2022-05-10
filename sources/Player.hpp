#pragma once
#include "Game.hpp"
#include <string>
#define COUP_PAYMENT 7
#define MAX_COINS 10

namespace coup
{
    class Player
    {
        protected:
            Game* game;
            std::string name;
            Player* blockedWho;
            Player* coupedWho;
            int Coins;
            bool blocked, couped, is_foreign_aid;
            Player* applied;

        public:
            Player(Game&, const std::string&);
            ~Player();
            void income();
            void foreign_aid();
            int coins() const;
            std::string getName();
            bool isBlocked() const;
            bool isCouped() const;
            virtual void coup(Player&);
            virtual void validate();
            virtual std::string role();
        
        friend class Ambassador;
        friend class Assassin;
        friend class Captain;
        friend class Contessa;
        friend class Duke;
    };
}