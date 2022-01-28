/*
** File name :
** core.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "SFML/Graphics.hpp"
#include "displayableObject.hpp"
#include "textObject.hpp"
#include "sceneManager.hpp"
#include "inputManager.hpp"
#include "camera.hpp"

#define STOP_RUN "STOP_RUN"

class App 
{
    public:
        App();
       ~App() = default;

        bool run(void);

        /* ADDERS */
        void addScene(std::string const &name);
        void addObject(GameObject *object);
        void addObjectTo(GameObject *object, std::string const &name);
        void addInput(Input *input);
        void addInput(std::string const &keyName, sf::Keyboard::Key key);
        void addCollisionPair(std::string const &tag1, std::string const &tag2);

        /* DELETERS */
        void deleteCollisionPair(std::string const &tag1, std::string const &tag2);

        /* SETTERS */
        void setCurrentScene(size_t const &scene);
        void setCurrentScene(std::string const &name);
        
        /* GETTERS */
        SceneManager getSceneManager(void)  const;
        float        getTick(void);
        bool         fpsPassed(void);
        Camera      *getCamera(void);
        
    private:
        bool draw(void);
        Camera                 *_camera;
        sf::RenderWindow       *_window;
        sf::Keyboard::Key       _leaveKey;
        SceneManager            _sceneManager;
        InputManager            _inputManager;
        sf::Clock               _clock;
        float                   _fps;
};