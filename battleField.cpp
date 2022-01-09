#include "battlefield.h"
#include <iostream>
#include "stdlib.h"
using namespace std;

#define NUM_ENEMY 3

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
			m_hero = new Hero("Thor", 100, 50);
			m_elements.push_back(m_hero);
			break;
		}
		else if (choice == 2) {
			m_hero = new Hero("Hulk", 150, 20);
			m_elements.push_back(m_hero);
			break;
		}
		else if (choice == 3) {
			m_hero = new Hero("Iron man", 120, 30);
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
		cout << "Please choose your option..." << endl;

		cin >> attack_choice;

		cout << "Which enemy you wanna attack (1, 2, 3)..." << endl;

		cin >> enemy_choice;

		switch (enemy_choice)
		{
		case 1:
			if (attack_choice == 1) {

				m_hero->m_RegulerAttack(m_elements[1]);
			}
			else if (attack_choice == 2) {

			}
			else if (attack_choice == 3) {

			}
			else {
				cout << "Wrong input, system helped you make a choice..." << endl;
				system("pause");
				system("cls");
			}
		case 2:
			if (attack_choice == 1) {

				m_hero->m_RegulerAttack(m_elements[2]);
			}
			else if (attack_choice == 2) {

			}
			else if (attack_choice == 3) {

			}
			else {
				cout << "Wrong input, system helped you make a choice..." << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (attack_choice == 1) {

				m_hero->m_RegulerAttack(m_elements[3]);
			}
			else if (attack_choice == 2) {

			}
			else if (attack_choice == 3) {

			}
			else {
				cout << "Wrong input, system helped you make a choice..." << endl;
				system("pause");
				system("cls");
			}
			break;
		default:
			cout << "Wrong input, hero will block the enemies' attack..." << endl;
				m_hero->m_Block(m_elements);
		}

		EnemyFightBack();

		CheckIsAlive();
		m_round_counter ++;
	}
}

void BattleGround::EnemyFightBack() {
	m_enemy_1->m_RegulerAttack(m_hero);
	m_enemy_2->m_RegulerAttack(m_hero);
	m_enemy_3->m_RegulerAttack(m_hero);
	cout << m_hero->m_name << " got hit by the enemies..." << endl;
}

void BattleGround::CheckIsAlive() {
	if (m_enemy_1->m_HP <= 0 && m_enemy_2->m_HP <= 0 && m_enemy_3->m_HP <= 0) {
		cout << m_hero->m_name << " won!" << endl;
		system("pause");
		exit(0);
	}
	if (m_hero->m_HP <= 0) {
		cout << m_hero->m_name << " lose!" << endl;
		system("pause");
		exit(0);
	}
}