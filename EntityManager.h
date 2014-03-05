//Entity Manager header file

#pragma once

class CollisionManager;
class MusicManager;
class SoundManager;

class Player;
class PlayerAttack;
class PumpMeter;

class EnemyAOE;

class EntityManager
{
public:
	EntityManager(sf::Sprite* playerSprite, sf::Vector2f playerlPOS, sf::Sprite* playerAttackSprite, sf::Sprite* playerdeathsprite, sf::Sprite* powSprite, SoundManager* soundmanager, MusicManager* musicmanager);
	~EntityManager();

	void Update(float &angle, sf::Vector2f &direction, float &deltatime);	
	void Draw(sf::RenderWindow* window);

	void AddMusic(MusicManager* musicmanager);
	void MusicSwitch();
	void AddSounds(SoundManager* soundmanager);
	void AddPumpMeter(sf::Sprite* pumpSprite, sf::Sprite* indicatorSprite, sf::Sprite* indicatorEffectSprite, sf::Sprite* leftWarningSprite, sf::Sprite* rightWarningSprite, sf::Vector2f &pumpMeterPOS);
	
	void AddEnemyAOE(EnemyAOE* enemyAOE);

private:
	void UpdatePlayer(float &angle, sf::Vector2f &direction,float &deltatime);
	void DrawPlayer(sf::RenderWindow* window);

	void CollisionCheck();
	void CheckHP();	//might be redundant

	void UpdatePumpMeter(int hpvalue);
	void DrawPumpMeter(sf::RenderWindow* window);

	void UpdateEnemyAOE(float &deltatime);
	void DrawEnemyAOE(sf::RenderWindow* window);

public:
	Player* m_player;
	sf::Sprite* m_powSprite;

private:
	CollisionManager* m_collisionManager;
	MusicManager* m_musicManager;
	SoundManager* m_soundManager;

	PumpMeter* m_pumpMeter;

	std::vector<PlayerAttack*> m_playerAttack;
	std::vector<EnemyAOE*> m_enemyAOE;	

	int m_musicNR;
	int m_musicNRprevious;

	bool m_musicSwitch;

};