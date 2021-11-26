# TANK-CITY_Game
my project game



		#define _CRT_SECURE_NO_WARNINGS
		#include <SFML\Graphics.hpp>
		#include <iostream>
		#include <sstream>
		#include "Enemy.h"
		#include "Enemy1.h"
		#include "Enemy2.h"
		#include "Player.h"
		#include "Bullet.h"
		#include <vector>
		#include "MENU.h"
		#include "Map.h"
		#include "Items.h"
		#include "Items2.h"
		#include "King.h"
		#include <stdio.h>
		#include <utility>
		#include <algorithm>
		#include <time.h>
		#pragma warning(disable:4996)

		int SCOORE = 0;
		using namespace std;
		sf::RenderWindow window(sf::VideoMode(1300,1000), "Tank_RE", sf::Style::Close);
		MENU menu(&window);
		string Pin;
		int scene = 0; 

		char temp[255];
		int score[6];
		string name[6];
		vector <pair<int, string>> userScore;
		FILE* fp;
		void BcB ()
		{

			sf::Texture backgroundHighTexture;
			backgroundHighTexture.loadFromFile("items/Wallscore-01.png");
			sf::Sprite backgroundHigh;
			backgroundHigh.setTexture(backgroundHighTexture);
			backgroundHigh.setScale(1.0f, 1.0f);
			window.draw(backgroundHigh);
		}
		void board()
		{
			sf::Text board[5];
			sf::Text nameBoard[5];
			sf::Font font;
			font.loadFromFile("Font/vinet.ttf");

			board[0].setFont(font);
			board[0].setFillColor(sf::Color::Red);
			board[0].setPosition(700.f,220.f);
			board[1].setFont(font);
			board[1].setFillColor(sf::Color::Red);
			board[1].setPosition(700.f, 320.f);
			board[2].setFont(font);
			board[2].setFillColor(sf::Color::Red);
			board[2].setPosition(700.f, 420.f);
			board[3].setFont(font);
			board[3].setFillColor(sf::Color::Red);
			board[3].setPosition(700.f, 520.f);
			board[4].setFont(font);
			board[4].setFillColor(sf::Color::Red);
			board[4].setPosition(700.f, 620.f);

			nameBoard[0].setFont(font);
			nameBoard[0].setCharacterSize(20);
			nameBoard[0].setOutlineThickness(15);
			nameBoard[0].setFillColor(sf::Color::White);
			nameBoard[0].setPosition(250.f, 220.);
			nameBoard[1].setFont(font);
			nameBoard[1].setCharacterSize(20);
			nameBoard[0].setOutlineThickness(15);
			nameBoard[1].setFillColor(sf::Color::White);
			nameBoard[1].setPosition(250.f, 320.f);
			nameBoard[2].setFont(font);
			nameBoard[2].setCharacterSize(20);
			nameBoard[0].setOutlineThickness(15);
			nameBoard[2].setFillColor(sf::Color::White);
			nameBoard[2].setPosition(250.f, 420.f);
			nameBoard[3].setFont(font);
			nameBoard[3].setCharacterSize(20);
			nameBoard[0].setOutlineThickness(15);
			nameBoard[3].setFillColor(sf::Color::White);
			nameBoard[3].setPosition(250.f, 520.f);
			nameBoard[4].setFont(font);
			nameBoard[4].setCharacterSize(42);
			nameBoard[0].setOutlineThickness(15);
			nameBoard[4].setFillColor(sf::Color::White);
			nameBoard[4].setPosition(250.f, 620.f);

			board[0].setString(to_string(score[0]));
			board[1].setString(to_string(score[1]));
			board[2].setString(to_string(score[2]));
			board[3].setString(to_string(score[3]));
			board[4].setString(to_string(score[4]));

			nameBoard[0].setString(name[0]);
			nameBoard[1].setString(name[1]);
			nameBoard[2].setString(name[2]);
			nameBoard[3].setString(name[3]);
			nameBoard[4].setString(name[4]);

			window.draw(board[0]);
			window.draw(board[1]);
			window.draw(board[2]);
			window.draw(board[3]);
			window.draw(board[4]);

			window.draw(nameBoard[0]);
			window.draw(nameBoard[1]);
			window.draw(nameBoard[2]);
			window.draw(nameBoard[3]);
			window.draw(nameBoard[4]);
		}
		void save()
		{
			userScore.clear();
			fp = fopen("Score.txt", "r");

			for (int i = 0; i < 5; i++)
			{
				fscanf(fp, "%s", &temp);
				name[i] = temp;
				fscanf(fp, "%d", &score[i]);
				userScore.push_back(std::make_pair(score[i], name[i]));
			}
			fclose(fp);
			name[5] = Pin;
			score[5] = SCOORE;
			printf("Good");
			userScore.push_back(make_pair(score[5], name[5]));
			sort(userScore.begin(), userScore.end());

			fp = fopen("Score.txt", "w");
			for (int i = 5; i >= 0; i--)
			{
				strcpy(temp, userScore[i].second.c_str());
				fprintf(fp, "%s %d\n", temp, userScore[i].first);
			}
			fclose(fp);
		}
		void renderName()
		{
			sf::Text q;
			sf::Font font;
			sf::Text Ptx;
			font.loadFromFile("Font/vinet.ttf");
			q.setFont(font);
			q.setFillColor(sf::Color::White);
			q.setString("Enter your name: ");
			q.setCharacterSize(50);
			q.setPosition(200.f,150.f);
			q.setOutlineColor(sf::Color(204, 102, 0));
			q.setOutlineThickness(10);
			Ptx.setString(Pin);
			Ptx.setFillColor(sf::Color(255, 204, 153));
			Ptx.setCharacterSize(50);
			Ptx.setOrigin(sf::Vector2f(Ptx.getLocalBounds().width / 2, Ptx.getLocalBounds().height / 2));
			Ptx.setPosition(350.f,500.f);
			Ptx.setFont(font);
			//window.clear(sf::Color::Black);
			//window.draw(back);
			window.draw(q);
			window.draw(Ptx);
		}
		void namepollEvent()
		{
			sf::Event nev;
			while (window.pollEvent(nev))
			{
				if (nev.type == sf::Event::KeyPressed)
				{
					if (nev.key.code == sf::Keyboard::BackSpace)
					{
						if (!Pin.empty())
						{
							Pin.erase(Pin.size() - 1, 1);
						}
					}
				}
				else if (nev.type == sf::Event::TextEntered)
				{
					if (std::isprint(nev.text.unicode))
					{
						Pin += static_cast<char>(nev.text.unicode);
					}
				}

			}
		}
		int main()
		{
			sf::RectangleShape block(sf::Vector2f(100.0f, 100.0f));
			std::vector<sf::Event> textEnter;
			Map pam;
			srand(time(NULL));
			sf::Vector2f spawn[4] = { sf::Vector2f(25,25), sf::Vector2f(975,25) ,sf::Vector2f(25,975) ,sf::Vector2f(975,975) };
			sf::Vector2f genitems[10] = { sf::Vector2f(75,200), sf::Vector2f(500,500) ,sf::Vector2f(450,350) ,sf::Vector2f(500,805),sf::Vector2f(175,750),sf::Vector2f(700,500),sf::Vector2f(50,100),sf::Vector2f(600,650),sf::Vector2f(800,700),sf::Vector2f(650,100) };
			sf::Vector2f impspawn[1] = { sf::Vector2f(500,800) };
			int Number1 = 1;
			int Number2 = 1;
			int Number3 = 1;
			int Hp = 5;
			int HpK = 5;
			int E1hp = 2;
			int Time = 0;
			int TimeI = 0;
			int TimeII = 0;
			int xi;
			int yi;
			int angle;
			float deltaTime;
			float delayFiremax = 0.50f;
			float delayFire = delayFiremax;
			sf::Clock clock;
			sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
			//player.setFillColor(sf::Color::Blue);
			sf::RectangleShape enemy(sf::Vector2f(100.0f, 100.0f));
			sf::RectangleShape enemy1(sf::Vector2f(100.0f, 100.0f));
			sf::RectangleShape enemy2(sf::Vector2f(100.0f, 100.0f));
			sf::RectangleShape Items01(sf::Vector2f(25.0f, 25.0f));
			sf::RectangleShape Items02(sf::Vector2f(25.0f, 25.0f));
			sf::RectangleShape King_(sf::Vector2f(100.0f, 100.0f));
			player.setOrigin(50.0f, 50.0f);
			player.setPosition(350.0f, 900.0f);
			sf::Texture playerTexture;
			sf::Texture bullet;
			sf::Texture enemyTexture;
			sf::Texture enemyTexture1;
			sf::Texture enemyTexture2;
			sf::Texture item1;
			sf::Texture item2;
			sf::Texture _King;
			playerTexture.loadFromFile("Untitled-2-01.png");
			enemyTexture.loadFromFile("ene1.png");
			enemyTexture1.loadFromFile("ene2.png");
			enemyTexture2.loadFromFile("ene3.png");
			bullet.loadFromFile("bullet ai-01.png");
			item1.loadFromFile("items/batt-01.png");
			item2.loadFromFile("items/bomb-01.png");
			_King.loadFromFile("items/imp-01.png");
			Items01.setTexture(&item1);
			Items02.setTexture(&item2);
			King_.setTexture(&_King);
			player.setTexture(&playerTexture);
			sf::Vector2u textureSize = playerTexture.getSize();

			sf::Font font;
			font.loadFromFile("Font/vinet.ttf");
			sf::Text point;
			point.setFont(font);
			point.setCharacterSize(20);
			point.setFillColor(sf::Color::White);
			point.setPosition(1050.0f, 100.0f);
			char str[50];

			std::stringstream ss;
			ss << "Score : " << SCOORE << " ";
			point.setString(ss.str());

			sf::Text HP;
			HP.setFont(font);
			HP.setCharacterSize(20);
			HP.setFillColor(sf::Color::White);
			HP.setPosition(1050.0f, 150.0f);
			char HPr[50];

			std::stringstream hp;
			hp << "MY HP : " << Hp << " ";
			HP.setString(hp.str());

			sf::Text HPK;
			HPK.setFont(font);
			HPK.setCharacterSize(20);
			HPK.setFillColor(sf::Color::White);
			HPK.setPosition(1050.0f, 200.0f);
			//char HPK[50];

			std::stringstream hpk;
			hpk << "HP BASE : " << HpK << " ";
			HPK.setString(hpk.str());

			sf::Text Name;
			Name.setFont(font);
			Name.setCharacterSize(32);
			Name.setPosition(sf::Vector2f(400.f, 550.f));
			Name.setFillColor(sf::Color::White);
			Name.setString(Pin);

			//define object
			std::vector<Enemy> enemies;
			std::vector<Bullet> bulletvec;
			std::vector<Enemy1> enemies1;
			std::vector<Enemy2> enemies2;
			std::vector<Bullet> enemyBullets;
			std::vector<Items> itemOne;
			std::vector<Items2> itemTwu;
			std::vector<King> imp;

			bool Firing = false;
			int counter = 1;


			while (window.isOpen()) {
				deltaTime = clock.restart().asSeconds();
				sf::Event evnt;
				while (window.pollEvent(evnt)) {
					textEnter.push_back(evnt);
					switch (evnt.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::TextEntered:
						if (evnt.text.unicode < 128) {
							//printf("%c", evnt.text.unicode);
						}
					}
				}
				//MenU
				scene = menu.getScene();
				switch(scene)
				{
				case 0://Menu
					//menu.bcM();
					menu.updateMenu();
					menu.renderMenu();
					break;
				case 4://leaderboard
					window.clear();
					BcB();
					menu.updateSC();
					menu.renderSC();
					board();
					window.display();
					break;
				case 3://login
					window.clear();
					menu.BcL();
					menu.updateLogin();
					renderName();
					namepollEvent();
					menu.randerLogin();//ok
					window.display();

					break;
				case 2://Over
					menu.updateGameOver();
					menu.renderGameOver();

					break;
				case 1://Gameplay

					//Spawn Enemy max
					if (imp.size() < 1)
					{
						//Size Pos Textture
						imp.push_back(King(sf::Vector2f(100.f, 100.f), impspawn[0], &_King));
					}
					if(Time >= 10000){
						if(enemies.size() < Number1)
						{
							//Size Pos Textture
							enemies.push_back(Enemy( sf::Vector2f(100.f,100.f) , spawn[rand() % 4] , &enemyTexture));
						}
					}
					if (Time >= 25000) {
						if (enemies1.size() < Number2)
						{
							//Size Pos Textture
							enemies1.push_back(Enemy1(sf::Vector2f(100.f, 100.f), spawn[rand() % 4], &enemyTexture1));
						}
					}
					if(Time >= 40000){
						if (enemies2.size() < Number3)
						{
							//Size Pos Textture
							enemies2.push_back(Enemy2(sf::Vector2f(100.f, 100.f), spawn[rand() % 4], &enemyTexture2));
						}
					}
					//item2
					if (TimeII >= 102000) {
						if (itemTwu.size() < 1)
						{
							//Size Pos Textture
							itemTwu.push_back(Items2(sf::Vector2f(50.f, 50.f), genitems[rand() % 10], &item2));
						}
						if (TimeII >= 110000) {
							itemTwu.erase(itemTwu.begin());
							TimeII = 0;
						}
					}
					//item1
					if (TimeI >= 70000) {
						if (itemOne.size() < 1)
						{
							//Size Pos Textture
							itemOne.push_back(Items(sf::Vector2f(50.f, 50.f), genitems[rand() % 10], &item1));
						}
						if (TimeI >= 85000) {
							itemOne.erase(itemOne.begin());
							TimeI = 0;
						}
					}
					if (Time > 40100) {
						Time = 0;
						Number1++;
						Number2++;
						Number3++;
					}

					//keyboard
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
						if (player.getPosition().x >= 25)
						{
							if (!pam.checkWall(player.getPosition().x - 2.5f, player.getPosition().y))
							{
								player.move(-2.5f, 0.0f);
								player.setRotation(270);
							}
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
						if (player.getPosition().x <= 975)
						{
							if (!pam.checkWall(player.getPosition().x + 2.5f, player.getPosition().y))
							{
								player.move(2.5f, 0.0f);
								player.setRotation(90);
							}
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
						if (player.getPosition().y >= 25)
						{
							if (!pam.checkWall(player.getPosition().x, player.getPosition().y - 2.5f))
							{
								player.move(0.0f, -2.5f);
								player.setRotation(0);
							}
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
						if (player.getPosition().y <= 975)
						{
							if (!pam.checkWall(player.getPosition().x, player.getPosition().y + 2.5f))
							{
								player.move(0.0f, 2.5f);
								player.setRotation(180);
							}
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && delayFire >= delayFiremax) {
						Firing = true;
						delayFire = 0;
					}

					//mouse
					/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						sf::Vector2i mousePos = sf::Mouse::getPosition(window);
						player.setPosition((float)mousePos.x, (float)mousePos.y);
					}*/

					//Update Enemy act
					for(int i=0;i<enemies.size();i++)
					{
						enemies[i].update(window,deltaTime);
						if(enemies[i].getShoot())
						{
							Bullet newBullet(sf::Vector2f(40, 5),enemies[i].getRotation());
							newBullet.setPos(sf::Vector2f(enemies[i].getPosition().x , enemies[i].getPosition().y));
							//bulletvec.push_back(newBullet);
							enemyBullets.push_back(newBullet);
							enemies[i].stopShoot();
						}
					}
					for (int i = 0; i < enemies1.size(); i++)
					{
						enemies1[i].update(window, deltaTime);
						if(enemies1[i].getShoot())
						{
							Bullet newBullet(sf::Vector2f(40, 5),enemies1[i].getRotation());
							newBullet.setPos(sf::Vector2f(enemies1[i].getPosition().x , enemies1[i].getPosition().y));
							enemyBullets.push_back(newBullet);
							enemies1[i].stopShoot();
						}
					}
					for (int i = 0; i < enemies2.size(); i++)
					{
						enemies2[i].update(window, deltaTime);
						if(enemies2[i].getShoot())
						{
							Bullet newBullet(sf::Vector2f(40, 5),enemies2[i].getRotation());
							newBullet.setPos(sf::Vector2f(enemies2[i].getPosition().x , enemies2[i].getPosition().y));
							enemyBullets.push_back(newBullet);
							enemies2[i].stopShoot();
						}
					}

					if (Firing == true && counter != 0) {
						Bullet newBullet(sf::Vector2f(40, 5),player.getRotation());
						newBullet.setPos(sf::Vector2f(player.getPosition().x , player.getPosition().y));
						bulletvec.push_back(newBullet);
						//--counter;
						Firing = false;
					}
					//Bullet Update
					for (int i = 0; i < bulletvec.size(); i++) {

						bulletvec[i].fire(3.4f);
					}

					for (int i = 0; i < enemyBullets.size(); i++) {

						enemyBullets[i].fire(3.4f);
					}
					//check chon tan 3
					for (int i = 0; i < imp.size(); i++)
					{
						for (int jl = 0; jl < enemies2.size(); jl++)
						{
							if (imp[i].getGlobalBounds().intersects(enemies2[jl].getGlobalBounds()))
							{
								enemies2.erase(enemies2.begin() + jl);
								HpK--;
								std::stringstream hpk;
								hpk << "HP BASE : " << HpK << " ";
								HPK.setString(hpk.str());
								goto HERE;
							}
						}
					}
					//check dead
					for (int i = 0; i < bulletvec.size(); i++)
					{
						for(int j=0;j < enemies.size();j++)
						{
							if (bulletvec[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds()))
							{
								bulletvec.erase(bulletvec.begin() + i);
								enemies.erase(enemies.begin() + j);
								SCOORE += 100;
								std::stringstream ss;
								ss << "SCORE: " << SCOORE << " ";
								point.setString(ss.str());
								goto HERE;
							}
						}
						for (int jl = 0; jl < enemies1.size(); jl++)
						{
							if (bulletvec[i].getGlobalBounds().intersects(enemies1[jl].getGlobalBounds()))
							{
								bulletvec.erase(bulletvec.begin() + i);
								E1hp--;
									if (E1hp == 0)
									{
										enemies1.erase(enemies1.begin() + jl);
										SCOORE += 250;
										std::stringstream ss;
										ss << "SCORE: " << SCOORE << " ";
										point.setString(ss.str());
										E1hp = 2;

									}
								goto HERE;
							}
						}
						for (int jll = 0; jll < enemies2.size(); jll++)
						{
							if (bulletvec[i].getGlobalBounds().intersects(enemies2[jll].getGlobalBounds()))
							{
								bulletvec.erase(bulletvec.begin() + i);
								enemies2.erase(enemies2.begin() + jll);
								SCOORE += 350;
								std::stringstream ss;
								ss << "SCORE: " << SCOORE << " ";
								point.setString(ss.str());
								goto HERE;
							}
						}
						for (int jl = 0; jl < imp.size(); jl++)
						{
							if (bulletvec[i].getGlobalBounds().intersects(imp[jl].getGlobalBounds()))
							{
								bulletvec.erase(bulletvec.begin() + i);
								HpK--; 
								SCOORE -= 100;
								std::stringstream hpk;
								hpk << "HP BASE : " << HpK << " ";
								HPK.setString(hpk.str());

								std::stringstream ss;
								ss << "SCORE: " << SCOORE << " ";
								point.setString(ss.str());
								goto HERE;
							}
						}

					}
					for(int i=0;i<enemyBullets.size();i++)
					{
						if (enemyBullets[i].getGlobalBounds().intersects(player.getGlobalBounds()))
						{
								enemyBullets.erase(enemyBullets.begin() + i);
								Hp--;
								std::stringstream hp;
								hp << "HP : " << Hp << " ";
								HP.setString(hp.str());
								goto HERE;
						}
						for (int k = 0; k < imp.size(); k++)
						{
							if (enemyBullets[i].getGlobalBounds().intersects(imp[k].getGlobalBounds()))
							{
								bulletvec.erase(bulletvec.begin() + i);
								HpK--;
								std::stringstream hpk;
								hpk << "HP BASE : " << HpK << " ";
								HPK.setString(hpk.str());
								goto HERE;
							}
						}
					}
					//item1
					for (int i = 0; i < itemOne.size(); i++)
					{
						if (itemOne[i].getGlobalBounds().intersects(player.getGlobalBounds()))
						{
							itemOne.erase(itemOne.begin() + i);
							SCOORE += 50;
							TimeI = 0;
							std::stringstream ss;
							ss << "SCORE: " << SCOORE << " ";
							point.setString(ss.str());
							if (Hp < 5) {
								Hp++;
								std::stringstream hp;
								hp << "HP : " << Hp << " ";
								HP.setString(hp.str());
							}
							goto HERE;
						}
					}
					//item2
					for (int i = 0; i < itemTwu.size(); i++)
					{
						if (itemTwu[i].getGlobalBounds().intersects(player.getGlobalBounds()))
						{
							itemTwu.erase(itemTwu.begin() + i);
							SCOORE += 50;
							TimeII = 0;
							std::stringstream ss;
							ss << "SCORE: " << SCOORE << " ";
							point.setString(ss.str());
							enemies.clear();
							enemies1.clear();
							enemies2.clear();
							Number1 = 2;
							Number2 = 1;
							Number3 = 1;
							goto HERE;
						}
					}

				HERE:
					delayFire += deltaTime;

					if (Hp <= 0 || HpK <= 0) {
						menu.setScene(2);
						Hp = 5;
						HpK = 5;
						std::stringstream hpk;
						hpk << "HP BASE : " << HpK << " ";
						HPK.setString(hpk.str());
						save();
						itemOne.clear();
						enemies.clear();
						enemies1.clear(); 
						enemies2.clear();   
						bulletvec.clear();  
						enemyBullets.clear();   
						player.setPosition(350, 950);   
						SCOORE = 0;
						Time = 0;
						TimeI = 0;
						TimeII = 0;
						Number1 = 1;
						Number2 = 0;
						Number3 = 0;
						std::stringstream ss;
						ss << "SCORE: " << SCOORE << " ";
						point.setString(ss.str());
					}
					window.clear();


					//draw
					for (int i = 0; i < imp.size(); i++) {
						imp[i].draw(window);
					}
					pam.generate(window);
					window.draw(player);

					for (int i = 0; i < enemies2.size(); i++) {
						enemies2[i].draw(window);
					}
					for (int i = 0; i < enemies1.size(); i++) {
						enemies1[i].draw(window);
					}
					for (int i = 0; i < enemies.size(); i++) {
						enemies[i].draw(window);
					}  
					for(int i=0;i<bulletvec.size();i++){
						bulletvec[i].draw(window);
					}
					for(int i=0;i<enemyBullets.size();i++){
						enemyBullets[i].draw(window);
					}
					pam.createGreen(window);
					for (int i = 0; i < itemTwu.size(); i++) {
						itemTwu[i].draw(window);
					}
					for (int i = 0; i < itemOne.size(); i++) {
						itemOne[i].draw(window);
					}
					window.draw(point);
					window.draw(HP);
					window.draw(HPK);
					window.display();
					break;
				}
				//printf("%d\n",scene);
				Time += 13;
				TimeI += 10;
				TimeII += 5;
			}
			return 0;
		}
