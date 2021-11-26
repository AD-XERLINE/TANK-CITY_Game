# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>

class Items 
{
public:
	Items(sf::Vector2f size, sf::Vector2f newPos, sf::Texture* texture)
	{
		item.setSize(size);
		this->items_texture = texture;
		item.setTexture(this->items_texture);
		item.setOrigin(sf::Vector2f(item.getLocalBounds().width / 2, item.getLocalBounds().height / 2));
		item.setPosition(newPos);
	}
	sf::FloatRect getGlobalBounds()
	{
		return this->item.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(item);
	}



private:

	sf::RectangleShape item;
	sf::Texture* items_texture;
	int hp2 = 1;
	int action;
	int point;
	int type;


};
