#ifndef ENGINE_H
#define ENGINE_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
#include "../tokenizer/tokenizer/tokenizer.h"
#include "../lib/shunting_yard/shunting_yard.h"
#include "../lib/rpn/rpn.h"
using namespace std;


class Engine 
{
private:
    sf::RenderWindow _window;
    sf::VertexArray vtx;
public:
    Engine()
    {
        this->_window.create(sf::VideoMode(1000, 1000), "Graphing Calculator");
    }
    ~Engine(){}
    void run(){}
        
};




#endif