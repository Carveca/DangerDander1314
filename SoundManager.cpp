//SoundManager.cpp

#include "stdafx.h"
#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
	m_buffer.clear();
}

bool SoundManager::Initialize(const sf::String directory)
{
	m_pathname = directory;

	return true;
}

void SoundManager::LoadSound(std::string file_name, std::string sound_name)
{
	std::string buffername = sound_name + "Buffer";
	sf::SoundBuffer buffer;

	if(!buffer.loadFromFile( m_pathname + file_name))
	{
		std::cout<<"Error, could not load sound file"<<std::endl;
	}
	
	m_buffer.insert(std::pair <std::string, sf::SoundBuffer>(buffername, buffer));

}

void SoundManager::PlaySound(std::string name)
{
	m_sound.setBuffer(m_buffer[name]);
	m_sound.play();
}