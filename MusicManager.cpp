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

bool MusicManager::LoadMusic(std::string m_path)
{
	if(!m_music.openFromFile(m_path))
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

void MusicManager::VolumeControl(int m_volume)
{
	m_music.setVolume(m_volume);
}