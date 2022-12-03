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
    void run()
    {
        Config config;
        sf::Sprite s(config.get_texture(BACK_GROUND));
        this->test();
        while (this->_window.isOpen())
        {
            this->input();
            this->_window.clear(sf::Color::Black);
            this->update(s);
            this->_window.display();
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
        this->_window.draw(this->vtx);
    }



    void test()
    {
        sf::VertexArray function(sf::LineStrip, 500);
        function.clear();


        string func = "x + 4";



        Tokenizer tk(func);
        Queue<Token*>infix = tk.infix();

        if(infix.empty()) 
        {
            cout << "empty queue error" << endl;
            return;
        }


        ShuntingYard sy(infix);
        Queue<Token*> postfix = sy.postfix();
        if(sy.is_error())
        {
            cout << "error in shunting yard!";
            return;
        }
        //cout << postfix << endl;
        RPN rpn(postfix);

        for(float x = -100; x < 100; x+=0.01)
        {   

            float y = rpn.rpn(x);
            if(rpn.is_error())
            {
                cout << "Error in rpn! " << endl;
                return;
            }
            //if(fabs(cos(x)) <= 0.3) continue;
            //if(fabs(y) >= 5) continue;
            //cout << "tan of " << x << " is " << X << endl;
            //cout << X << endl;
            sf::Vertex point(sf::Vector2f(x*50.f + this->_window.getSize().x/2, -1.f*y*70.f + this->_window.getSize().y / 2));
            point.color = sf::Color::White;
            function.append(point);
        }
        this->vtx = function;
    }
};




#endif