# TANK-CITY_Game
my project game

#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpmax;
}

void Player::initvarible()
{
	this->hpmax = 5;
	this-> hp = this-> hpmax;
}

void Player::initGUI()
{

}
void Player::updateGUI()
{
	//init playerGUI
	this->playerhpbar.setSize(sf::Vector2f(300.0f, 25.0f));
	this->playerhpbar.setFillColor(sf::Color::Red);
	this->playerhpbar.setPosition(sf::Vector2f(20.f,20.f));


	this->playerhpbarback = playerhpbar;
	this->playerhpbarback.setFillColor(sf::Color(25, 25, 25, 200));
}
void Player::randerGUI()
{
	/*this->window->draw(playerhpbarback);
	this->window->draw(playerhpbar);*/
}
