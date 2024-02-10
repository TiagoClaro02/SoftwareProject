# BlackJack

This project is a Blackjack game developed in C++ for the Software Project course of the Master in Electronics and Computing Engineering of the Faculty of Engineering of the University of Porto (FEUP).
This game allows the users to play Blackjack against the computer, with the possibility of saving the current balance in an account. The gambler also gets to choose between the various casinos all arround the world, each with it's own table theme.

This game was developed by **João Oliveira**, **Joana Silva**, **Tiago Claro** and **Tomás Correia**.

## Prerequisites

To edit and compile this project you will need the following software installed on your windows machine:

    - Visual Studio 2022

## Installation

To install this project in your machine you need to follow the next steps:

    - Clone this repository
    - Open the project in Visual Studio 2022
    - Build the project
    - Run the project

## Usage

In this section we will explain how to use the application, from simply running it to executing the unit tests in the class Game.

### Run the application

To run the application you just need to download the `BlackJack.zip` file in the master branch and extract it. Then you just need to run the following executable:

    - BlcakJackServer/BlackJackServer.exe
    - BlackJackClient/BlackJackClient.exe

If you want to edit the code and run the application you need to follow the steps in the Installation section.

### Run the unit tests

Download the `BlackJack.zip` file in the master branch and extract it. Then go to BlackJackServer and click on the file `RunTests.bat`

## Configuration

The server IP and port are defined in the `config.txt` file. This IP must be the IP of the network interface of the server. The default values are:

```txt
# Config File
ServerIP= 127.0.0.1
ServerPort= 8080
```

## License

This project is licensed under the [MIT License](LICENSE).