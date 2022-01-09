#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Character {
	/* This is the interface for characters. */
public:

	// Regular attack, triggered by the player everyround.
	virtual void m_RegulerAttack(Character* enemy) = 0;

	// The character has a chance to give crital attack at each round, not triggered by the player.
	virtual void m_CritalAttack(Character* enemy) = 0;

	// Spell attack, triggered by the player every round and deplete MP value.
	virtual void m_SpellAttack(Character* enemy) = 0;

	// Block the attack from the enemies, triggered by the player every round.
	virtual void m_Block(vector <Character*> element) = 0;

public:
	// Name of the character.
	string m_name;

	// HP of the character.
	int m_HP;

	// MP of the character.
	int m_MP;
};



class Hero : public Character {
public:
	Hero(string name, int HP, int MP);

	~Hero();

	void m_RegulerAttack(Character* enemy);

	// The character has a chance to give crital attack at each round, not triggered by the player.
	void m_CritalAttack(Character* enemy);

	// Spell attack, triggered by the player every round and deplete MP value.
	void m_SpellAttack(Character* enemy);

	// Block the attack from the enemies, triggered by the player every round.
	void m_Block(vector <Character*> element);

	// Escape from the game.
	void Escape();
};



class Enemy : public Character {
public:
	Enemy(string name, int HP, int MP);

	~Enemy();

	void m_RegulerAttack(Character* enemy);

	// The character has a chance to give crital attack at each round, not triggered by the player.
	void m_CritalAttack(Character* enemy);

	// Spell attack, triggered by the player every round and deplete MP value.
	void m_SpellAttack(Character* enemy);

	// Block the attack from the enemies, triggered by the player every round.
	void m_Block(vector <Character*> element);
};

