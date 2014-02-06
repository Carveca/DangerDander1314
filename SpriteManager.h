//SpriteManager header file

#pragma once
#include "stdafx.h"
#include <map>

class SpriteManager
{
public:
	SpriteManager();

	bool Initialize(const sf::String &directory);
	void LoadSprite( std::string file_name, std::string sprite_name, int x, int y, int width, int height, float scale_X, float scale_Y);
	
	std::map<std::string, sf::Sprite> m_sprites; // remember to move th to protected and make a method for calling on it
	std::map<std::string, sf::Texture> m_textures;

protected:
	std::string m_filepath;

};