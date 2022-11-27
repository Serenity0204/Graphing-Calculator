#include "config.h"



Config::Config()
{
    this->_set_texture();
}

Config::~Config(){}


std::shared_ptr<sf::Texture> Config::_get_texture(int key)
{
    if(this->_texture_map.find(key) != this->_texture_map.end()) 
    {
        return this->_texture_map[key];
    }
    return nullptr;
}


sf::Texture& Config::get_texture(int index)
{
    std::shared_ptr<sf::Texture> texture = this->_get_texture(index);
    assert(texture != nullptr && "Getting non existed texture");
    return *texture;
}


void Config::_set_texture()
{
    auto texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("../assets/cat1.png");
    this->_texture_map[BACK_GROUND] = texture;
}