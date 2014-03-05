//MusicManager.h

#pragma once

#include <string>

class MusicManager
{
public:
	MusicManager();
	~MusicManager();

	void Initialize(const std::string &directory);
	void Play();
	void Pause();
	void Stop();
	void VolumeControl(int &m_volume);
	bool LoadMusic(std::string filename);

	sf::Time Offset();
	void PlayWithOffset();

private:	
	std::string m_directory;
	sf::Music m_music;

	sf::Time m_musicOffset;
};