#include "character.h"
#include "stdlib.h"

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
	// Only perform attack when the HP of the enemy is larger than 0.
	if (enemy->m_HP >0) {
		srand((unsigned)time(NULL));
		enemy->m_HP -= (BASE_REGULAR_ATTACK - ((rand() % WEAKEN_REGULAR_ATTACK_MAX) + WEAKEN_REGULAR_ATTACK_MIN));
	}
	else {
		cout << "You are hitting the dead body! No effect!\n" << endl;
	}

	// Avoid negative value.
	if (enemy->m_HP < 0) {
		enemy->m_HP = 0;
	}
}

// Spell attack, triggered by the player every round and deplete MP value.
void Hero::m_SpellAttack(Character* enemy) {
	// Only perform attack when the HP of the enemy is larger than 0.
	if (enemy->m_HP > 0) {
		srand((unsigned)time(NULL));
		enemy->m_HP -= (BASE_SPELL_ATTACK - ((rand() % WEAKEN_SPELL_ATTACK_MAX) + WEAKEN_SPELL_ATTACK_MIN));
		m_MP -= 10;
	}
	else {
		cout << "You are hitting the dead body! No effect!\n" << endl;
	}

	// Avoid negative value.
	if (enemy->m_HP < 0) {
		enemy->m_HP = 0;
	}
}

// Block the attack from the enemies, triggered by the player every round.
void Hero::m_Block(vector <Character*> element) {
	for (int i = 1; i < element.size(); i++) {
		element[i]->m_IsBlockActivated = true;
	}
}


/* Enemy implementations. */

Enemy::Enemy(string name, int HP, int MP) {
	m_name = name;
	m_HP = HP;
	m_MP = MP;
	m_IsBlockActivated = false;
	cout << "Enemy " << m_name << " joined the game! HP: " << m_HP <<
		" MP: " << m_MP << " \n" << endl;
}

Enemy::~Enemy() {

}

void Enemy::m_RegulerAttack(Character* enemy) {
	// Attack value is not a fixed value.
	srand((unsigned)time(NULL));
	// Will block by the hero or not.
	if (m_IsBlockActivated == false) {
		enemy->m_HP -= ((BASE_REGULAR_ATTACK - 2) - ((rand() % WEAKEN_REGULAR_ATTACK_MAX) + WEAKEN_REGULAR_ATTACK_MIN));
	}
	else {
		enemy->m_HP -= BLOCK_PERCNETAGE * ((BASE_REGULAR_ATTACK - 2) - ((rand() % WEAKEN_REGULAR_ATTACK_MAX) + WEAKEN_REGULAR_ATTACK_MIN));
	}

}

// Spell attack, triggered by the system every round and deplete MP value.
void Enemy::m_SpellAttack(Character* enemy) {
	srand((unsigned)time(NULL));
	// Will block by the hero or not.
	if (m_IsBlockActivated == false) {
		enemy->m_HP -= ((BASE_SPELL_ATTACK - 2) - ((rand() % WEAKEN_SPELL_ATTACK_MAX) + WEAKEN_SPELL_ATTACK_MIN));
	}
	else {
		enemy->m_HP -= BLOCK_PERCNETAGE * ((BASE_SPELL_ATTACK - 2) - ((rand() % WEAKEN_SPELL_ATTACK_MAX) + WEAKEN_SPELL_ATTACK_MIN));

	}
	m_MP -= 6;
}

void Enemy::m_Block(vector <Character*> element) {

}