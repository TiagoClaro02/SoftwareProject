#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class ImageButton
{
public:
    ImageButton(const std::string &imagePath, float x, float y);
    ~ImageButton();

    void setOverImage(const std::string &OverImagePath);

    bool isClicked(const sf::RenderWindow &window);
    void update(const sf::RenderWindow &window); // Check for mouse Over and update the button accordingly
    void draw(sf::RenderWindow &window) const;
    bool isMouseOver(const sf::RenderWindow &window) const;
    sf::Sprite sprite;
    bool enabled = true;
    sf::Texture normalTexture;

private:
    sf::Texture OverTexture;

    bool clicked;
};