#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "sstream"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
#define TAB_KEY 9

class TextBox
{
public:
    /**
     * @brief Construct a new TextBox object
     */
    TextBox(int size, sf::Color color, bool sel, std::string text);

    /**
     * @brief Defines the font of the textbox
     */
    void setFont(sf::Font &font);

    /**
     * @brief Sets the position of the textbox
     */
    void setPosition(sf::Vector2f pos);

    /**
     * @brief Sets the limit of characters the textbox can hold
     */
    void setLimit(bool ToF);

    /**
     * @brief Sets the limit of characters the textbox can hold
     */
    void setLimit(bool ToF, int lim);

    /**
     * @brief Sets the selected state of the textbox
     */
    void setSelected(bool sel);

    /**
     * @brief Gets the string of the textbox
     */
    std::string getText();

    /**
     * @brief Handles the input for the textbox
     */
    void drawTo(sf::RenderWindow &window);

    /**
     * @brief Handles the input for the textbox
     */
    void typedOn(sf::Event input);

    /**
     * @brief Checks if the mouse is over the textbox
     */
    bool isMouseOver(sf::RenderWindow &window);

    /**
     * @brief Checks if the textbox is selected
     */
    bool isSelected = false;

    /**
     * @brief Sets the text of the textbox
     */
    void setText(std::string text);

private:
    sf::Text textbox;
    std::ostringstream text;
    bool hasLimit = true;
    int limit;
    std::string defaultText;

    /**
     * @brief Handles the input logic for the textbox
     */
    void inputLogic(int charTyped);

    /**
     * @brief Deletes the last character in the textbox
     */
    void deleteLastChar();
};
