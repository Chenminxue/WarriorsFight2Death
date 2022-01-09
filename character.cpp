#include "character.h"
#include "stdlib.h"

#define BASE_REGULAR_ATTACK 5
#define WEAKEN_REGULAR_ATTACK_MAX 3
#define WEAKEN_REGULAR_ATTACK_MIN 1

/* Hero implementations. */

Hero::Hero(string name, int HP, int MP) {
	m_name = name;
	m_HP = HP;
	m_MP = MP;
	cout << "Hero " << m_name << " joined the game! HP: " << m_HP <<
		" MP: " << m_MP << " \n" << endl;
}

Hero::~Hero() {
	
}

void Hero::m_RegulerAttack(Character* enemy) {
	srand((unsigned)time(NULL));
	enemy->m_HP -= (BASE_REGULAR_ATTACK - ((rand() % WEAKEN_REGULAR_ATTACK_MAX) + WEAKEN_REGULAR_ATTACK_MIN));
}

// The character has a chance to give crital attack at each round, not triggered by the player.
void Hero::m_CritalAttack(Character* enemy) {

}

// Spell attack, triggered by the player every round and deplete MP value.
void Hero::m_SpellAttack(Character* enemy) {

}

// Block the attack from the enemies, triggered by the player every round.
void Hero::m_Block(Character* enemy) {

}

// Escape from the game.
void Hero::Escape() {

}

/* Enemy implementations. */

Enemy::Enemy(string name, int HP, int MP) {
	m_name = name;
	m_HP = HP;
	m_MP = MP;
	cout << "Enemy " << m_name << " joined the game! HP: " << m_HP <<
		" MP: " << m_MP << " \n" << endl;
}

Enemy::~Enemy() {

}

void Enemy::m_RegulerAttack(Character* enemy) {
	srand((unsigned)time(NULL));
	enemy->m_HP -= (BASE_REGULAR_ATTACK - ((rand() % WEAKEN_REGULAR_ATTACK_MAX) + WEAKEN_REGULAR_ATTACK_MIN));
}

// The character has a chance to give crital attack at each round, not triggered by the player.
void Enemy::m_CritalAttack(Character* enemy) {

}

// Spell attack, triggered by the player every round and deplete MP value.
void Enemy::m_SpellAttack(Character* enemy) {

}

// Block the attack from the enemies, triggered by the player every round.
void Enemy::m_Block(Character* enemy) {

}