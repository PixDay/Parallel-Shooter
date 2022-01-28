#include <stdlib.h>
#include <time.h>
#include "core.h"

void secondPlayer(GameObject *self)
{
  sf::Vector2f position = self->getPosition();
  sf::Vector2f ballPosition = static_cast<DisplayableObject *>(self)->getObjects()[0]->getPosition();

  if (position.y > ballPosition.y - 75.0f)
    position.y -= self->getSpeed();
  if (position.y < ballPosition.y - 75.0f)
    position.y += self->getSpeed();
  position.y = (position.y < 0.0f) ? 0.0f : (position.y > 930.0f) ? 930.0f : position.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void player(GameObject *self)
{
  sf::Vector2f position = self->getPosition();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    position.y -= self->getSpeed();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    position.y += self->getSpeed();
  position.y = (position.y < 0.0f) ? 0.0f : (position.y > 930.0f) ? 930.0f : position.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ballMovement(GameObject *self)
{
  sf::Vector2f direction = self->getDirection();
  sf::Vector2f position = self->getPosition();

  if (position.x > 1870.0f)
    direction.x = -(self->getDirection().x);
  if (position.x < 0.0f) 
    direction.x = -(self->getDirection().x);
  if (position.y > 1030.0f)
    direction.y = -(self->getDirection().y);
  if (position.y < 0.0f)
    direction.y = -(self->getDirection().y);
  position.x = position.x + (direction.x * self->getSpeed());
  position.y = position.y + (direction.y * self->getSpeed());
  self->setDirection(direction);
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ballCollision(GameObject *self, GameObject *collided)
{
    TextObject *scoreObject;
    sf::Vector2f direction = self->getDirection();
    sf::Vector2f position = {1920.0f / 2.0f, 1080.0f / 2.0f};
    std::string score;
    int intScore;

    direction.x = -(self->getDirection().x);
    self->setSpeed(self->getSpeed() + 0.1f);
    if (collided->getTag() == "Line") {
      if (static_cast<DisplayableObject *>(self)->getPosition().x < 960.0f)
        scoreObject = static_cast<TextObject *>(static_cast<DisplayableObject *>(self)->getObjects()[1]);
      else
        scoreObject = static_cast<TextObject *>(static_cast<DisplayableObject *>(self)->getObjects()[0]);
      static_cast<DisplayableObject *>(self)->setPosition(position);
      self->setSpeed(4.0f);
      score = scoreObject->getText();
      intScore = std::stoi(score);
      intScore++;
      scoreObject->setText(std::to_string(intScore));
    }
    self->setDirection(direction);
}

void cameraMovement(GameObject *self)
{
    sf::Vector2f position = {0.0f, 0.0f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        position.x -= 5.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        position.x += 5.0f;
    static_cast<Camera *>(self)->move(position);
}

int main()
{
    App app = App();
    TextObject *playerScore = new TextObject("0");
    TextObject *botScore = new TextObject("-1");
    DisplayableObject *player1 = new DisplayableObject("../../img/player.png", &player);
    DisplayableObject *player2 = new DisplayableObject("../../img/player.png", &secondPlayer);
    DisplayableObject *line1 = new DisplayableObject("../../img/line.png");
    DisplayableObject *line2 = new DisplayableObject("../../img/line.png");
    DisplayableObject *ball = new DisplayableObject("../../img/ball.png", &ballMovement);
    sf::Vector2f position = {50.0f, 500.0f};
    GameObject *camera = app.getCamera();
    ball->setTag("Ball");
    ball->setSpeed(5.0f);
    player1->setTag("Player");
    player2->setTag("Bot");
    line1->setTag("Line");
    line2->setTag("Line");
    player1->setPosition(position);
    position.x = 1820.0f;
    player2->setPosition(position);
    player2->setSpeed(5.5f);
    position.x = 73.0f;
    position.y = 0.0f;
    line1->setPosition(position);
    position.x = 1843.0f;
    line2->setPosition(position);
    position.x = 500.0f;
    position.y = 50.0f;
    playerScore->setPosition(position);
    position.x = 1460.0f;
    botScore->setPosition(position);
    playerScore->setSize(50);
    botScore->setSize(50);
    ball->addObject(playerScore);
    ball->addObject(botScore);
    camera->setFunction(&cameraMovement);
    srand(time(NULL));
    app.addScene("Game");
    app.setCurrentScene("Game");
    app.addObject(new DisplayableObject("../../img/background.png"));
    app.addObject(ball);
    app.addObject(line1);
    app.addObject(line2);
    app.addObject(player1);
    app.addObject(player2);
    app.addObject(playerScore);
    app.addObject(botScore);
    app.addObject(camera);
    player2->addObject(ball);
    app.addCollisionPair("Ball", "Player");
    app.addCollisionPair("Ball", "Bot");
    app.addCollisionPair("Ball", "Line");
    ball->setOnCollide(&ballCollision);
    app.run();
    return 0;
}