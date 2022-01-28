/*
** File name :
** mouse.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "displayableObject.hpp"

class Mouse : public DisplayableObject
{
    public:
        Mouse() = default;
        Mouse(std::string const &texture) {}
       ~Mouse() = default;


        /* GETTERS */
        sf::Mouse   getMouse(void)  const {return _mouse;};

    private:
        sf::Mouse   _mouse;
};