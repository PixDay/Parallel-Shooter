/*
** File name :
** camera.cpp
** File creator :
** Adrien Colombier
*/

#include "camera.hpp"

Camera::Camera()
{
    this->_view.setSize(1920.0f, 1080.f);
    this->_view.setCenter(1920.0f / 2.0f, 1080.0f / 2.0f);
}

Camera::Camera(sf::Vector2f const &position)
{
    this->_view.setCenter(position.x, position.y);
}

Camera::~Camera()
{

}

void Camera::move(sf::Vector2f const &vector)
{
    this->_view.move(vector);
}

void Camera::move(float const &x, float const &y)
{
    this->_view.move(x, y);
}

/* ADDERS */

/* DELETERS */

/* SETTERS */
void Camera::setOrigin(sf::Vector2f const &origin)
{
    this->_view.setCenter(origin);
}

void Camera::setSize(sf::Vector2f const &size)
{
    this->_view.setSize(size);
}

void Camera::setRotation(float const &rotation)
{
    this->_view.setRotation(rotation);
}

void Camera::setObjectToFollow(GameObject *object)
{
    this->_toFollow = object;
}

/* GETTERS */
sf::Vector2f Camera::getPosition(void) const
{
    return this->_view.getCenter();
}

sf::Vector2f Camera::getOrigin(void) const
{
    return this->_view.getCenter();
}

sf::Vector2f Camera::getSize(void) const
{
    return this->_view.getSize();
}

float Camera::getRotation(void) const
{
    return this->_view.getRotation();
}

sf::View Camera::getView(void) const
{
    return this->_view;
}

GameObject *Camera::getToFollow(void) const
{
    return this->_toFollow;
}