#ifndef HISTORY_BAR_H
#define HISTORY_BAR_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../button/button.h"
#include "../config/config.h"
#include "../lib/lru/lru.h"
using namespace std;




class HistoryBar
{
public:
    HistoryBar()
    {
        this->_lru = LRU<string, sf::VertexArray>(5);
        this->_bar.setSize(HISTORY_BAR_SIZE);
        this->_bar.setPosition(HISTORY_BAR_POS);
        this->_buttons = vector<Button>();
        this->_bar.setPosition(HISTORY_BAR_POS);
        this->_bar.setSize(HISTORY_BAR_SIZE);
        this->_bar.setFillColor(sf::Color::Magenta);                                                
        for(int i = 0; i < 5; ++i)
        {
            Button btn("test", {150, 100}, 20, sf::Color::White, sf::Color::Black);
            float y = 100 + 180 * i ;
            btn.setPosition({1025, y});
            this->_buttons.push_back(btn);
        }
    }
    ~HistoryBar(){}
	
    void drawTo(sf::RenderWindow &window) {
        Config config;
        sf::Font font = config.get_font(ARIAL);
        window.draw(_bar);
        //this->set_lru_to_history();
        for(int i = 0; i < 5; ++i)
        {
            Button btn = this->_buttons[i];
            btn.setFont(font);
            btn.drawTo(window);
        }		
        
	}
    void isOver(sf::RenderWindow& window)
    {
        for(int i = 0; i < 5; ++i)
        {
            if(this->_buttons[i].isMouseOver(window))
            {
                this->_buttons[i].setBackColor(sf::Color::Yellow);
                return;
            }
            this->_buttons[i].setBackColor(sf::Color::White);
        }
    }
    LRU<string, sf::VertexArray>& get_cache(){return this->_lru;}
    void isClicked(sf::Event& input, sf::RenderWindow& window)
    {
        for(int i = 0; i < 5; ++i)
        {
            if(input.type == sf::Event::MouseButtonPressed && this->_buttons[i].isMouseOver(window))
            {
                cout << "YES " << i<< endl;
            }
        }
    }   
private:    
    void set_lru_to_history()
    {
        for(int i = 0; i < this->_buttons.size(); ++i)
        {
            this->_buttons[i].setText(this->_lru[i]);
        }
    }
    LRU<string, sf::VertexArray> _lru;
    sf::RectangleShape _bar;
    vector<Button> _buttons;
};


#endif // !HISTORY_BAR_H