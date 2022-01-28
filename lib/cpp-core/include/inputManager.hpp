/*
** File name :
** inputManager.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "input.hpp"

class InputManager
{
    public:
        InputManager();
       ~InputManager() = default;

       void addInput(Input *input);
       void addInput(std::string const &keyName, sf::Keyboard::Key key);
       void deleteInput(std::string const &keyName);
       bool isKeyPressed(std::string const &keyName) const;
       
    private:
        std::vector<Input *>    _inputs;
};