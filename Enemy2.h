# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Map.h"

class Enemy2
{
public:
	Enemy2(sf::Vector2f size, sf::Vector2f newPos, sf::Texture* texture)
	{
		enemy2.setSize(size);
		this->enemy_texture2 = texture;
		enemy2.setTexture(this->enemy_texture2);
		enemy2.setOrigin(sf::Vector2f(enemy2.getLocalBounds().width / 2, enemy2.getLocalBounds().height / 2));
		enemy2.setPosition(newPos);
		shoot = 0;
	}
	Map pam;
	sf::FloatRect getGlobalBounds()
	{
		return this->enemy2.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(enemy2);
	}
	void update(sf::RenderWindow& window, float deltaTime)
	{
		if (actionDelay2 >= actionDelatMax2)
		{
			action = rand() % 6;
			actionDelay2 = 0;
			moveDuration2 = 1.0f;
		}

		if (moveDuration2 > 0)
		{
			switch (action)
			{
			case 0://Up
				if (enemy2.getPosition().y - speed * deltaTime >= 25)
				{
					if (!pam.checkWall(enemy2.getPosition().x, enemy2.getPosition().y - speed * deltaTime))
					{
						enemy2.setRotation(0);
						enemy2.move(sf::Vector2f(0, -speed * deltaTime));
					}
				}
				break;
			case 1: //Down
				if (enemy2.getPosition().y + speed * deltaTime <= 975)
				{
					if (!pam.checkWall(enemy2.getPosition().x, enemy2.getPosition().y + speed * deltaTime))
					{
						enemy2.setRotation(180);
						enemy2.move(sf::Vector2f(0, speed * deltaTime));
					}
				}
				break;
			case 2: //Right
				if (enemy2.getPosition().x + speed * deltaTime <= 975)
				{
					if (!pam.checkWall(enemy2.getPosition().x + speed * deltaTime, enemy2.getPosition().y ))
					{
						enemy2.setRotation(90);
						enemy2.move(sf::Vector2f(speed * deltaTime, 0));
					}
				}
				break;
			case 3: //Left
				if (enemy2.getPosition().x - speed * deltaTime >= 25)
				{
					if (!pam.checkWall(enemy2.getPosition().x - speed * deltaTime, enemy2.getPosition().y))
					{
						enemy2.setRotation(270);
						enemy2.move(sf::Vector2f(-speed * deltaTime, 0));
					}
				}
				break;
			case 4: //shoot
				shoot = 1;
				moveDuration2 = 0.f;
				break;
			case 5:
				shoot = 1;
				moveDuration2 = 0.f;
			}
			moveDuration2 -= deltaTime;
		}
		else
			actionDelay2 += deltaTime;
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
		return enemy2.getRotation();
	}

	sf::Vector2f getPosition()
	{
		return enemy2.getPosition();
	}

private:
	int action;
	sf::RectangleShape enemy2;
	sf::Texture* enemy_texture2;
	bool shoot;
	float actionDelatMax2 = 1.0f;
	float actionDelay2 = actionDelatMax2;
	float moveDuration2 = 1.0f;
	float speed = 300.0f;

};
