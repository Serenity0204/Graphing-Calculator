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
#include "includes/engine/engine.h"
#include "includes/config/config.h"
#include "includes/input_box/input_box.h"
#include "includes/sidebar/sidebar.h"
using namespace std;


// int main()
// {
//     Engine engine;
//     engine.run();
// }


// int main()
// {
    
//     sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Test!");

//     Config config;
//     // sf::RenderWindow window(sf::VideoMode(200, 200), "There's a cat!");
//     // sf::CircleShape shape(100.f);
//     // shape.setFillColor(sf::Color::Green);
//     // sf::Texture texture;
//     // if(texture.loadFromFile("../assets/cat1.png")) cout << "load success" << endl;
    
//     // sf::Sprite sprite;
//     // sprite.setTexture(texture, true);

//     // sf::Font font;
//     // font.loadFromFile("../assets/arial.ttf");
//     // sf::Text text;
//     // // select the font
//     // text.setFont(font); // font is a sf::Font
//     // // set the string to display
//     // text.setString("Hello world");
//     // // set the character size
//     // text.setCharacterSize(24); // in pixels, not points!
//     // // set the color
//     // text.setFillColor(sf::Color::Red);
//     // // set the text style
//     // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
//     sf::VertexArray function(sf::Points, 100);
//     function.clear();


//     string func = "1/cos(x^2)";

    
    
//     Tokenizer tk(func);
//     Queue<Token*>infix = tk.infix();
//     cout << infix;
    
//     if(infix.empty()) 
//     {
//         cout << "empty queue error" << endl;
//         return -1;
//     }


//     ShuntingYard sy(infix);
//     Queue<Token*> postfix = sy.postfix();
//     if(sy.is_error())
//     {
//         cout << "error in shunting yard!";
//         return -1;
//     }
//     //cout << postfix << endl;
//     RPN rpn(postfix);

//     for(float x = -50; x < 50; x+=0.01)
//     {   

//         float y = rpn.rpn(x);
//         if(rpn.is_error())
//         {
//             cout << "Error in rpn! " << endl;
//             return -1;
//         }
//         //if(fabs(cos(x)) <= 0.3) continue;
//         if(fabs(y) >= 5) continue;
//         //cout << "tan of " << x << " is " << X << endl;
//         //cout << X << endl;
//         sf::Vertex point(sf::Vector2f(x*100.f + window.getSize().x/2, -1.f*y*200.f + window.getSize().y / 2));
//         point.color = sf::Color::White;
//         function.append(point);
//     }

//     sf::Sprite s(config.get_texture(BACK_GROUND));
//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear(sf::Color::Black);
//         window.draw(s);
        
//         window.draw(function);
//         //window.draw(text);
//         //window.draw(sprite);
//         //window.draw(shape);
//         window.display();
//     }

//     return 0;
// }







// testing 


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Test!");
    window.setKeyRepeatEnabled(true);
    Sidebar sb(850,250);
    Textbox textbox1(15, sf::Color::Red, false);
    sf::Font arial;
    arial.loadFromFile("../assets/arial.ttf");

    textbox1.setFont(arial);
    textbox1.setPosition({500, 500});
    sf::VertexArray function(sf::LinesStrip, 100);

    Config config;
    sf::Sprite s(config.get_texture(ERROR_IMAGE));
    s.setPosition({300, 300});


    bool error = false;
    bool test = false;
    while (window.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            textbox1.setSelected(true);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            textbox1.setSelected(false);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::TextEntered)
            {
                textbox1.typedOn(event);
                cout << textbox1.getText() << endl;
            }
            if(test && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                test = false;
                error = false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !test)
            {
                test = true;

                
                function.clear();


                string func = "";
                func += textbox1.getText();

                
                
                Tokenizer tk(func);
                Queue<Token*>infix = tk.infix();
                //cout << infix;
                
                if(infix.empty()) 
                {
                    cout << "empty queue error" << endl;
                    error = true;
                    break;;
                }

                if(error) break;
                ShuntingYard sy(infix);
                Queue<Token*> postfix = sy.postfix();
                if(sy.is_error())
                {
                    cout << "error in shunting yard!";
                    error = true;
                    continue;
                }
                //cout << postfix << endl;
                RPN rpn(postfix);
                if(error) break;
                for(float x = -100; x < 100; x+=0.001)
                {   

                    float y = rpn.rpn(x);
                    if(rpn.is_error())
                    {
                        cout << "Error in rpn! " << endl;
                        error = true;
                        break;
                    }
                    //if(fabs(cos(x)) <= 0.3) continue;
                    //if(fabs(y) >= 5) continue;
                    //cout << "tan of " << x << " is " << X << endl;
                    //cout << X << endl;
                    sf::Vertex point(sf::Vector2f(x*20.f + window.getSize().x/2, -1.f*y*50.f + window.getSize().y / 2));
                    point.color = sf::Color::White;
                    function.append(point);
                }






            }
        }

        window.clear();
        sb.draw(window);
        if(!error) window.draw(function);
        else window.draw(s);
        textbox1.drawTo(window);
        window.display();
    }

    return 0;
}