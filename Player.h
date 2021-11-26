# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>

class Player {
public:
	Player(sf::Vector2f size) {
		player.setSize(size);
	}

	void move(sf::Vector2f dir) {
		player.move(dir);
	}

	int getX() {
		return player.getPosition().x;
	}
	int getY() {
		return player.getPosition().y;
	}

	const int& getHp() const;
	const int& getHpMax() const;


private:
	sf::RectangleShape player;
	int hp;
	int hpmax;
	//playerGUI
	sf::RectangleShape playerhpbar;
	sf::RectangleShape playerhpbarback;


	void initvarible();
	void initGUI();
	void updateGUI();

	void randerGUI();

};
