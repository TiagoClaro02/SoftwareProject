#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Account.h"
#include "Card.h"
#include "Dealer.h"
#include "Deck.h"
#include "Game.h"
#include "Gambler.h"
#include "Hand.h"
#include "Server.h"
#include "Shoe.h"

//#define TEST

int main()
{
#ifndef TEST
	Server server;

	server.run();

	return 0;

#else
	std::cout << "Unit Test: Game.h" << std::endl;

	int betAmmount = 10;
	int success = 0;
	int fail = 0;

	Game game;
	// TODO Test 1
	std::cout << "##### Test 1: init(10) #####"
			  << "\n"
			  << std::endl;
	game.init(betAmmount);

	//? Test 1.1
	std::cout << "Expected betAmmount: 10"
			  << "\t";
	std::cout << "Actual betAmmount: " << game.betAmmount << std::endl;

	if (game.betAmmount == 10)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	//? Test 1.2
	std::cout << "Expected gameState: init"
			  << "\t";
	std::cout << "Actual gameState: " << game.gameState << std::endl;

	if (game.gameState == "init")
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	//? Test 1.3
	std::cout << "Expected isDouble: false"
			  << "\t";
	std::cout << "Actual isDouble: " << game.isDouble << std::endl;

	if (game.isDouble == false)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	//? Test 1.4
	std::cout << "Expected gambler.hand.getNumCards(): 2"
			  << "\t";
	std::cout << "Actual gambler.hand.getNumCards(): " << game.gambler.hand.getNumCards() << std::endl;

	if (game.gambler.hand.getNumCards() == 2)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	//? Test 1.5
	std::cout << "Expected dealer.hand.getNumCards(): 2"
			  << "\t";
	std::cout << "Actual dealer.hand.getNumCards(): " << game.dealer.hand.getNumCards() << std::endl;

	if (game.dealer.hand.getNumCards() == 2)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	// TODO Test 2
	game.init(10);
	std::cout << "##### Test 2: run(\"h\") #####"
			  << "\n"
			  << std::endl;
	game.run("h");

	//? Test 2.1
	std::cout << "Expected input: h"
			  << "\t";
	std::cout << "Actual input: " << game.input << std::endl;

	if (game.input == "h")
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	//? Test 2.2
	std::cout << "Expected gambler hand size: 3"
			  << "\t";
	std::cout << "Actual gambler hand size: " << game.gambler.hand.getNumCards() << std::endl;

	if (game.gambler.hand.getNumCards() == 3)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	// TODO test 3
	game.init(10);
	std::cout << "##### Test 3: run(\"s\") #####"
			  << "\n"
			  << std::endl;
	game.run("s");

	//? Test 3.1
	std::cout << "Expected input: s"
			  << "\t";
	std::cout << "Actual input: " << game.input << std::endl;

	if (game.input == "s")
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	//? Test 3.2
	std::cout << "Expected gameState: different than init"
			  << "\t";
	std::cout << "Actual gameState: " << game.gameState << std::endl;

	if (game.gameState != "init")
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	// TODO test 4
	game.init(10);
	std::cout << "##### Test 4: run(\"d\") #####"
			  << "\n"
			  << std::endl;
	game.run("d");

	//? Test 4.1
	std::cout << "Expected input: d"
			  << "\t";
	std::cout << "Actual input: " << game.input << std::endl;

	if (game.input == "d")
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	//? Test 4.2
	std::cout << "Expected isDouble: true"
			  << "\t";
	std::cout << "Actual isDouble: " << game.isDouble << std::endl;

	if (game.isDouble == true)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}
	//? Test 4.3
	std::cout << "Expected gambler hand size: 3"
			  << "\t";
	std::cout << "Actual gambler hand size: " << game.gambler.hand.getNumCards() << std::endl;

	if (game.gambler.hand.getNumCards() == 3)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	//? Test 4.4
	std::cout << "Expected betAmmount: 20"
			  << "\t";
	std::cout << "Actual betAmmount: " << game.betAmmount << std::endl;

	if (game.betAmmount == 20)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	// TODO test 5
	std::cout << "##### Test 5: run(\"d\") for the second time #####"
			  << "\n"
			  << std::endl;
	game.run("d");

	//? Test 5.1
	std::cout << "Expected input: d"
			  << "\t";
	std::cout << "Actual input: " << game.input << std::endl;

	if (game.input == "d")
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	//? Test 5.2
	std::cout << "Expected gambler hand size: 3"
			  << "\t";
	std::cout << "Actual gambler hand size: " << game.gambler.hand.getNumCards() << std::endl;

	if (game.gambler.hand.getNumCards() == 3)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	//? Test 5.3
	std::cout << "Expected betAmmount: 20"
			  << "\t";
	std::cout << "Actual betAmmount: " << game.betAmmount << std::endl;

	if (game.betAmmount == 20)
	{
		std::cout << "Test passed" << '\n'
				  << std::endl;
		success++;
	}
	else
	{
		std::cout << "Test failed" << '\n'
				  << std::endl;
		fail++;
	}

	std::cout << "Successfull tests: " << success << std::endl;
	std::cout << "Failed tests: " << fail << std::endl;

	return 0;
#endif
}