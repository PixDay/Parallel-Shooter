/*
** File name :
** scene.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "gameObject.hpp"

class Scene
{
    public:
        Scene(std::string const &name);
        ~Scene() = default;

        /* ADDERS */
        void addObject(GameObject * const gameObject);

        /* DELETERS */
        void deleteObject(std::string const &tag);
        void deleteObject(size_t const &index);
        void eraseObject(std::string const &tag);

        /* SETTERS */
        void setName(std::string const &name);

        /* GETTERS */
        std::vector<GameObject *>   getGameObjects()                    const;
        std::string                 getName()                           const;
        bool                        isExisting(std::string const &tag)  const;

    private:
        std::string                 _name;
        std::vector<GameObject *>   _gameObjects;
};