# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>

class Items2
{
public:
	Items2(sf::Vector2f size, sf::Vector2f newPos, sf::Texture* texture)
	{
		item2.setSize(size);
		this->items2_texture = texture;
		item2.setTexture(this->items2_texture);
		item2.setOrigin(sf::Vector2f(item2.getLocalBounds().width / 2, item2.getLocalBounds().height / 2));
		item2.setPosition(newPos);
	}
	sf::FloatRect getGlobalBounds()
	{
		return this->item2.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(item2);
	}



private:

	sf::RectangleShape item2;
	sf::Texture* items2_texture;
	int hp2 = 1;
	int action;
	int point;
	int type;


};
