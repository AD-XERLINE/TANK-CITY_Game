# TANK-CITY_Game
my project game

  #pragma once
  #define _CRT_SECURE_NO_WARNINGS
  #include <SFML\Graphics.hpp>
  #include <string>
  #include <sstream>
  #include <stdio.h>
  #include <utility>
  #include <algorithm>
  #include <vector>
  #include <iostream>

  #pragma warning(disable:4996)
  using namespace std;
  std::stringstream ss;


  class MENU
  {
      private:
          sf::RenderWindow *window;
          sf::Font font;
          //sf::Font font2;
          sf::Text playText;
          sf::Text Tank_City;
          sf::Text TextOVER;
          sf::Text BACK2M;
          sf::Text ShScore;
          sf::Text Ok;
          sf::Text Me;
          sf::Text BACKL;
          int Shscore;
          sf::Texture backgound;
          sf::Text SC;

          /*char temp[255];
          int score[6];
          string name[6];
          vector <pair<int, string>> userScore;
          FILE* fp;
          int SCOORE;*/

          int scene = 0;
      public:
          MENU(sf::RenderWindow* window)
          {
              this->window = window;
              font.loadFromFile("Font/vinet.ttf");
              //font2.loadFromFile("Font/sOv_kLoRnG.ttf");
              playText.setFont(font);
              playText.setCharacterSize(32);
              playText.setString("PLAY");
              playText.setOrigin( sf::Vector2f(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2) );
              playText.setPosition( sf::Vector2f(500.f,450.f) );
              playText.setFillColor(sf::Color(204, 102, 0));
              //
              SC.setFont(font);
              SC.setCharacterSize(32);
              SC.setString("LEADER BOARD");
              SC.setOrigin(sf::Vector2f(SC.getLocalBounds().width / 2, SC.getLocalBounds().height / 2));
              SC.setPosition(sf::Vector2f(500.f, 650.f));
              SC.setFillColor(sf::Color(204, 102, 0));
              //
              Me.setFont(font);
              Me.setCharacterSize(18);
              Me.setString("64010444 NEERACHA LOWMATJIT");
              Me.setOrigin(sf::Vector2f(Me.getLocalBounds().width / 2, Me.getLocalBounds().height / 2));
              Me.setPosition(sf::Vector2f(500.f, 850.f));
              Me.setFillColor(sf::Color(255, 255, 255));
              //
              Tank_City.setFont(font);
              Tank_City.setCharacterSize(50);
              Tank_City.setString("TANK CITY");
              Tank_City.setOrigin(sf::Vector2f(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2));
              Tank_City.setPosition(sf::Vector2f(350.f, 250.f));
              Tank_City.setFillColor(sf::Color(128, 128, 128));
              //
              TextOVER.setFont(font);
              TextOVER.setCharacterSize(100);
              TextOVER.setString("GAME OVER");
              TextOVER.setOrigin(sf::Vector2f(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2));
              TextOVER.setPosition(sf::Vector2f(290.f, 250.f));
              TextOVER.setFillColor(sf::Color(128, 128, 128));
              //
              BACK2M.setFont(font);
              BACK2M.setCharacterSize(42);
              BACK2M.setString("BACK TO MENU");
              BACK2M.setOrigin(sf::Vector2f(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2));
              BACK2M.setPosition(sf::Vector2f(500.f, 650.f));
              BACK2M.setFillColor(sf::Color(51, 51, 255));
              //
              BACKL.setFont(font);
              BACKL.setCharacterSize(32);
              BACKL.setString("BACK TO MENU");
              BACKL.setOrigin(sf::Vector2f(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2));
              BACKL.setPosition(sf::Vector2f(150.f, 850.f));
              BACKL.setFillColor(sf::Color(51, 51, 255));

              ShScore.setFont(font);
              ShScore.setCharacterSize(32);
              //ss >> SCOORE;
              //ss << "SCORE: " << SCOORE;
              ShScore.setOrigin(sf::Vector2f(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2));
              ShScore.setPosition(sf::Vector2f(400.f, 550.f));
              ShScore.setFillColor(sf::Color(255, 255, 255));
              this->ShScore.setString(ss.str());

              sf::RectangleShape BG(sf::Vector2f(1000.0f, 1000.0f));
              BG.setFillColor(sf::Color::White);
              sf::Texture bg_menu;
              bg_menu.loadFromFile("bg_menu-01.png");
              BG.setTexture(&bg_menu);
              BG.setPosition(sf::Vector2f(0.0f, 0.0f));

              font.loadFromFile("Font/vinet.ttf");
              Ok.setFont(this->font);
              Ok.setCharacterSize(20);
              Ok.setFillColor(sf::Color::White);
              Ok.setOrigin(sf::Vector2f(Ok.getLocalBounds().width / 2, Ok.getLocalBounds().height / 2));
              Ok.setPosition(425.f, 600.f);
              Ok.setLetterSpacing(1.5f);
              //this->playerLabel.setString(this->playerName);
              Ok.setString("Let's GO!!");
          }
          //Ok
          void updateSC()
          {
              if (BACKL.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
              {
                  BACKL.setFillColor(sf::Color(0, 128, 255));
                  BACKL.setScale(sf::Vector2f(1.1f, 1.1f));
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                  {
                      scene = 0;
                  }
              }
              else
              {
                  BACKL.setScale(sf::Vector2f(1.0f, 1.0f));
                  BACKL.setFillColor(sf::Color(51, 51, 255));

              }
          }
          void renderSC()
          {
              window->draw(BACKL);
          }

          void updateLogin() {
              if (Ok.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
              {
                  Ok.setFillColor(sf::Color(255, 255, 0));
                  Ok.setScale(sf::Vector2f(1.1f, 1.1f));
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                  {
                      scene = 1;
                  }
              }
              else
              {
                  Ok.setScale(sf::Vector2f(1.0f, 1.0f));
                  Ok.setFillColor(sf::Color(204, 102, 0));
              }
          }
          void BcL()
          {
              sf::Texture backgroundL;
              backgroundL.loadFromFile("items/walllogin-01.png");
              sf::Sprite backgroundLo;
              backgroundLo.setTexture(backgroundL);
              backgroundLo.setScale(1.0f, 1.0f);
              window->draw(backgroundLo);
          }
          void randerLogin()
          {
              window->draw(Ok);
          }
          void bcM()
          {
              window->clear();
              sf::Texture background;
              background.loadFromFile("items/wallmenu-01.png");
              sf::Sprite backgroundM;
              backgroundM.setTexture(background);
              backgroundM.setScale(1.0f, 1.0f);
              window->draw(backgroundM);
          }
          void updateMenu()
          {

              if (playText.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
              {
                  playText.setFillColor(sf::Color(255, 255, 0));
                  playText.setScale(sf::Vector2f(1.1f, 1.1f));
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                  {
                      scene = 3;
                  }
              }
              else if (SC.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
              {
                  SC.setFillColor(sf::Color(255, 255, 0));
                  SC.setScale(sf::Vector2f(1.1f, 1.1f));
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                  {
                      scene = 4;
                  }
              }
              else
              {
                  playText.setScale(sf::Vector2f(1.0f, 1.0f));
                  playText.setFillColor(sf::Color(204, 102, 0));
                  SC.setScale(sf::Vector2f(1.0f, 1.0f));
                  SC.setFillColor(sf::Color(204, 102, 0));
              }
          }
          void renderMenu()
          {
              window->clear();
              sf::Texture background;
              background.loadFromFile("items/wallmenu-01.png");
              sf::Sprite backgroundM;
              backgroundM.setTexture(background);
              backgroundM.setScale(1.0f, 1.0f);
              window->draw(backgroundM);
              window->draw(Me);
              window->draw(SC);
              window->draw(playText);
              window->draw(Tank_City);
              window->display();
          }

          void updateGameOver()
          {
              if (BACK2M.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
              {
                  BACK2M.setFillColor(sf::Color(0, 128, 255));
                  BACK2M.setScale(sf::Vector2f(1.1f, 1.1f));
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                  {
                      scene = 0;
                  }
              }
              else
              {
                  BACK2M.setScale(sf::Vector2f(1.0f, 1.0f));
                  BACK2M.setFillColor(sf::Color(51, 51, 255));
              }

          }
          void renderGameOver()
          {
              window->clear();
              window->draw(TextOVER);
              //window->draw(ShScore);
              window->draw(BACK2M);
              window->display();
          }

          int getScene()
          {
              return scene;
          }
          int GetScore()
          {
              //return SCOORE;
          }
          void setScene(int scene)
          {
              this->scene = scene;
          }
  };

