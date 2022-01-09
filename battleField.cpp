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

void BattleGround::CreateHero(int choice) {

	while (true) {
		if (choice == 1) {
			m_hero = new Hero("Thor", 100, 50);
			break;
		}
		else if (choice == 2) {
			m_hero = new Hero("Hulk", 100, 50);
			break;
		}
		else if (choice == 3) {
			m_hero = new Hero("Iron man", 100, 50);
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
}

void BattleGround::StartFight() {
	int round_counter = 1;
	while (true)
	{
		system("pause");
		system("cls");

		cout << "---------------------" << endl;
		cout << "Round " << round_counter << endl;
		cout << "---------------------" << endl;
		cout << m_hero->m_name << "\t" << " HP: \t" << m_hero->m_HP << "\t" << " MP: \t" << m_hero->m_MP << "\t" << endl;
		cout <<  m_enemy_1->m_name << "\t" << " HP: \t" << m_enemy_1->m_HP << "\t" << " MP: \t" << m_enemy_1->m_MP << "\t" << endl;
		cout <<  m_enemy_2->m_name << "\t" << " HP: \t" << m_enemy_2->m_HP << "\t" << " MP: \t" << m_enemy_2->m_MP << "\t" << endl;
		cout <<  m_enemy_3->m_name << "\t" << " HP: \t" << m_enemy_3->m_HP << "\t" << " MP: \t" << m_enemy_3->m_MP << "\t" << endl;
		cout << "---------------------\n" << endl;

		int attack_choice;
		cout << "---------------------" << endl;
		cout << " 1. Regular Attack " << endl;
		cout << " 2. Spell Attack " << endl;
		cout << " 3. Block " << endl;
		cout << "---------------------" << endl;
		cout << "Please choose your option..." << endl;

		cin >> attack_choice;

		if (attack_choice == 1) {
			m_hero->m_RegulerAttack(m_enemy_1);
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


		CheckIsAlive();
		round_counter ++;
	}
}

void BattleGround::CheckIsAlive() {
	if (m_enemy_1->m_HP <= 0) {
		system("pause");
		exit(0);
	}
}