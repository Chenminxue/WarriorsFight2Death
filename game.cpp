#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
#include "battlefield.h"
using namespace std;

int main() {

	// Create the battlefield object.
	BattleGround bg;

	// Main menu choice.
	int hall_choice;

	while (true)
	{
		bg.ShowMenu();

		// Player has to give a choice whether to enter the game or exit the game.
		cin >> hall_choice;
		
		switch (hall_choice) {
		
		// Enter the game.
		case 1:
			system("cls");
			
			int create_hero_choice;
			cout << "-----------------------------------------" << endl;
			cout << "-------------- 1. Thor ------------------" << endl;
			cout << "-------------- 2. Hulk ------------------" << endl;
			cout << "-------------- 3. Iron man --------------" << endl;
			cout << "-----------------------------------------\n" << endl;
			cout << "Please choose your hero!" << endl;
			cin >> create_hero_choice;
			
			system("cls");

			// Create hero and enemies.
			bg.CreateHero(create_hero_choice);
			bg.CreateEnemy();
			
			// Start the game.
			bg.StartFight();

			system("pause");
			break;

		// Exit the game.
		case 2:
			bg.Exit();
			break;

		// Wrong input choice.
		default:
			cout << "Wrong input, please enter 1 or 2...\n" << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}
