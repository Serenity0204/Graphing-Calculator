#include "config.h"



Config::Config()
{

}

Config::~Config()
{
    delete[] this->_textures;
}


sf::Texture* Config::_get_texture(int index)
{
    sf::Texture* walker = this->_textures;
    for(int i = 0; i < this->_texture_num; ++i)
    {
        if(i == index) return walker;
        walker++;
    }
    return nullptr;
}


sf::Texture Config::get_texture(int index)
{
    sf::Texture* texture = this->_get_texture(index);
    assert(texture != nullptr && "Getting non existed texture");
    return *texture;
}

void Config::_set_texture()
{
    this->_textures = new sf::Texture[NUM_TEXTURE];
    
}