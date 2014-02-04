//SpriteManager source file

#include "SpriteManager.h"
#include <iostream>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
//#include <SFML/System/String.hpp>

SpriteManager::SpriteManager(std::string path_name)
{
	m_filepath = path_name;
}

void SpriteManager::LoadSprite( std::string file_name, std::string sprite_name, int x, int y, int width, int height, float scale_X, float scale_Y)
{
	std::string name = sprite_name;
	sf::Texture texture;
	sf::Sprite* sprite;
	sprite = nullptr;

	if( !texture.loadFromFile( m_filepath + file_name, sf::IntRect(x, y, width, height) ) )
	{
		std::cout << "Error, could not load image file" << std::endl;
	}

	sprite->setTexture(texture);
	sprite->setScale(scale_X, scale_Y);

	m_sprites[name] = sprite;
}