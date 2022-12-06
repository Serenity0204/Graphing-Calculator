#ifndef ENGINE_H
#define ENGINE_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
#include "../input_box/input_box.h"
#include "../plot/plot.h"
#include "../tokenizer/tokenizer/tokenizer.h"
using namespace std;


class Engine 
{
private:
    // sfml
    sf::RenderWindow _window;
    sf::Sprite _error_image;
    sf::VertexArray _points;
    sf::RectangleShape _y_axis;
    sf::RectangleShape _x_axis;

    Config _config;
    InputBox _input_box;
    bool _error;
    bool _need_reset;

    void _update_equation();
    void _update_input_box();
public:
    Engine();
    ~Engine();
    void input();
    void run();
    void display();
};




#endif