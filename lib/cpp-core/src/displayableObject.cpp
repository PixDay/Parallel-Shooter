/*
** File name :
** displayableObject.cpp
** File creator :
** Adrien Colombier
*/

#include "displayableObject.hpp"

DisplayableObject::DisplayableObject(std::string const &texture):
_sprite(new sf::Sprite()),
_visibleTime(-1.0f)
{
    this->setType("DisplayableObject");
    
    _texture.loadFromFile(texture);
    _sprite->setTexture(_texture, false);
}

DisplayableObject::DisplayableObject(std::string const &texture, std::function<void(GameObject *)> function):
_sprite(new sf::Sprite()),
_visibleTime(-1.0f)
{
    this->setType("DisplayableObject");

    _texture.loadFromFile(texture);
    _sprite->setTexture(_texture, false);
    GameObject::setFunction(function);
}

DisplayableObject::~DisplayableObject()
{
    delete _sprite;
}

void DisplayableObject::update()
{
    if (_visibleTime > 0.0f && _clock.getElapsedTime().asSeconds() >= _visibleTime) {
        this->setActive(false);
    }
}

void DisplayableObject::resetTimer(void)
{
    _clock.restart();
}

/* ADDERS */

void DisplayableObject::addObject(DisplayableObject *object)
{
    _objects.emplace_back(object);
}

/* DELETERS */

void DisplayableObject::deleteObject(std::string const &tag)
{
    size_t iterator = 0;

    for (auto object : _objects) {
        if (object->getTag() == tag) { 
            delete object;
            _objects.erase(_objects.begin() + iterator);
            break;
        }
        iterator++;
    }
}


/* SETTERS */

void DisplayableObject::setTexture(std::string const &texture)
{
    _texture.loadFromFile(texture);
    _sprite->setTexture(_texture, false);
}

void DisplayableObject::setTexture(sf::Texture const &texture)
{
    _texture = texture;
    _sprite->setTexture(texture, false);
}

void DisplayableObject::setPosition(sf::Vector2f const &position)
{
    GameObject::setPosition(position);
    _sprite->setPosition(position);
}

void DisplayableObject::setOrigin(sf::Vector2f const &origin)
{
    GameObject::setOrigin(origin);
    _sprite->setOrigin(origin);
}

void DisplayableObject::setScale(sf::Vector2f const &scale)
{
    GameObject::setScale(scale);
    _sprite->setScale(scale);
}

void DisplayableObject::setHitbox(sf::Vector2f const &hitbox)
{
    GameObject::setHitbox(hitbox);
}

void DisplayableObject::setHitbox(float const &x, float const &y)
{
    GameObject::setHitbox(x, y);
}

void DisplayableObject::setAngle(float const &angle)
{
    _angle = angle;
    _sprite->setRotation(angle);
}

void DisplayableObject::setAngleByCenter(float const &angle)
{
    sf::Vector2u center = _sprite->getTexture()->getSize();

    center.x = center.x / 2;
    center.y = center.y / 2;
    _sprite->setOrigin(static_cast<sf::Vector2f>(center));
    _angle = angle;
    _sprite->setRotation(_angle);
    _sprite->setOrigin(GameObject::getOrigin());
}

void DisplayableObject::setVisibleTime(float time)
{
    _clock.restart();
    _visibleTime = time;
}

/* GETTERS */

sf::Sprite* DisplayableObject::getSprite(void) const
{
    return _sprite;
}

sf::Texture DisplayableObject::getTexture(void) const
{
    return _texture;
}

float DisplayableObject::getTime(void) const
{
    return _clock.getElapsedTime().asSeconds();
}

float DisplayableObject::getAngle(void) const
{
    return _angle;
}

std::vector<DisplayableObject *> DisplayableObject::getObjects() const
{
    return _objects;
}