#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "network.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "TextBox.h"
#include "Button.h"

#define ADDRESS "127.0.0.1"
#define PORT 8080

#define ESTORIL 0
#define ANTARTIDA 1
#define VEGAS 2
#define SIDNEY 3
#define SOUTH_AMERICA 4
#define SUNCITY 5	
#define DUBAI 6
#define MACAU 7

class Client
{
public:
	/**
	 * @brief Runs the client
	 */
	void run();


private:
	/**
	 * @brief Sends a message to the server
	 *
	 * @param server The server to send the message to
	 * @param message The message to send
	 */
	void sendMessage(sf::TcpSocket &server, std::string message);

	/**
	 * @brief Receives a message from the server
	 *
	 * @param server The server to receive the message from
	 *
	 * @return The message received
	 */
	std::string receiveMessage(sf::TcpSocket &server);

	/**
	 * @brief Registers an account
	 *
	 * @param server The server to register the account with
	 * @param page The page to go to
	 * @param balance The balance of the account
	 *
	 * @return 0 if the registration was successful, -1 if the registration failed
	 */
	int registerAccount(sf::TcpSocket &server, std::string *page, double *balance, std::string *username, std::string *password, std::string *confirmPassword2);

	/**
	 * @brief Logs the user in
	 *
	 * @param server The server to log the user in to
	 *
	 * @return 0 if the login was successful, -1 if the login failed
	 */
	int login(sf::TcpSocket &server, std::string *page, double *balance, std::string *username, std::string *password);

	/**
	 * @brief Handles a bet
	 *
	 * @param server The server to handle the bet with
	 * @param page The page to go to
	 * @param balance The balance of the account
	 *
	 * @return 0 if the bet was successful, -1 if the bet failed
	 */
	int bet(sf::TcpSocket &server, std::string *page, double *balance);

	/**
	 * @brief Handles a game
	 *
	 * @param server The server to handle the game with
	 * @param page The page to go to
	 * @param balance The balance of the account
	 *
	 * @return 0 if the game was successful, -1 if the game failed
	 */
	int game(sf::TcpSocket &server, std::string *page, double *balance, sf::RenderWindow window, ImageButton StandButton, ImageButton HitButton, ImageButton DoubleButton);

	/**
	 * @brief
	 *
	 * @param
	 * @param
	 * @param
	 *
	 * @return
	 */
	bool loadCards(std::vector<char> dealerSuits, std::vector<char> dealerRanks, std::vector<char> gamblerSuits, std::vector<char> gamblerRanks, sf::RenderWindow *window);

	/**
	 * @brief
	 *
	 * @param
	 * @param
	 * @param
	 *
	 * @return
	 */
	bool getCardsFromMessage(std::vector<char> *dealerSuits, std::vector<char> *dealerRanks, std::vector<char> *gamblerSuits, std::vector<char> *gamblerRanks, std::string *dealer, std::string *gambler, int *dealerValue, int *gamblerValue);

	/**
	 * @brief
	 *
	 * @param
	 * @param
	 * @param
	 *
	 * @return
	 */
	bool animateSprite(sf::Sprite *sprite, sf::Vector2f destination, int speed, sf::RenderWindow *window, sf::Texture *texture);

	struct Config{
    std::string serverIP;
    int serverPort;
    };

    /**
     * @brief Reads the config file
     * 
     * @param filename The name of the config file
     * 
     * @return The config
    */
    Config readConfig(const std::string& filename);
};
