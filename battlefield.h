#pragma once
#include "character.h"
#include <fstream>

// Number of the enemies, current project will create 3 enemies instead of using this variable.
#define NUM_ENEMY 3

// Maximum HP and MP for heros and enemies.
#define THOR_MAX_HP 100
#define HULK_MAX_HP 150
#define IRONMAN_MAX_HP 120
#define THOR_MAX_MP 50
#define HULK_MAX_MP 20
#define IRONMAN_MAX_MP 30

// Amount of MP that hero and enemy can recover.
#define HERO_MP_RECOVERY 5
#define ENEMY_MP_RECOVERY 3

#define FILENAME "Record.txt"

class BattleGround {
public:

	// For storing hero object.
	Character* m_hero;

	// For storing enemy object.
	Character* m_enemy_1;
	Character* m_enemy_2;
	Character* m_enemy_3;

	// For counting rounds.
	int m_round_counter;

	// Storing objects.
	vector <Character*> m_elements;

public:
	// Exit the game.
	void Exit();

	// Hall menu.
	void ShowMenu();

	// Show HP and MP each round.
	void ShowBattleInfo();

	// Create your seleted hero.
	void CreateHero(int choice);

	// Automatically create enemies.
	void CreateEnemy();

	// Gameing loop.
	void StartFight();

	// Enemies fight back each round.
	void EnemyFightBack();

	// Check the end of the game.
	void CheckIsAlive();

	// Recover character's MP each round.
	void RecoverCharactersMP();

	// Save records.
	void Save();

	// Deconstructor of the BattleGround.
	~BattleGround();
};

