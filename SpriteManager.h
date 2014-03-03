//SpriteManager header file

#pragma once
#include "stdafx.h"
#include <map>

class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	bool Initialize(const sf::String &directory);

	void LoadTexture(std::string fileName, int width, int height);
	void LoadSprite(std::string &filename, int &width, int &height);
		
	sf::Sprite* GetSprite(std::string filename, int width, int height);

protected:
	std::string m_filepath;

	std::map<std::string, sf::Texture*> m_textures;
	std::map<std::string, sf::Sprite*> m_sprites; 	
};