# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>

class King
{
public:
	King(sf::Vector2f size, sf::Vector2f newPos, sf::Texture* texture)
	{
		Kong.setSize(size);
		this->King_texture = texture;
		Kong.setTexture(this->King_texture);
		Kong.setOrigin(sf::Vector2f(Kong.getLocalBounds().width / 2, Kong.getLocalBounds().height / 2));
		Kong.setPosition(newPos);
	}
	sf::FloatRect getGlobalBounds()
	{
		return this->Kong.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(Kong);
	}



private:

	sf::RectangleShape Kong;
	sf::Texture* King_texture;
	int hp2 = 10;
	int action;
	int point;
	int type;


};
