#ifndef ENGINE_H
#define ENGINE_H
#include "../config/config.h"
#include "../history_bar/history_bar.h"
#include "../input_box/input_box.h"
#include "../lru/lru.h"
#include "../plot/plot.h"
#include "../tokenizer/tokenizer.h"
#include <SFML/Graphics.hpp>
#include <string>
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
    HistoryBar _history_bar;
    LRU<string, sf::VertexArray> _lru;

    string _current_function;
    bool _error;
    bool _need_reset;
    float _zoom_factor;
    float _low_bound;
    float _up_bound;

    void _zoom_helper();
    void _update_cache(int index);
    void _update_equation();
    void _update_input_box();
    void _update_history_box();
    void _clear_infix(Queue<Token*>& infix)
    {
        if (infix.empty()) return;
        typename Queue<Token*>::Iterator it;
        for (it = infix.begin(); it != infix.end(); ++it) delete (*it);
        cout << "cleared" << endl;
    }

public:
    Engine();
    ~Engine();
    void input();
    void run();
    void display();
};

#endif