//SoundManager.cpp

#include "stdafx.h"
#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

bool SoundManager::Initialize(const sf::String directory)
{
	m_pathname = directory;

	return true;
}

void SoundManager::Cleanup()
{
	m_buffer.clear();
}

void SoundManager::LoadSound(std::string file_name, std::string sound_name)
{
	std::string name = sound_name;
	std::string buffername = sound_name + "Buffer";
	sf::SoundBuffer buffer;
	sf::Sound sound;

	if(!buffer.loadFromFile( m_pathname + file_name))
	{
		std::cout<<"Error, could not load sound file"<<std::endl;
	}

	m_buffer.insert(std::pair <std::string, sf::SoundBuffer>(buffername, buffer));
	m_sounds.insert(std::pair <std::string, sf::Sound>(name, sound));
}

void SoundManager::PlaySound(std::string name)
{
	m_sounds[name].setBuffer(m_buffer[name + "Buffer"]);
	m_sounds[name].setVolume(m_volume);
	m_sounds[name].play();
}

void SoundManager::VolumeControl(float volume)
{
	m_volume = volume;
}