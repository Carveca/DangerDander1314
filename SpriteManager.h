//SpriteManager header file

#pragma once

namespace sf
{
	class Sprite;
	class Texture;
	class string;
}

#include <map>

class SpriteManager
{
public:
	SpriteManager(std::string path_name);

	void LoadSprite( std::string file_name, std::string sprite_name, int x, int y, int width, int height, float scale_X, float scale_Y);
	
protected:
	std::string m_filepath;

	//std::map<std::string, sf::Texture*> m_textures; //what did I need this for?
	std::map<std::string, sf::Sprite*> m_sprites;

};