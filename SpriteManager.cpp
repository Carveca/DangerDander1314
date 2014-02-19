//SpriteManager source file
#include "stdafx.h"
#include "SpriteManager.h"
#include <iostream>

SpriteManager::SpriteManager()
{
	
}

SpriteManager::~SpriteManager()
{
	m_textures.clear();
	m_sprites.clear();

}

bool SpriteManager::Initialize(const sf::String &directory)
{
	m_filepath = directory;

	return true;
}


void SpriteManager::LoadSprite( std::string file_name, std::string sprite_name, int x, int y, int width, int height, float scale_X, float scale_Y)
{
	std::string name = sprite_name;
	std::string textureName = sprite_name + "Texture";
	sf::Texture texture;
	sf::Sprite sprite;	

	if( !texture.loadFromFile( m_filepath + file_name, sf::IntRect(x, y, width, height) ) )
	{
		std::cout << "Error, could not load image file" << std::endl;
	}

	sprite.setScale(scale_X, scale_Y);

	m_textures.insert ( std::pair <std::string, sf::Texture>(textureName, texture));
	m_sprites.insert ( std::pair <std::string, sf::Sprite>(name, sprite));

}

std::map<std::string, sf::Sprite> SpriteManager::GetSprites()
{
	return m_sprites;
}

std::map<std::string, sf::Texture> SpriteManager::GetTextures()
{
	return m_textures;
}