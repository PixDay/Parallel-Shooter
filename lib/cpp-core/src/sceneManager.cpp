/*
** File name :
** sceneManager.cpp
** File creator :
** Adrien Colombier
*/

#include <iostream>
#include "sceneManager.hpp"

SceneManager::SceneManager():
_currentScene(0)
{
    this->addScene("default");
}

void SceneManager::clearSceneContent(std::string const &name)
{
    size_t index = getScene(name);

    while (!_scenes[index]->getGameObjects().empty())
    {
        _scenes[index]->deleteObject(0);
    }
}

/* ADDERS */
 
void SceneManager::addScene(std::string const &name)
{
    Scene *scene = new Scene(name);

    _scenes.emplace_back(scene);
}

void SceneManager::addObject(GameObject *object)
{
    _scenes[_currentScene]->addObject(object);
}

void SceneManager::addObjectTo(GameObject *object, std::string const &name)
{
    _scenes[this->getScene(name)]->addObject(object);
}

void SceneManager::addCollisionPair(std::string const &tag1, std::string const &tag2)
{
    Pair pair(tag1, tag2);

    _collisionPair.push_back(pair);
}

/* DELETERS */

void SceneManager::deleteScene(std::string const &name)
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name) {
            _scenes.erase(_scenes.begin() + iterator);
            delete scene;
            break;
        }
        iterator++;
    }
}

void SceneManager::deleteCollisionPair(std::string const &tag1, std::string const &tag2)
{
    size_t iterator = 0;

    for (auto collision : _collisionPair) {
        if (collision.getFirst() == tag1 && collision.getSecond() == tag2) {
            _collisionPair.erase(_collisionPair.begin() + iterator);
            break;
        }
        iterator++;
    }
}

/* SETTERS */

void SceneManager::setCurrentScene(size_t const &scene)
{
    _currentScene = scene;
}

void SceneManager::setCurrentScene(std::string const &name)
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name) {
            _currentScene = iterator;
            break;
        }
        iterator++;
    }
}

/* GETTERS */

std::vector<Scene *> SceneManager::getScenes() const
{
    return _scenes;
}

size_t SceneManager::getCurrentScene() const
{
    return _currentScene;
}

size_t SceneManager::getScene(std::string const &name) const
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name)
            return iterator;
        iterator++;
    }
    return _currentScene;
}

GameObject *SceneManager::getGameObject(std::string const &tag) const
{
    for (auto gameObject : _scenes[_currentScene]->getGameObjects()) {
        if (gameObject->getTag() == tag)
            return gameObject;
    }
    return nullptr;
}

void SceneManager::onCollideTrigger(void)
{
    GameObject *collidedObject;

    for (auto pair : _collisionPair) {
        if (collidedObject = collide(pair.getFirst(), pair.getSecond())) {
            GameObject *object = getGameObject(pair.getFirst());
            object->onCollide(collidedObject);
        }
    }
}

GameObject *SceneManager::collide(std::string const &tag1, std::string const &tag2) const
{
    DisplayableObject *object1 = nullptr;
    DisplayableObject *object2 = nullptr;
    
    for (auto object : _scenes[_currentScene]->getGameObjects()) {
        if (object->getTag() == tag1)
            object1 = static_cast<DisplayableObject *>(object);
        if (object->getTag() == tag2)
            object2 = static_cast<DisplayableObject *>(object);
        if (object1 != nullptr && object2 != nullptr) {
            sf::Rect<float> obj1(
                object1->getPosition(), 
                {(float)object1->getSprite()->getTexture()->getSize().x * object1->getScale().x, 
                (float)object1->getSprite()->getTexture()->getSize().y * object1->getScale().y}
            );
            sf::Rect<float> obj2(
                object2->getPosition(), 
                {(float)object2->getSprite()->getTexture()->getSize().x * object2->getScale().x, 
                (float)object2->getSprite()->getTexture()->getSize().y * object2->getScale().y}
            );
            if (obj1.intersects(obj2)) {
                return object2;
            }
        }
    }
    return nullptr;
}