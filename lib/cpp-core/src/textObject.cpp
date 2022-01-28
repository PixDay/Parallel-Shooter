/*
** File name :
** textObject.cpp
** File creator :
** Adrien Colombier
*/

#include "textObject.hpp"

TextObject::TextObject(std::string const &text):
_text(text)
{
    this->setType("TextObject");
    _font.loadFromFile("font/Teko-Bold.ttf");
    _render.setFont(_font);
    _render.setCharacterSize(24);
    _render.setFillColor(sf::Color::White);
    _render.setString(_text);
};

TextObject::TextObject(std::string const &text, std::string const &fontPath):
_text(text)
{
    this->setType("TextObject");
    _font.loadFromFile(fontPath);
    _render.setFont(_font);
}

TextObject::TextObject(std::string const &text, std::string const &fontPath, size_t color):
_text(text),
_color(sf::Color((sf::Uint32)color))
{
    this->setType("TextObject");
    _font.loadFromFile(fontPath);
    _render.setFont(_font);
}

/* SETTERS */
void TextObject::setText(std::string const &text)
{
    _text = text;
    _render.setString(_text);
}

void TextObject::setFont(std::string const &fontPath)
{
    _font.loadFromFile(fontPath);
}

void TextObject::setColor(size_t color)
{
    _color = sf::Color((sf::Uint32)color);
    _render.setFillColor(_color);
}

void TextObject::setPosition(sf::Vector2f const &position)
{
    GameObject::setPosition(position);
    _render.setPosition(position);
}

void TextObject::setSize(unsigned int const &size)
{
    _render.setCharacterSize(size);
}

/* GETTERS */
std::string TextObject::getText(void) const
{
    return _text;
}

sf::Font TextObject::getFont(void) const
{
    return _font;
}

sf::Color TextObject::getColor(void) const
{
    return _color;
}

sf::Text TextObject::getRender(void) const
{
    return _render;
}