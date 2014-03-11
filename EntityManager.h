//Entity Manager header file

#pragma once

class CollisionManager;
class MusicManager;
class SoundManager;

class Player;
class PlayerAttack;
class PumpMeter;

class EnemyAOE;
class MeleeAttack;
class EnemyMelee;
class Bullet;
class EnemyRanged;
class RubbishBin;
class Rubbishpile;
class HappyPill;
class BlueCow;

class EntityManager
{
public:
	EntityManager(sf::Sprite* playerSprite, sf::Vector2f playerlPOS, sf::Sprite* playerAttackSprite, sf::Sprite* playerdeathsprite, sf::Sprite* powSprite, SoundManager* soundmanager, MusicManager* musicmanager);
	~EntityManager();

	void Update(float &angle, sf::Vector2f &direction, float &deltatime);	
	void Draw(sf::RenderWindow* window, float &deltatime, float &playerangle );

	void AddMusic(MusicManager* musicmanager);
	void MusicSwitch();
	void AddSounds(SoundManager* soundmanager);
	void AddPumpMeter(sf::Sprite* pumpSprite, sf::Sprite* indicatorSprite, sf::Sprite* indicatorEffectSprite, sf::Sprite* leftWarningSprite, sf::Sprite* rightWarningSprite, sf::Vector2f &pumpMeterPOS);
	
	void AddMeleeAttack(MeleeAttack* meleeattack);
	void AddEnemyMelee(EnemyMelee* enemymelee);
	void AddBullet(Bullet* bullet);
	void AddEnemyRanged(EnemyRanged* enemyranged);
	void AddEnemyAOE(EnemyAOE* enemyAOE);
	void AddRubbishBin(RubbishBin* rubbishbin);
	void AddRubbishpile(Rubbishpile* rubbishpile);
	void AddBlueCow(BlueCow* bluecow);
	void AddHappyPill(HappyPill* happypill);

private:
	void UpdatePlayer(float &angle, sf::Vector2f &direction,float &deltatime);
	void DrawPlayer(sf::RenderWindow* window);

	void CollisionCheck();
	void CheckHP(float &deltatime, float &angle);	

	void UpdatePumpMeter(int hpvalue);
	void DrawPumpMeter(sf::RenderWindow* window);

	void UpdateEnemyAOE(float &deltatime);
	void DrawEnemyAOE(sf::RenderWindow* window);

	void UpdateMeleeAttack(float &deltatime);
	void DrawMeleeAttack(sf::RenderWindow* window);

	void UpdateEnemyMelee(float &deltatime);
	void DrawEnemyMelee(sf::RenderWindow* window);

	void UpdateBullet(float &deltatime);
	void DrawBullet(sf::RenderWindow* window);

	void UpdateEnemyRanged(float &deltatime);
	void DrawEnemyranged(sf::RenderWindow* window);

	void UpdateRubbishBin(float &deltatime);
	void DrawRubbishBin(sf::RenderWindow* window, float &deltatime, float &playerangle);

	void UpdateRubbishPile(float &deltatime);
	void DrawRubbishPile(sf::RenderWindow* window);

	void UpdateBlueCow(float &deltatime);
	void DrawBlueCow(sf::RenderWindow* window);

	void UpdateHappyPill(float &deltatime);
	void DrawHappyPill(sf::RenderWindow* window);

public:
	Player* m_player;
	sf::Sprite* m_powSprite;

	std::vector<RubbishBin*> m_rubbishBin;
	std::vector<EnemyRanged*> m_enemyRanged;
	std::vector<EnemyMelee*> m_enemyMelee;

private:
	CollisionManager* m_collisionManager;
	MusicManager* m_musicManager;
	SoundManager* m_soundManager;

	PumpMeter* m_pumpMeter;

	std::vector<PlayerAttack*> m_playerAttack;
	std::vector<EnemyAOE*> m_enemyAOE;
	
	std::vector<Bullet*> m_bullets;
	
	std::vector<MeleeAttack*> m_meleeAttacks;
	
	std::vector<Rubbishpile*> m_rubbishpile;
	std::vector<BlueCow*> m_blueCow;
	std::vector<HappyPill*> m_happyPill;

	int m_musicNR;
	int m_musicNRprevious;

	bool m_musicSwitch;

};