#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Test!");
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
    sf::VertexArray function(sf::LinesStrip, 100);
    function.clear();
    for(float x = -30; x < 30; x+=0.25)
    {
        function.append(sf::Vertex(sf::Vector2f(x*20.f + window.getSize().x/2, -1.f*sin(pow(x, 2))*20.f + window.getSize().y / 2)));
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(function);
        //window.draw(text);
        //window.draw(sprite);
        //window.draw(shape);
        window.display();
    }

    return 0;
}