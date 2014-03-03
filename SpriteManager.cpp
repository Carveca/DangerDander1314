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

void SpriteManager::LoadSprite(std::string &filename, int &width, int &height)
{
	sf::Sprite* sprite = new sf::Sprite;
	
	auto it = m_textures.find(filename);

	if(it == m_textures.end())	
	{
		LoadTexture(filename, width, height);
	}

	sprite->setTexture(*m_textures[filename]);
	m_sprites.insert( std::pair <std::string, sf::Sprite*>(filename, sprite ) );
}


void SpriteManager::LoadTexture(std::string filename, int width, int height)
{
	sf::Texture* texture = new sf::Texture;

	texture->loadFromFile(m_filepath + filename, sf::IntRect(0, 0, width, height));

	m_textures.insert( std::pair <std::string, sf::Texture*>(filename, texture ) );
}

sf::Sprite* SpriteManager::GetSprite(std::string filename, int width, int height)
{
	auto it = m_sprites.find(filename);

	if(it == m_sprites.end())	
	{
		LoadSprite(filename, width, height);
	}
	
	return m_sprites[filename];
}


/*
	bool exists = false;	

	for(std::map<std::string, sf::Sprite*>::iterator Iterator = m_sprites.begin(); Iterator != m_sprites.end(); ++Iterator)
	{
		if (Iterator->first == filename)
		{
			exists = true;
		}
	}

	if( !exists ) 
	{
		LoadSprite(filename, width, height);
	}
	*/
	
/*
	bool exists = false;

	for(std::map<std::string, sf::Texture*>::iterator Iterator = m_textures.begin(); Iterator != m_textures.end(); ++Iterator)
	{
		if (Iterator->first == filename)
		{
			exists = true;
		}
	}

	if( !exists ) 
	{
		LoadTexture(filename, width, height);		
	}
	*/