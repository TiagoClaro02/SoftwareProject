#include "Button.h"

ImageButton::ImageButton(const std::string &imagePath, float x, float y)
{
    if (!normalTexture.loadFromFile(imagePath))
    {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
    }

    sprite.setTexture(normalTexture);
    sprite.setPosition(x, y);
}

ImageButton::~ImageButton()
{
    // No explicit cleanup needed as SFML handles texture destruction
}

void ImageButton::setOverImage(const std::string &OverImagePath)
{
    if (!OverTexture.loadFromFile(OverImagePath))
    {
        std::cerr << "Failed to load OverImage: " << OverImagePath << std::endl;
    }
}

bool ImageButton::isClicked(const sf::RenderWindow &window)
{
    if (isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !this->clicked)
    {
        this->clicked = true;
        return true;
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // Reset clicked to false when the mouse button is released
        this->clicked = false;
    }

    return false;
}

void ImageButton::update(const sf::RenderWindow &window)
{
    if (isMouseOver(window))
    {
        sprite.setTexture(OverTexture);
    }
    else
    {
        sprite.setTexture(normalTexture);
    }
}

void ImageButton::draw(sf::RenderWindow &window) const
{

    window.draw(sprite);
}

bool ImageButton::isMouseOver(const sf::RenderWindow &window) const
{
    if (!enabled)
    {
        return false;
    }
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::FloatRect bounds = sprite.getGlobalBounds();
    return bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}