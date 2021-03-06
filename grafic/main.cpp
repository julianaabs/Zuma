#include "SFML/Graphics.hpp"
#include <iostream>
#include "SFML/Window/Mouse.hpp"
#include <math.h>
//#include "SFML/Graphics/Sprite.hpp"

int main(){
    const float PI = 3.14159265;


	sf::RenderWindow window(sf::VideoMode(640, 450), "Zuma");
    sf::Clock clock;


    //definir objetos de texturas
	sf::Texture interfaceText;
	sf::Texture caminho1Text;
	sf::Texture caminho2Text;
	sf::Texture caminho3Text;
	sf::Texture caminho4Text;
	sf::Texture caminho5Text;
	sf::Texture Amarela;
    sf::Texture Verde;
    sf::Texture Azul;
    sf::Texture Vermelha;
    sf::Texture ShooterText;

    //carregar imagens nos objetos textura
	interfaceText.loadFromFile("interface.png");
    caminho1Text.loadFromFile("l1.png");
    caminho2Text.loadFromFile("l2.png");
	caminho3Text.loadFromFile("l3.png");
	caminho4Text.loadFromFile("l4.png");
	caminho5Text.loadFromFile("l5.png");
    Vermelha.loadFromFile("vermelha.png");
    Azul.loadFromFile("azul.png");
    Amarela.loadFromFile("amarela.png");
    Verde.loadFromFile("verde.png");
	ShooterText.loadFromFile("Shooter.png");

	//definição de objetos sprites ,setando suas texturas com objetos texturas definidos e mudar sua posição.
	sf::Sprite interface;
	interface.setTexture(interfaceText);

	sf::Sprite l1;
	l1.setTexture(caminho1Text);
	l1.setPosition(sf::Vector2f(28, 56));
    sf::Sprite l2;
	l2.setTexture(caminho2Text);
	l2.setPosition(sf::Vector2f(583, 72));
    sf::Sprite l3;
	l3.setTexture(caminho3Text);
	l3.setPosition(sf::Vector2f(53, 337));
    sf::Sprite l4;
	l4.setTexture(caminho4Text);
	l4.setPosition(sf::Vector2f(33, 140));
    sf::Sprite l5;
	l5.setTexture(caminho5Text);
	l5.setPosition(sf::Vector2f(40, 121));

    sf::Sprite bola;
	bola.setTexture(Vermelha);
	bola.setPosition(sf::Vector2f(30, 57));

    sf::Sprite Shooter;
    Shooter.setTexture(ShooterText);
    Shooter.setPosition(sf::Vector2f(300, 240));

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}


        float MouseX = sf::Mouse::getPosition(window).x;
        float MouseY = sf::Mouse::getPosition(window).y;
        float a = 300 - MouseX;
        float b = 220 - MouseY;
        float mouseAngle = (atan2(b, a)) * 180 / PI;
        Shooter.setRotation(mouseAngle +180);

		sf::Time time = clock.getElapsedTime();

        if (bola.getGlobalBounds().intersects(l1.getGlobalBounds())){
			bola.move(sf::Vector2f(0.001 * time.asSeconds(), 0));

		}
		else{
            if(bola.getGlobalBounds().intersects(l2.getGlobalBounds())){
                bola.move(sf::Vector2f(0 , 0.001 * time.asSeconds()));
            }else{
                if(bola.getGlobalBounds().intersects(l3.getGlobalBounds())){
                    bola.move(sf::Vector2f(0.001 * -time.asSeconds(), 0));
                }else{
                    if(bola.getGlobalBounds().intersects(l4.getGlobalBounds())){
                        bola.move(sf::Vector2f(0 , 0.001 * -time.asSeconds()));
                    }
                    else{
                        if(bola.getGlobalBounds().intersects(l5.getGlobalBounds())){
                            bola.move(sf::Vector2f(0.001 * time.asSeconds(), 0));
                        }
                    }
                }
            }
		}
		window.clear();
		window.draw(interface);
		window.draw(l1);
		window.draw(l2);
		window.draw(l3);
		window.draw(l4);
		window.draw(l5);
		window.draw(bola);
        window.draw(Shooter);
		window.display();
	}
}
