# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Map.h"

class Enemy1 {
public:
	Enemy1(sf::Vector2f size, sf::Vector2f newPos, sf::Texture* texture)
	{
		enemy1.setSize(size);
		this->enemy_texture1 = texture;
		enemy1.setTexture(this->enemy_texture1);
		enemy1.setOrigin(sf::Vector2f(enemy1.getLocalBounds().width / 2, enemy1.getLocalBounds().height / 2));
		enemy1.setPosition(newPos);
		shoot = 0;
	}
	Map pam;
	sf::FloatRect getGlobalBounds()
	{
		return this->enemy1.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(enemy1);
	}
	void update(sf::RenderWindow& window, float deltaTime)
	{
		if (actionDelay1 >= actionDelatMax1)
		{
			action = rand() % 5;
			actionDelay1 = 0;
			moveDuration1 = 1.0f;
		}

		if (moveDuration1 > 0)
		{
			switch (action)
			{
			case 1://Up
				if (enemy1.getPosition().y - speed * deltaTime >= 25)
				{
					if (!pam.checkWall(enemy1.getPosition().x, enemy1.getPosition().y - speed * deltaTime))
					{
						enemy1.setRotation(0);
						enemy1.move(sf::Vector2f(0, -speed * deltaTime));
					}
				}
				break;
			case 0: //Down
				if (enemy1.getPosition().y + speed * deltaTime <= 975)
				{
					if (!pam.checkWall(enemy1.getPosition().x, enemy1.getPosition().y + speed * deltaTime))
					{
						enemy1.setRotation(180);
						enemy1.move(sf::Vector2f(0, speed * deltaTime));
					}
				}
				break;
			case 2: //Right
				if (enemy1.getPosition().x + speed * deltaTime <= 975)
				{
					if (!pam.checkWall(enemy1.getPosition().x + speed * deltaTime, enemy1.getPosition().y))
					{
						enemy1.setRotation(90);
						enemy1.move(sf::Vector2f(speed * deltaTime, 0));
					}
				}
				break;
			case 3: //Left
				if (enemy1.getPosition().x - speed * deltaTime >= 25)
				{
					if (!pam.checkWall(enemy1.getPosition().x - speed * deltaTime, enemy1.getPosition().y))
					{
						enemy1.setRotation(270);
						enemy1.move(sf::Vector2f(-speed * deltaTime, 0));
					}
				}
				break;
			case 4: //shoot
				shoot = 1;
				moveDuration1 = 0.f;
				break;
			}
			moveDuration1 -= deltaTime;
		}
		else
			actionDelay1 += deltaTime;
	}

	void stopShoot()
	{
		shoot = 0;
	}

	bool getShoot()
	{
		return shoot;
	}

	float getRotation()
	{
		return enemy1.getRotation();
	}

	sf::Vector2f getPosition()
	{
		return enemy1.getPosition();
	}
	
private:
	sf::RectangleShape enemy1;
	sf::Texture* enemy_texture1;
	float actionDelatMax1 = 1.0f;
	float actionDelay1 = actionDelatMax1;
	float moveDuration1 = 1.0f;
	float speed = 300.0f;
	bool shoot;
	int hp2 = 2;
	int action;
	int point;
	int type;
	void variable();

};
