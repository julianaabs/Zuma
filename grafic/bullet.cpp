#include <iostream>

class Bullet
{
private:
  sf::Vector2f  position;
  sf::Vector2f  velocity;
  sf::Sprite  sprite;

public:
  Bullet( const sf::Vector2f& startingposition, const sf::Vector2f& targetposition )
  {
    sprite.setTexture( your_texture_manager.get( /*função que gere o caminho para uma das 4 balas aleatoriamente*/ ) ); // note: one forward slash.

    // do other sprite setup here, like setting the texture rect or whatever

    position = startingposition;
    sprite.setPosition( position );

    // calculate the velocity here per fun2code's approach
  }

  // called every logic update
  void update()
  {
    // move the bullet position, update the sprite to match
    position += velocity;
    sprite.setPosition( position );
  }
};
