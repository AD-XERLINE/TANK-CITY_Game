# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>
#include <cmath>

class Bullet {
public:

	Bullet(sf::Vector2f size,float angle) {
		bullet.setSize(size);
		bullet.setOrigin(0, bullet.getLocalBounds().height/2);
		bullet.setRotation(angle - 90);
		bullet.setFillColor(sf::Color::Yellow);
		this->angle = angle;
	}
	void fire(float speed ) {
			bullet.move(speed * sinf(angle*3.14/180), -speed * cosf(angle * 3.14 / 180));
	}
	
	int getR() {
		return bullet.getPosition().x + bullet.getSize().x;
	}
	int getL() {
		return bullet.getPosition().x;
	}
	int getT() {
		return bullet.getPosition().y;
	}
	int getB() {
		return bullet.getPosition().y + bullet.getSize().y;
	}
	void draw(sf::RenderWindow& window) {
		window.draw(bullet);
	}
	void setPos(sf::Vector2f newPos) {
		bullet.setPosition(newPos);
	}
	sf::FloatRect getGlobalBounds()
	{
		return this->bullet.getGlobalBounds();
	}

private:
	float angle;
	sf::RectangleShape bullet;
};

