#include "pch.h"
#include <iostream>
#include "../MainProject_server/Game.h"
#include "../MainProject_server/Account.h"
#include "../MainProject_server/Card.h"
#include "../MainProject_server/Dealer.h"
#include "../MainProject_server/Deck.h"
#include "../MainProject_server/Gambler.h"
#include "../MainProject_server/Hand.h"
#include "../MainProject_server/Shoe.h"

TEST(GameInitTests, InitializationSuccessTest)
{
    Game game;
    double bet = 10;

    game.init(bet);

    EXPECT_EQ(game.gameState, "init");
    EXPECT_EQ(game.betAmmount, bet);
    EXPECT_EQ(false, game.isDouble);
    EXPECT_EQ(game.gambler.hand.getNumCards(), 2);
    EXPECT_EQ(game.dealer.hand.getNumCards(), 2);
}

TEST(GameInitTests, BoundaryCasesTest)
{
    Game game;
    double bet_values[] = { 0, 100, -50, DBL_MAX, DBL_MIN };

    for (double bet : bet_values)
    {
        game.init(bet);

        EXPECT_EQ(game.betAmmount, bet);
    }
}

TEST(GameInputTests, ValidInputsHit)
{
    Game game;
    double bet = 10;
    game.init(bet);
    game.run("h");
    EXPECT_EQ(game.input, "h");
    EXPECT_EQ(game.gambler.hand.getNumCards(), 3);
}
TEST(GameInputTests, ValidInputsStand)
{
    Game game;
    double bet = 10;
    game.init(bet);
    game.run("s");
    EXPECT_EQ(game.input, "s");
    EXPECT_EQ(game.gambler.hand.getNumCards(), 2);
}

TEST(GameInputTests, ValidInputsDouble)
{
    Game game;
    double bet = 10;
    game.init(bet);
    game.run("d");
    EXPECT_EQ(game.input, "d");
    EXPECT_EQ(game.gambler.hand.getNumCards(), 3);
}

TEST(GameStateTests, StandTest)
{
    Game game;
    game.init(10);
    game.run("s");
    EXPECT_NE(game.gameState, "init");
}
