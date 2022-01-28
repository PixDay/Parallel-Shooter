/*
** File name :
** camera.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "gameObject.hpp"

class Camera : public GameObject
{
        public:
        Camera();
        Camera(sf::Vector2f const &position);
       ~Camera();
        
        void move(sf::Vector2f const &vector);
        void move(float const &x, float const &y);
        /* ADDERS */

        /* DELETERS */

        /* SETTERS */
        void setOrigin(sf::Vector2f const &origin);
        void setSize(sf::Vector2f const &size);
        void setRotation(float const &rotation);
        void setObjectToFollow(GameObject *object);

        /* GETTERS */
        sf::Vector2f    getPosition(void)   const;
        sf::Vector2f    getOrigin(void)     const;
        sf::Vector2f    getSize(void)       const;
        float           getRotation(void)   const;
        sf::View        getView(void)       const;
        GameObject     *getToFollow(void)   const;
        
    private:
        sf::View    _view;
        GameObject *_toFollow;
};