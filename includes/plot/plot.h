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
public:
    Plot(){}
    Plot(Queue<Token*> infix);
    sf::VertexArray operator()(float low, float up, int points, bool& error);
    ~Plot();
};







#endif