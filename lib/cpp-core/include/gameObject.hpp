/*
** File name :
** gameObject.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include <functional>
#include "SFML/Graphics.hpp"

class GameObject
{
    public:
        GameObject();
        GameObject(std::function<void(GameObject *)>);
       ~GameObject() = default;

        void update();
        void onCollide(GameObject *object);
        
         /* SETTERS */
        void setTag(std::string const &tag);
        void setType(std::string const &type);
        void setPosition(sf::Vector2f const &position);
        void setScale(sf::Vector2f const &scale);
        void setOrigin(sf::Vector2f const &origin);
        void setDirection(sf::Vector2f const &direction);
        void setHitbox(sf::Vector2f const &hitbox);
        void setHitbox(float const &x, float const &y);
        void setLayout(size_t const &layout);
        void setIndex(size_t const &index);
        void setSpeed(float const &speed);
        void setActive(bool const &active);
        void setFunction(std::function<void(GameObject *)> function);
        void setOnCollide(std::function<void(GameObject *, GameObject *)> onCollide);

        /* GETTERS */
        std::string     getTag(void)            const;
        std::string     getType(void)           const;
        sf::Vector2f    getPosition(void)       const;
        sf::Vector2f    getScale(void)          const;
        sf::Vector2f    getOrigin(void)         const;
        sf::Vector2f    getDirection(void)      const;
        sf::Vector2f    getHitbox(void)         const;
        size_t          getLayout(void)         const;
        size_t          getIndex(void)          const;
        float           getSpeed(void)          const;
        bool            getActive(void)         const;

     private:
        std::string                                         _tag;
        std::string                                         _type;
        sf::Vector2f                                        _position;
        sf::Vector2f                                        _scale;
        sf::Vector2f                                        _origin;
        sf::Vector2f                                        _direction;
        sf::Vector2f                                        _hitbox;
        size_t                                              _layout;
        size_t                                              _index;
        float                                               _speed;
        bool                                                _active;
        std::function<void(GameObject *)>                   _function;
        std::function<void(GameObject *, GameObject *)>     _onCollide;
};
