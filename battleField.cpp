#include "battlefield.h"
#include <iostream>
#include "stdlib.h"
using namespace std;

void BattleGround::Exit() {
	cout << "Goodbye!" << endl;
	system("pause");
	exit(0);
}

void BattleGround::ShowMenu() {
	cout << "------------------------------------------" << endl;
	cout << "------------1. Enter the game ------------" << endl;
	cout << "------------2. Exit the game  ------------" << endl;
	cout << "------------------------------------------\n" << endl;
	cout << "Please enter your choice..." << endl;
}

void BattleGround::ShowBattleInfo() {
	cout << "---------------------" << endl;
	cout << "Round " << m_round_counter << endl;
	cout << "---------------------" << endl;
	cout << m_hero->m_name << "\t" << " HP: \t" << m_hero->m_HP << "\t" << " MP: \t" << m_hero->m_MP << "\t" << endl;
	cout << m_enemy_1->m_name << "\t" << " HP: \t" << m_enemy_1->m_HP << "\t" << " MP: \t" << m_enemy_1->m_MP << "\t" << endl;
	cout << m_enemy_2->m_name << "\t" << " HP: \t" << m_enemy_2->m_HP << "\t" << " MP: \t" << m_enemy_2->m_MP << "\t" << endl;
	cout << m_enemy_3->m_name << "\t" << " HP: \t" << m_enemy_3->m_HP << "\t" << " MP: \t" << m_enemy_3->m_MP << "\t" << endl;
	cout << "---------------------\n" << endl;
}


void BattleGround::CreateHero(int choice) {

	while (true) {
		if (choice == 1) {
			m_hero = new Hero("Thor", THOR_MAX_HP, THOR_MAX_MP);
			m_elements.push_back(m_hero);
			break;
		}
		else if (choice == 2) {
			m_hero = new Hero("Hulk", HULK_MAX_HP, HULK_MAX_MP);
			m_elements.push_back(m_hero);
			break;
		}
		else if (choice == 3) {
			m_hero = new Hero("Iron man", IRONMAN_MAX_HP, IRONMAN_MAX_MP);
			m_elements.push_back(m_hero);
			break;
		}
		else {
			cout << "Wrong choice, randomly created a hero for you...\n" << endl;
			srand((unsigned)time(NULL));
			int random = (rand() % NUM_ENEMY) + 1;
			choice = random;
		}
	}
}

void BattleGround::CreateEnemy() {

	m_enemy_1 = new Enemy("Slime", 20, 10);
	m_enemy_2 = new Enemy("Crepper", 30, 30);
	m_enemy_3 = new Enemy("Gollum", 25, 20);
	m_elements.push_back(m_enemy_1);
	m_elements.push_back(m_enemy_2);
	m_elements.push_back(m_enemy_3);
}

void BattleGround::StartFight() {
	m_round_counter = 1;
	while (true)
	{
		system("pause");
		system("cls");

		ShowBattleInfo();

		int attack_choice, enemy_choice;
		cout << "---------------------" << endl;
		cout << " 1. Regular Attack " << endl;
		cout << " 2. Spell Attack " << endl;
		cout << " 3. Block " << endl;
		cout << "---------------------" << endl;
		cout << "Please choose your option...\n" << endl;

		cin >> attack_choice;

		switch (attack_choice)
		{
		case 1:
			cout << "Which enemy you wanna attack (1, 2, 3)...\n" << endl;

			cin >> enemy_choice;
			if (enemy_choice == 1) {

				m_hero->m_RegulerAttack(m_elements[1]);
			}
			else if (enemy_choice == 2) {
				m_hero->m_RegulerAttack(m_elements[2]);
			}
			else if (enemy_choice == 3) {
				m_hero->m_RegulerAttack(m_elements[3]);
			}
			else {
				cout << "Wrong input, system helped you make a choice...\n" << endl;
			}
			break;
		case 2:
			cout << "Which enemy you wanna attack (1, 2, 3)...\n" << endl;

			cin >> enemy_choice;
			if (enemy_choice == 1 && m_hero->m_MP >= BASE_SPELL_ATTACK) {
				m_hero->m_SpellAttack(m_elements[1]);
			}
			else if (enemy_choice == 2 && m_hero->m_MP >= BASE_SPELL_ATTACK) {
				m_hero->m_SpellAttack(m_elements[2]);
			}
			else if (enemy_choice == 3 && m_hero->m_MP >= BASE_SPELL_ATTACK) {
				m_hero->m_SpellAttack(m_elements[3]);
			}
			else {
				cout << "Wrong input or not enough MP value, hero will block the enemies' attack...\n" << endl;
				m_hero->m_Block(m_elements);
			}
			break;
		case 3:
			m_hero->m_Block(m_elements);
			break;
		default:
			cout << "Wrong input, hero will block the enemies' attack...\n" << endl;
				m_hero->m_Block(m_elements);
		}

		EnemyFightBack();

		RecoverCharactersMP();

		CheckIsAlive();
		m_round_counter ++;
	}
}

// The enemies need to fight back automatically by the system.
void BattleGround::EnemyFightBack() {
	// Enemy will perform regular attack or spell attack.
	srand((unsigned)time(NULL));
	int chance = (rand() % 3 + 1);

	if (chance != 3) {
		m_enemy_1->m_RegulerAttack(m_hero);
		m_enemy_2->m_RegulerAttack(m_hero);
		m_enemy_3->m_RegulerAttack(m_hero);
	}
	// If not enough MP, the enemies will perform regular attack.
	else {
		if (m_enemy_1->m_MP > 0) {
			m_enemy_1->m_SpellAttack(m_hero);
		}
		else {
			m_enemy_1->m_RegulerAttack(m_hero);
		}

		if (m_enemy_2->m_MP > 0) {
			m_enemy_2->m_SpellAttack(m_hero);
		}
		else {
			m_enemy_2->m_RegulerAttack(m_hero);
		}

		if (m_enemy_3->m_MP > 0) {
			m_enemy_3->m_SpellAttack(m_hero);
		}
		else {
			m_enemy_3->m_RegulerAttack(m_hero);
		}
	}

}

void BattleGround::RecoverCharactersMP() {
	// Recover hero and enemies' MP value.
	m_hero->m_MP += HERO_MP_RECOVERY;
	if (m_enemy_1->m_HP > 0) {
		m_enemy_1->m_MP += ENEMY_MP_RECOVERY;
	}
	if (m_enemy_2->m_HP > 0) {
		m_enemy_2->m_MP += ENEMY_MP_RECOVERY;
	}
	if (m_enemy_3->m_HP > 0) {
		m_enemy_3->m_MP += ENEMY_MP_RECOVERY;
	}
}

void BattleGround::CheckIsAlive() {
	// The player will win the game when all enemies are dead.
	if (m_enemy_1->m_HP <= 0 && m_enemy_2->m_HP <= 0 && m_enemy_3->m_HP <= 0) {
		cout << m_hero->m_name << " won!\n" << endl;
		system("pause");
		exit(0);
	}
	// The player lose when the hero dead.
	if (m_hero->m_HP <= 0) {
		cout << m_hero->m_name << " lose!\n" << endl;
		system("pause");
		exit(0);
	}
}

// Destory all objects.
BattleGround::~BattleGround() {
	delete m_hero;
	delete m_enemy_1;
	delete m_enemy_2;
	delete m_enemy_3;
	cout << "Game over! All characters are destoried...\n" << endl;
}