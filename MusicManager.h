//MusicManager.h

#pragma once

#include <string>

class MusicManager
{
public:
	MusicManager();
	~MusicManager();

	void Play();
	void Pause();
	void Stop();
	void VolumeControl(int m_volume);
	bool LoadMusic(std::string m_path);

private:	
	sf::Music m_music;

};