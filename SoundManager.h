//SoundManager.h 

#pragma once
#include <map>


class SoundManager
{
public:

	SoundManager();
	~SoundManager();

	bool Initialize(const sf::String directory);
	void Cleanup();
	void LoadSound(std::string file_name, std::string sound_name);
	void PlaySound(std::string name);

private:
	std::string m_pathname;

	std::map<std::string, sf::Sound> m_sounds;
	std::map<std::string, sf::SoundBuffer> m_buffer; 
};