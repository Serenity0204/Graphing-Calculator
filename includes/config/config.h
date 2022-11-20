#ifndef CONFIG_H
#define CONFIG_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;


enum TEXTURES
{
    BACK_GROUND = 0,
};

const int NUM_TEXTURE = 1;




class Config
{
private:
    sf::Texture* _textures;
    int _texture_num;
    sf::Texture* _get_texture(int index);
    void _set_texture();
public:
    Config();
    ~Config();
    sf::Texture get_texture(int index);
};



#endif