# TANK-CITY_Game
my project game

#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class Map
{

	std::vector <sf::Vector2f> tilemap;
	std::vector <sf::Vector2f> tilehide;


public:
	void generate(sf::RenderWindow& window);
	bool checkWall(float x, float y);
	void createGreen(sf::RenderWindow& window);

};

