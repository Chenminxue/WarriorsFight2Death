#pragma once
#include "character.h"


class BattleGround {
public:
	Character* m_hero;

	Character* m_enemy_1;
	Character* m_enemy_2;
	Character* m_enemy_3;

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
};

