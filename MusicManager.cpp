//MusicManager.cpp

#include "stdafx.h"
#include "MusicManager.h"
#include <iostream>

MusicManager::MusicManager()
{
	m_music.setLoop(true);
}

MusicManager::~MusicManager()
{

}

void MusicManager::Initialize(const std::string &directory)
{
	m_directory = directory;
}

bool MusicManager::LoadMusic(std::string filename)
{
	if(!m_music.openFromFile(m_directory + filename))
	{
		std::cout<<"Error: could not load music file"<<std::endl;
	}
		
	return true; 
}

void MusicManager::Play()
{
	m_music.play();
}

void MusicManager::Pause()
{
	m_music.pause();
}

void MusicManager::Stop()
{
	m_music.stop();
}

void MusicManager::VolumeControl(int &m_volume)
{
	m_music.setVolume(m_volume);
}