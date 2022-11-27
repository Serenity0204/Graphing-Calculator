#ifndef CONFIG_H
#define CONFIG_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;


enum TEXTURES
{
    BACK_GROUND = 0,
};





class Config
{
private:
    std::unordered_map<int, std::shared_ptr<sf::Texture>> _texture_map;
    std::shared_ptr<sf::Texture> _get_texture(int key);
    void _set_texture();
public:
    Config();
    ~Config();
    sf::Texture& get_texture(int index);
};



#endif