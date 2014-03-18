//HUD.cpp

#include "stdafx.h"
#include "HUD.h"
#include "SpriteManager.h"
#include "Player.h"
#include <string>

HUD::HUD(SpriteManager* spritemanager)
{
	m_spritemanager = spritemanager;

	m_pumpmeter = m_spritemanager->GetSprite("bottom_pumpmeter.png", 1250, 180);
	m_indicator = m_spritemanager->GetSprite("new_indicator.png", 50, 66);
	m_indicatoreffect = m_spritemanager->GetSprite("indicator_glow.png", 100, 100);
	m_warningleft = m_spritemanager->GetSprite("alert_left.png", 170, 180);
	m_warningright = m_spritemanager->GetSprite("alert_right.png", 170, 180);
	m_bluecow = m_spritemanager->GetSprite("blue_icon.png", 43, 64);
	m_happypill = m_spritemanager->GetSprite("happy_icon.png", 43, 64);
	m_powerupframe = m_spritemanager->GetSprite("powerup_hud.png", 270, 210);
	m_scoresprite = m_spritemanager->GetSprite("test_score.png", 314, 230);

	m_font.loadFromFile("../Sprites/testfont.ttf");

	m_pumpmeterPOS = sf::Vector2f(335, 900);
	m_startPOS = sf::Vector2f(m_pumpmeterPOS + sf::Vector2f(151, 60) + sf::Vector2f(-35, 0));
	m_indicatoreffect->setPosition(m_startPOS + sf::Vector2f(-40, -28));
	m_scorePOS = sf::Vector2f(1620, 850);
	m_powerupframePOS = sf::Vector2f(50, 850);

	m_scoretext = new sf::Text;
	m_scoretext->setPosition(700, 50);
	m_scoretext->setCharacterSize(60);
	m_scoretext->setFont(m_font);
	m_scoretext->setColor(sf::Color::Cyan);
	m_scoretext->setStyle(sf::Text::Regular);

	m_happypilltext = new sf::Text;
	m_happypilltext->setPosition(100,20);
	m_happypilltext->setCharacterSize(60);
	m_happypilltext->setFont(m_font);
	m_happypilltext->setColor(sf::Color::Magenta);
	m_happypilltext->setStyle(sf::Text::Regular);

	m_bluecowtext = new sf::Text;
	m_bluecowtext->setPosition(160,20);
	m_bluecowtext->setCharacterSize(60);
	m_bluecowtext->setFont(m_font);
	m_bluecowtext->setColor(sf::Color::Blue);
	m_bluecowtext->setStyle(sf::Text::Regular);

	m_pumpmeter->setPosition(m_pumpmeterPOS);
	m_warningleft->setPosition(m_pumpmeterPOS);
	m_warningright->setPosition(m_pumpmeterPOS + sf::Vector2f(1080 ,0) );
	m_scoresprite->setPosition(m_scorePOS);
	m_powerupframe->setPosition(m_powerupframePOS);
	m_happypill->setPosition(m_powerupframePOS + sf::Vector2f(50, 95));
	m_bluecow->setPosition(m_powerupframePOS + sf::Vector2f(176, 95));
}

HUD::~HUD()
{
	delete m_scoretext;
	m_scoretext = nullptr;

	delete m_happypilltext;
	m_happypilltext = nullptr;

	delete m_bluecowtext;
	m_bluecowtext = nullptr;
}

void HUD::Update(Player* player)
{
	m_indicator->setPosition(m_startPOS + sf::Vector2f(10 * player->GetHP(), 35));

	m_indicatoreffect->setPosition(m_indicator->getPosition() + sf::Vector2f(-22, -16));
	
	m_scoretext->setString(std::to_string(player->GetScore()));
	m_happypilltext->setString(std::to_string(player->m_happyPills));
	m_bluecowtext->setString(std::to_string(player->m_blueCows));
}

sf::Sprite* HUD::GetPumpmeter()
{
	return m_pumpmeter;
}

sf::Sprite* HUD::GetPowerupframe()
{
	return m_powerupframe;
}

sf::Sprite* HUD::GetScoreSprite()
{
	return m_scoresprite;
}

sf::Sprite* HUD::GetIndicator()
{
	return m_indicator;
}

sf::Sprite* HUD::GetIndicatorEffect()
{
	return m_indicatoreffect;
}

sf::Sprite* HUD::GetWarningLeft()
{
	return m_warningleft;
}

sf::Sprite* HUD::GetWarningRight()
{
	return m_warningright;
}

sf::Sprite* HUD::GetHappyPill()
{
	return m_happypill;
}

sf::Sprite* HUD::GetBlueCow()
{
	return m_bluecow;
}

sf::Text* HUD::GetScoreText()
{
	return m_scoretext;
}

sf::Text* HUD::GetHappyPillText()
{
	return m_happypilltext;
}

sf::Text* HUD::GetBlueCowText()
{
	return m_bluecowtext;
}