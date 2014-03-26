//OptionsState.cpp

#include "stdafx.h"
#include "OptionsState.h"
#include "SpriteManager.h"
#include "MusicManager.h"
#include "FileWriter.h"

OptionsState::OptionsState()
{
	m_done = false;
}

bool OptionsState::Enter(SpriteManager* spritemanager, MusicManager* musicmanager)
{
	m_writer = new FileWriter;
	m_writer->Initialize("../Data/");

	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("SoundSettings.txt");

	m_musicVolume = m_reader->m_settings["MusicVolume"];
	m_soundVolume = m_reader->m_settings["SoundVolume"];

	m_done = false;
	m_selection = 1;
	m_keytimer = 0.0f;

	m_spriteManager = spritemanager;
	m_background = m_spriteManager->GetSprite("menuscreen.png", 1920, 1080);

	m_musicManager = musicmanager;

	m_musicManager->LoadMusic("screen_music.wav");
	m_musicManager->RepeatON();
	m_musicManager->Play();

	return true;
}

void OptionsState::Exit()
{
	m_writer->AddData("MusicVolume" , m_musicVolume);
	m_writer->AddData("SoundVolume" , m_soundVolume);
	m_writer->WriteToFile("SoundSettings.txt");

	delete m_reader;
	m_reader = nullptr;

	delete m_writer;
	m_writer = nullptr;
}

bool OptionsState::Update(float &deltatime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_keytimer <= 0.0)
	{
		if(m_selection != 3)
		{
			m_selection++;
			m_keytimer = 0.2;
		}
		else
		{
			m_selection = 1;
			m_keytimer = 0.2;
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_keytimer <= 0.0)
	{
		if(m_selection != 1)
		{
			m_selection--;
			m_keytimer = 0.2;
		}
		else
		{
			m_selection = 3;
			m_keytimer = 0.2;
		}
	}

	if(m_selection == 1)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_keytimer <= 0.0)
		{
			if(m_musicVolume < 100)
			{
				m_musicVolume++;
			}
			m_keytimer = 0.2f;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_keytimer <= 0.0)
		{
			if(m_musicVolume > 0)
			{
				m_musicVolume--;
			}
			m_keytimer = 0.2f;
		}
	}

	else if(m_selection == 2)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_keytimer <= 0.0)
		{
			if(m_soundVolume < 100)
			{
				m_soundVolume++;
			}
			m_keytimer = 0.2f;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_keytimer <= 0.0)
		{
			if(m_soundVolume > 0)
			{
				m_soundVolume--;
			}
			m_keytimer = 0.2f;
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if(m_selection == 3)
		{
			m_nextState = "MenuStateII";
			m_done = true;
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_nextState = "MenuStateII";
		m_done = true;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_nextState = "quit";
		m_done = true;
	}

	m_keytimer -= deltatime;
	if(m_keytimer < -10)
	{
		m_keytimer = 0.0f;
	}

	
	return m_done;
}

void OptionsState::Draw(sf::RenderWindow* window)
{
	window->draw(*m_background);
}

std::string OptionsState::Next()
{
	return m_nextState;
}

bool OptionsState::IsType(const std::string &type)
{
	return type.compare("OptionsState") == 0;
}

void OptionsState::Draw(sf::RenderWindow* window, float &deltatime)
{

}