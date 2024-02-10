#include "TextBox.h"

TextBox::TextBox(int size, sf::Color color, bool sel, std::string text)
{
    this->defaultText = text;
    textbox.setCharacterSize(size);
    textbox.setFillColor(color);
    isSelected = sel;
    if (sel)
    {
        textbox.setString("_");
    }
    else
    {
        textbox.setString(defaultText);
    }
}

void TextBox::inputLogic(int charTyped)
{
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY && charTyped != TAB_KEY)
    {
        text << static_cast<char>(charTyped);
    }

    if (charTyped == DELETE_KEY)
    {
        if (text.str().length() > 0)
        {
            deleteLastChar();
        }
    }

    if (charTyped == TAB_KEY || charTyped == ENTER_KEY || charTyped == ESCAPE_KEY)
    {
        text.str() = defaultText;
    }

    textbox.setString(text.str() + "_");
}

void TextBox::deleteLastChar()
{
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++)
    {
        newT += t[i];
    }
    text.str("");
    text << newT;

    textbox.setString(text.str());
}

void TextBox::setFont(sf::Font &font)
{
    textbox.setFont(font);
}

void TextBox::setPosition(sf::Vector2f pos)
{
    textbox.setPosition(pos);
}

void TextBox::setLimit(bool ToF)
{
    hasLimit = ToF;
}

void TextBox::setLimit(bool ToF, int lim)
{
    hasLimit = ToF;
    limit = lim - 1;
}

void TextBox::setSelected(bool sel)
{
    if (textbox.getString() == this->defaultText)
    {
        textbox.setString("_");
    }
    else if (!sel)
    {
        textbox.setString(text.str());
    }
    else
    {
        textbox.setString(text.str() + "_");
    }

    isSelected = sel;

    if (!sel && text.str() == "")
    {
        textbox.setString(this->defaultText);
        /* std::string t = text.str();
        std::string newT = "_";
        for (int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        textbox.setString(newT); */
    }
}

std::string TextBox::getText()
{
    return text.str();
}

void TextBox::drawTo(sf::RenderWindow &window)
{
    window.draw(textbox);
}

void TextBox::typedOn(sf::Event input)
{
    if (isSelected)
    {
        int charTyped = input.text.unicode;
        if (charTyped < 128)
        {
            if (hasLimit)
            {
                if (text.str().length() <= limit)
                {
                    inputLogic(charTyped);
                }
                else if (text.str().length() > limit && charTyped == DELETE_KEY)
                {
                    deleteLastChar();
                }
            }
            else
            {
                inputLogic(charTyped);
            }
        }
    }
}

bool TextBox::isMouseOver(sf::RenderWindow &window)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = textbox.getPosition().x;
    float btnPosY = textbox.getPosition().y;

    float btnxPosWidth = textbox.getPosition().x + this->limit * 24;
    float btnyPosHeight = textbox.getPosition().y + textbox.getLocalBounds().height;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
    {
        return true;
    }
    return false;
}

void TextBox::setText(std::string text)
{
    textbox.setString(text);
}