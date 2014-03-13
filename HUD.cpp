//HUD.cpp

#include "stdafx.h"
#include "HUD.h"
#include "SpriteManager.h"
#include "Player.h"

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


	m_pumpmeterPOS = sf::Vector2f(335, 900);
	m_startPOS = sf::Vector2f(m_pumpmeterPOS + sf::Vector2f(151, 60) + sf::Vector2f(-35, 0));
	m_indicatoreffect->setPosition(m_startPOS + sf::Vector2f(-40, -28));
	m_scorePOS = sf::Vector2f(1620, 850);
	m_powerupframePOS = sf::Vector2f(50, 850);

	m_score = 0;

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

}

void HUD::Update(Player* player)
{
	m_indicator->setPosition(m_startPOS + sf::Vector2f(10 * player->GetHP(), 35));

	m_indicatoreffect->setPosition(m_indicator->getPosition() + sf::Vector2f(-22, -16));
	
	m_score = player->GetScore();
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