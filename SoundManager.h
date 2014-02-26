//SoundManager.h 

#pragma once
#include <map>


class SoundManager
{
public:

	SoundManager();
	~SoundManager();

	bool Initialize(const sf::String directory);
	void LoadSound(std::string file_name, std::string sound_name);
	void PlaySound(std::string name);

private:
	std::string m_pathname;

	sf::Sound m_sound;
	std::map<std::string, sf::SoundBuffer> m_buffer; 
};