#include "plot.h"


Plot::Plot(Queue<Token*> infix)
{
    this->_infix = infix;
}

Plot::~Plot()
{
    this->_infix.clear();
}

sf::VertexArray Plot::operator()(float low, float up, int points, bool& error)
{
    sf::VertexArray function(sf::Points, points);
    function.clear();
    ShuntingYard sy(this->_infix);
    Queue<Token*> postfix = sy.postfix();
    if(sy.is_error())
    {
        cout << "error in shunting yard!";
        error = true;
        return function;
    }
    RPN rpn(postfix);
    for(float x = -100; x < 100; x+=0.0005)
    {   

        float y = rpn.rpn(x);
        if(rpn.is_error())
        {
            cout << "Error in rpn! " << endl;
            error = true;
            function.clear();
            return function;
        }
        //if(fabs(cos(x)) <= 0.3) continue;
        //if(fabs(y) >= 5) continue;
        //cout << "tan of " << x << " is " << X << endl;
        //cout << X << endl;
        
        sf::Vertex point(sf::Vector2f(x*20.f + WINDOW_WIDTH/2, -1.f*y*50.f + WINDOW_HEIGHT / 2));
        point.color = sf::Color::White;
        if(point.position.x >= 995 || point.position.y > 900 || point.position.y < 100) continue;
        function.append(point);
    }


    return function;
}
