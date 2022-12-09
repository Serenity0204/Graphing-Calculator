#ifndef PLOT_H
#define PLOT_H
#include <bits/stdc++.h>
#include "../lib/shunting_yard/shunting_yard.h"
#include "../lib/rpn/rpn.h"
#include "../config/config.h"
#include <SFML/Graphics.hpp>




class Plot
{
private:
    Queue<Token*> _infix;
    sf::Vector2f get_origin()
    {
        // knowing x, y 500, 500 is origin, want y(0) -> y(500), y(500) - > 1
        float y = this->_rpn(0);
        sf::Vector2f pos = {0, y};
        return pos;
    }
    sf::Vector2f get_actual()
    {
        float y = this->_rpn(500);
        sf::Vector2f pos = {500, y};
        return pos;
    }

public:
    RPN _rpn;
    Plot(){}
    Plot(Queue<Token*> infix);
    sf::VertexArray operator()(float low, float high, float zoom_factor, bool& error);
    ~Plot();
};





#endif