#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "includes/tokenizer/tokenizer/tokenizer.h"
#include "includes/lib/rpn/rpn.h"
#include "includes/lib/shunting_yard/shunting_yard.h"
#include "includes/lib/queue/MyQueue.h"
#include "includes/lib/token/function.h"
#include "includes/lib/token/constants.h"
#include "includes/lib/token/operator.h"
#include "includes/lib/token/integer.h"
// #include "includes/engine/engine.h"
#include "includes/config/config.h"
using namespace std;


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Test!");

    Config config;
    // sf::RenderWindow window(sf::VideoMode(200, 200), "There's a cat!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    // sf::Texture texture;
    // if(texture.loadFromFile("../assets/cat1.png")) cout << "load success" << endl;
    
    // sf::Sprite sprite;
    // sprite.setTexture(texture, true);

    // sf::Font font;
    // font.loadFromFile("../assets/arial.ttf");
    // sf::Text text;
    // // select the font
    // text.setFont(font); // font is a sf::Font
    // // set the string to display
    // text.setString("Hello world");
    // // set the character size
    // text.setCharacterSize(24); // in pixels, not points!
    // // set the color
    // text.setFillColor(sf::Color::Red);
    // // set the text style
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::VertexArray function(sf::LineStrip, 100);
    function.clear();


    string func = "x";

    
    
    Tokenizer tk(func);
    Queue<Token*>infix = tk.infix();
    cout << infix;
    
    if(infix.empty()) 
    {
        cout << "empty queue error" << endl;
        return -1;
    }


    ShuntingYard sy(infix);
    Queue<Token*> postfix = sy.postfix();
    if(sy.is_error())
    {
        cout << "error in shunting yard!";
        return -1;
    }
    //cout << postfix << endl;
    RPN rpn(postfix);

    for(float x = -50; x < 50; x+=0.01)
    {   

        float y = rpn.rpn(x);
        if(rpn.is_error())
        {
            cout << "Error in rpn! " << endl;
            return -1;
        }
        if(fabs(cos(x)) <= 0.3) continue;
        //cout << "tan of " << x << " is " << X << endl;
        //cout << X << endl;
        sf::Vertex point(sf::Vector2f(x*20.f + window.getSize().x/2, -1.f*y*20.f + window.getSize().y / 2));
        point.color = sf::Color::White;
        function.append(point);
    }

    sf::Sprite s(config.get_texture(BACK_GROUND));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        //window.draw(s);
        
        // window.draw(function);
        //window.draw(text);
        //window.draw(sprite);
        //window.draw(shape);
        window.display();
    }

    return 0;
}