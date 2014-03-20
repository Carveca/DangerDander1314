//Player header file

#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attackSprite, SoundManager* soundmanager, sf::Sprite* deathAnimation, sf::Sprite* blueeffectanimation, sf::Sprite* happyeffectanimation);
	~Player();
	
	void Initialize();
	void Cleanup();	
	void Update(float &angle, sf::Vector2f &direction, float &deltatime);
	void HandleCollision();
	void Attack();
	void WeaponStick();
	void ChangeHP(int value);

	void SetDrainTutorial();
	void SetDrainNormal();

	int GetWeaponSize();
	
	float GetAttackTimer();

	bool GetAttacking();
	bool GetAttackAnimation();

	sf::Sprite* GetSprite();
	sf::Sprite* GetAttackSprite();
	sf::Sprite* GetBlueSprite();
	sf::Sprite* GetHappySprite();

	void SetAttackAnimationStop();
	
	void AddScore(int value);
	int GetScore();
	void UseHappyPill();
	void UseBlueCow();
	float GetBlueCowTimer();
	float GetHappyPillTimer();

public:
	int m_happyPills;
	int m_blueCows;

private:
	FileReader reader;

	SoundManager* m_soundManager;

	float m_moveSoundTimer;
	float m_attackTimer;
	float m_drainTimer;

	int m_weaponSize;
	float m_hpDrain;
	
	bool m_isAttacking;
	bool m_attackAnimation;
	
	sf::Sprite* m_attackSprite;
	float m_attackFrameCounter;
	int m_attackImageNR;

	sf::Sprite* m_deathSprite;
	float m_deathFrameCounter;
	int m_deathImageNR;

	sf::Sprite* m_blueEffectSprite;
	float m_blueFrameCounter;
	int m_blueImageNR;

	sf::Sprite* m_happyEffectSprite;
	float m_happyFrameCounter;
	int m_happyImageNR;
		
	int m_score;
	float m_blueCowTimer;
	float m_happyPillTimer;

	float m_drainFactor;
};