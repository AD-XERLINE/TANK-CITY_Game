# TANK-CITY_Game
my project game

#include "Map.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>

void Map::generate(sf::RenderWindow& window)
{
    std::vector <sf::Vector2f> map;
    sf::RectangleShape block(sf::Vector2f(50.0f, 50.0f));
    block.setFillColor(sf::Color::White);
    sf::Texture Wall;
    Wall.loadFromFile("items/wall-01.png");
    block.setTexture(&Wall);
    sf::RectangleShape green(sf::Vector2f(50.0f, 50.0f));
    sf::Texture Gr;
    Gr.loadFromFile("items/GREEN-01.png");
    green.setTexture(&Gr);
    std::ifstream openfile("Tmap.txt");
    if (openfile.is_open())
    {
        std::string line;
        int lineCount = 0;
        while (std::getline(openfile, line))
        {

            for (int column = 0; column < line.length(); column++)
            {
                if (line[column] == '1')
                {
                    sf::Vector2f blockPos = { 50.0f * (column),50.0f * (lineCount) };
                    map.push_back(blockPos);
                }
            }
            lineCount++;
        }
    }
    tilemap = map;
    for (int i = 0; i < map.size(); i++)
    {
        block.setPosition(map[i].x, map[i].y);
        window.draw(block);
        
    }
}
bool Map::checkWall(float x, float y)
{
    for (int i = 0; i < tilemap.size(); i++)
    {
        if ((tilemap[i].x < x + 50.0) && (tilemap[i].x + 100.0 > x) && (tilemap[i].y < y + 50.0) && (tilemap[i].y + 100.0 > y))
        {
            return true;
        }

    }
    return false;
}

void Map::createGreen(sf::RenderWindow& window)
{
    std::vector <sf::Vector2f> hide;
    sf::RectangleShape block(sf::Vector2f(50.0f, 50.0f));
    block.setFillColor(sf::Color::White);
    sf::Texture Wall;
    //Wall.loadFromFile("items/wall-01.png");
    block.setTexture(&Wall);
    sf::RectangleShape green(sf::Vector2f(50.0f, 50.0f));
    sf::Texture Gr;
    Gr.loadFromFile("items/GREEN-01.png");
    green.setTexture(&Gr);
    std::ifstream openfile("Tmap.txt");
    if (openfile.is_open())
    {
        std::string line;
        int lineCount = 0;
        while (std::getline(openfile, line))
        {
            for (int column = 0; column < line.length(); column++)
            {
                if (line[column] == '2')
                {
                    sf::Vector2f greenPos = { 50.0f * (column),50.0f * (lineCount) };
                    hide.push_back(greenPos);
                }
            }
            lineCount++;
        }
    }
    for (int i = 0; i < hide.size(); i++)
    {
        green.setPosition(hide[i].x, hide[i].y);
        window.draw(green);
    }
}
