# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Map.h"


class Enemy {
public:
    
	Enemy(sf::Vector2f size,sf::Vector2f newPos,sf::Texture *texture)
	{
		enemy.setSize(size);
		this->enemy_texture = texture;
		enemy.setTexture(this->enemy_texture);
		enemy.setOrigin(sf::Vector2f(enemy.getLocalBounds().width / 2, enemy.getLocalBounds().height / 2));
		enemy.setPosition(newPos);
		shoot = 0;
	}
	Map pam;

	sf::FloatRect getGlobalBounds()
	{
		return this->enemy.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(enemy);
	}

	void update(sf::RenderWindow& window,float deltaTime)
	{
		if(actionDelay >= actionDelatMax)
		{
			action = rand() % 5;
			actionDelay = 0;
			moveDuration = 1.0f;
		}

		if(moveDuration > 0)
		{
			switch(action)
			{
				case 1://Up
					if (enemy.getPosition().y - speed * deltaTime >= 25)
					{
						if (!pam.checkWall(enemy.getPosition().x , enemy.getPosition().y - speed * deltaTime))
						{
							enemy.setRotation(0);
							enemy.move(sf::Vector2f(0, -speed * deltaTime));
						}
					}
					break;
				case 0: //Down
					if(enemy.getPosition().y + speed * deltaTime <= 975)
					{
						if (!pam.checkWall(enemy.getPosition().x, enemy.getPosition().y + speed * deltaTime))
						{
							enemy.setRotation(180);
							enemy.move(sf::Vector2f(0, speed * deltaTime));
						}
					}
					break;
				case 2: //Right
					if(enemy.getPosition().x + speed * deltaTime <= 975)
					{
						if (!pam.checkWall(enemy.getPosition().x + speed * deltaTime, enemy.getPosition().y))
						{
							enemy.setRotation(90);
							enemy.move(sf::Vector2f(speed * deltaTime, 0));
					    }
					}
					break;
				case 3: //Left
					if(enemy.getPosition().x - speed * deltaTime >= 25)
					{
						if (!pam.checkWall(enemy.getPosition().x - speed * deltaTime, enemy.getPosition().y))
						{
							enemy.setRotation(270);
							enemy.move(sf::Vector2f(-speed * deltaTime, 0));
						}
					}
					break;
				case 4: //shoot
					shoot = 1;
					moveDuration = 0.f;
					break;
			}
			moveDuration -= deltaTime;
		}
		else
			actionDelay += deltaTime;
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
		return enemy.getRotation();
	}

	sf::Vector2f getPosition()
	{
		return enemy.getPosition();
	}

private:
	float actionDelatMax = 1.0f;
	float actionDelay = actionDelatMax;
	float moveDuration = 1.0f;
	float speed = 300.0f;
	bool shoot;
	int action;
	sf::RectangleShape enemy;
	sf::Texture* enemy_texture;
	int type;
	bool Firing_enemy = false;
};
