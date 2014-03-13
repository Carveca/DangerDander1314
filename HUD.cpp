//HUD.cpp

#include "stdafx.h"
#include "HUD.h"
#include "SpriteManager.h"
#include "Player.h"

HUD::HUD(SpriteManager* spritemanager)
{
	m_spritemanager = spritemanager;

	m_pumpmeter = m_spritemanager->GetSprite("new_pumpmeter.png", 800, 246);
	m_indicator = m_spritemanager->GetSprite("pumpmeter_indicator.png", 70, 94);
	m_indicatoreffect = m_spritemanager->GetSprite("indicator_effect.png", 150, 150);
	m_warningleft = m_spritemanager->GetSprite("meter_effect_left.png", 800, 246);
	m_warningright = m_spritemanager->GetSprite("meter_effect_right.png", 800, 246);
	/*m_bluecow = m_spritemanager->GetSprite("");
	m_happypill = m_spritemanager->GetSprite("");
	m_powerupframe = m_spritemanager->GetSprite("");
	m_scoresprite = m_spritemanager->GetSprite("");*/


	m_pumpmeterPOS = sf::Vector2f(0, 0);
	m_startPOS = sf::Vector2f(m_pumpmeterPOS + sf::Vector2f(151, 60) + sf::Vector2f(-35, 0));
	m_indicatoreffect->setPosition(m_startPOS + sf::Vector2f(-40, -28));
	m_scorePOS = sf::Vector2f(1800, 10);
	m_powerupframePOS = sf::Vector2f(20, 1000);

	m_score = 0;

	m_pumpmeter->setPosition(m_pumpmeterPOS);
	m_warningleft->setPosition(m_pumpmeterPOS);
	m_warningright->setPosition(m_pumpmeterPOS);
	m_scoresprite->setPosition(m_scorePOS);
	m_powerupframe->setPosition(m_powerupframePOS);
}

HUD::~HUD()
{

}

void HUD::Update(Player* player)
{
	m_indicator->setPosition(m_startPOS + sf::Vector2f( 5 * player->GetHP(), 0));

	m_indicatoreffect->setPosition(m_indicator->getPosition() + sf::Vector2f(-40, -28));
	
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