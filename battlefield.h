#pragma once
#include "character.h"


class BattleGround {
public:
	Character* m_hero;

	Character* m_enemy_1;
	Character* m_enemy_2;
	Character* m_enemy_3;

public:
	void Exit();

	void ShowMenu();

	void CreateHero(int choice);

	void CreateEnemy();

	void StartFight();

	void CheckIsAlive();
};

