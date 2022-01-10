#pragma once
#include <string>
#include <vector>
#include <iostream>

// Base attack value.
#define BASE_REGULAR_ATTACK 5
#define WEAKEN_REGULAR_ATTACK_MAX 3
#define WEAKEN_REGULAR_ATTACK_MIN 1

// Base spell attack value.
#define BASE_SPELL_ATTACK 10
#define WEAKEN_SPELL_ATTACK_MAX 4
#define WEAKEN_SPELL_ATTACK_MIN 2

// Block attack percentage.
#define BLOCK_PERCNETAGE 0.8

using namespace std;

class Character {
	/* This is the interface for characters. */
public:

	// Regular attack interface.
	virtual void m_RegulerAttack(Character* enemy) = 0;

	// Spell attack interface.
	virtual void m_SpellAttack(Character* enemy) = 0;

	// Block interface.
	virtual void m_Block(vector <Character*> element) = 0;

public:
	// Name of the character.
	string m_name;

	// HP of the character.
	int m_HP;

	// MP of the character.
	int m_MP;

	// Block option used or not.
	bool m_IsBlockActivated;
};



class Hero : public Character {
public:
	// Initialization of the hero.
	Hero(string name, int HP, int MP);

	// Destory the hero.
	~Hero();

	// Hero's regular attack, triggered by the player.
	void m_RegulerAttack(Character* enemy);

	// Spell attack, triggered by the player every round and deplete MP value.
	void m_SpellAttack(Character* enemy);

	// Block the attack from the enemies, triggered by the player every round.
	void m_Block(vector <Character*> element);
};



class Enemy : public Character {
public:
	// Initialization of the enemy.
	Enemy(string name, int HP, int MP);

	// Destroy the enemy.
	~Enemy();

	// Enemy's regular attack, automatically triggered by the system.
	void m_RegulerAttack(Character* enemy);

	// Spell attack, triggered by the system every round and deplete MP value.
	void m_SpellAttack(Character* enemy);

	// Block the attack from the enemies, triggered by the system every round.
	void m_Block(vector <Character*> element);

public:
	// Block option used or not.
	bool m_IsBlockActivated;
};

