#include "engine.h"


Engine::Engine()
{
    this->_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Graphing Calculator");
    this->_window.setKeyRepeatEnabled(true);
    this->_config = Config();
    this->_input_box = InputBox(INPUT_BOX_FONT_SIZE, INPUT_BOX_SIZE, INPUT_BOX_POS, sf::Color::Red, sf::Color::White, false);
    this->_error = false;
    this->_need_reset = false;
    this->_error_image = sf::Sprite(this->_config.get_texture(ERROR_IMAGE));
    this->_error_image.setPosition(ERROR_IMAGE_POS);
}

Engine::~Engine(){}

void Engine::_update_input_box()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        //cout << "User selecting input box" << endl;
        this-> _input_box.setSelected(true);
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        //cout << "User quit inputing" << endl;
        this->_input_box.setSelected(false);
        return;
    }
}



void Engine::input()
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            cout << "User Quit" << endl;
            this->_window.close();
        }
        if (event.type == sf::Event::TextEntered)
        {
            this->_input_box.typedOn(event);
            //cout << this->_input_box.getText()<< endl;
        }
        if(!this->_need_reset && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cout << "User graphing" << endl;
            this->_update_equation();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cout << "User reset error state" << endl;
            this->_points.clear();
            this->_need_reset = false;
            this->_error = false;
        }
    }
}




void Engine::_update_equation()
{
    string func = "";
    func += this->_input_box.getText();
    Tokenizer tk(func);
    Queue<Token*>infix = tk.infix();

    if(infix.empty()) 
    {
        cout << "Tokenize error" << endl;
        this->_error = true;
        this->_need_reset = true;
        return;
    }

    Plot plot(infix);
    sf::VertexArray points = plot(-100, 100, 100, this->_error);
    this->_need_reset = this->_error;
    this->_points = points;
}








void Engine::display()
{
    this->_input_box.drawTo(this->_window);  
    if(!this->_error)
    {
        this->_window.draw(this->_points);
        return;
    }
    this->_window.draw(this->_error_image);
}

void Engine::run()
{
    sf::Font arial = this->_config.get_font(ARIAL);
    this->_input_box.setFont(arial);
    this->_input_box.setLimit(true, CHAR_LIMIT);

    while (this->_window.isOpen())
    {

        this->_update_input_box();
        this->input();
        this->_window.clear();

        this->display();
        this->_window.display();
    }

}