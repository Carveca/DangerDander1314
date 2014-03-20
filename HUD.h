//HUD.h

#pragma once

class Player;
class SpriteManager;

class HUD 
{
public:
	HUD(SpriteManager* spritemanager);
	~HUD();
	 
	void Update(Player* player, float &deltatime); 

	sf::Sprite* GetPumpmeter();
	sf::Sprite* GetPowerupframe();
	sf::Sprite* GetScoreSprite();
	sf::Sprite* GetIndicator();
	sf::Sprite* GetIndicatorEffect();
	sf::Sprite* GetWarningLeft();
	sf::Sprite* GetWarningRight();
	sf::Sprite* GetHappyPill();
	sf::Sprite* GetBlueCow();
	sf::Sprite* GetBlueArrow();
	sf::Sprite* GetRedArrow();

	sf::Text* GetScoreText();
	sf::Text* GetHappyPillText();
	sf::Text* GetBlueCowText();

	float GetBlueArrowTimer();
	float GetRedArrowTimer();
	
protected:
	SpriteManager* m_spritemanager;

	sf::Sprite* m_pumpmeter;
	sf::Sprite* m_indicator;
	sf::Sprite* m_indicatoreffect; 
	sf::Sprite* m_warningleft; 
	sf::Sprite* m_warningright;
	sf::Sprite* m_scoresprite; 
	sf::Sprite* m_happypill; 
	sf::Sprite* m_bluecow; 
	sf::Sprite* m_powerupframe;
	sf::Sprite* m_blueArrow;
	sf::Sprite* m_redArrow;

	sf::Vector2f m_pumpmeterPOS;
	sf::Vector2f m_startPOS;
	sf::Vector2f m_scorePOS;
	sf::Vector2f m_powerupframePOS;
	
	sf::Font m_font;
	sf::Text* m_scoretext;
	sf::Text* m_bluecowtext;
	sf::Text* m_happypilltext;

	float m_redArrowTimer;
	float m_blueArrowTimer;
};