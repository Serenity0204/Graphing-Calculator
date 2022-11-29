#ifndef ENGINE_H
#define ENGINE_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
using namespace std;


class Engine 
{
private:
    sf::RenderWindow _window;
public:
    Engine()
    {
        this->_window.create(sf::VideoMode(1000, 1000), "Graphing Calculator");
    }
    ~Engine(){}
    void run()
    {
        Config config;
        sf::Sprite s(config.get_texture(BACK_GROUND));
        while (this->_window.isOpen())
        {
            this->input();
            this->_window.clear(sf::Color::Black);
            this->update(s);
            this->render();
        }
    }

    void input()
    {
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) this->_window.close();
        }
    }

    void update(sf::Sprite s)
    {
        this->_window.draw(s);
    }
    void render()
    {
        this->_window.display();
    }

};




#endif