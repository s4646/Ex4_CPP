#include "doctest.h"
#include <vector>
#include <string>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;
using namespace std;

Game game_1{};

Duke duke{game_1, "Moshe"};
Assassin assassin{game_1, "Yossi"};
Ambassador ambassador{game_1, "Meirav"};
Captain captain{game_1, "Reut"};
Contessa contessa{game_1, "Gilad"};

TEST_CASE("NO ERROR")
{
    SUBCASE("INCOME")
    {
        SUBCASE("TURN")
        {
            // turn #1
            CHECK(game_1.turn()=="Moshe");
            CHECK_NOTHROW(duke.income());
            CHECK(game_1.turn()=="Yossi");
            CHECK_NOTHROW(assassin.income());
            CHECK(game_1.turn()=="Meirav");
            CHECK_NOTHROW(ambassador.income());
            CHECK(game_1.turn()=="Reut");
            CHECK_NOTHROW(captain.income());
            CHECK(game_1.turn()=="Gilad");
            CHECK_NOTHROW(contessa.income());
        }
        SUBCASE("PLAYERS")
        {
            vector<string> plrs = game_1.players();
            CHECK(plrs.at(0)=="Moshe");
            CHECK(plrs.at(1)=="Yossi");
            CHECK(plrs.at(2)=="Meirav");
            CHECK(plrs.at(3)=="Reut");
            CHECK(plrs.at(4)=="Gilad");
        }
        // turn #2
        CHECK_NOTHROW(duke.income());
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.income());
        CHECK_NOTHROW(captain.income());
        CHECK_NOTHROW(contessa.income());
    }
    SUBCASE("FOREIGN_AID")
    {
        // turn #3
        CHECK_NOTHROW(duke.foreign_aid());
        CHECK_NOTHROW(assassin.foreign_aid());
        CHECK_NOTHROW(ambassador.foreign_aid());
        CHECK_NOTHROW(captain.foreign_aid());
        CHECK_NOTHROW(contessa.foreign_aid());
        // turn #4
        CHECK_NOTHROW(duke.foreign_aid());
        CHECK_NOTHROW(assassin.foreign_aid());
        CHECK_NOTHROW(ambassador.foreign_aid());
        CHECK_NOTHROW(captain.foreign_aid());
        CHECK_NOTHROW(contessa.foreign_aid());
    }
    SUBCASE("BLOCK")
    {
        SUBCASE("COUP")
       {
            // turn #5. Contessa
            CHECK_NOTHROW(duke.income());
            CHECK_NOTHROW(assassin.coup(duke));
            CHECK_NOTHROW(ambassador.foreign_aid());
            CHECK_NOTHROW(captain.income());
            CHECK_NOTHROW(contessa.block(assassin));
       }
        // turn #6. Duke
        CHECK_NOTHROW(duke.block(ambassador));
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.income());
        CHECK_NOTHROW(captain.steal(contessa));
        CHECK_NOTHROW(contessa.income());
        // turn #7. Ambassador / Captain
        CHECK_NOTHROW(duke.income());
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.block(captain));
        CHECK_NOTHROW(captain.foreign_aid());
        CHECK_NOTHROW(contessa.foreign_aid());
    }
    SUBCASE("TAX")
    {
        // turn #8
        CHECK_NOTHROW(duke.tax());
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.income());
        CHECK_NOTHROW(captain.income());
        CHECK_NOTHROW(contessa.income());
    }
    SUBCASE("TRANSFER")
    {
        // turn #9
        CHECK_NOTHROW(duke.income());
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.transfer(captain,assassin));
        CHECK_NOTHROW(captain.income());
        CHECK_NOTHROW(contessa.income());
    }
    SUBCASE("COUP")
    {
        // turn #10
        CHECK_NOTHROW(duke.coup(contessa));
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.coup(assassin));
        CHECK_NOTHROW(captain.income());
        CHECK_NOTHROW(contessa.income()); 
    }
}

TEST_CASE("ERROR")
{
    
}