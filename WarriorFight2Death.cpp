#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
using namespace std;

class Warrior {
private:
	int AttackMax;
	int BlockMax;

public:
	string name;
	int health;

	Warrior(string name, int health, int AttackMax, int BlockMax);

	int Attack();

	int Block();
};

class Battle {
public:
	static void Fight(Warrior& role1, Warrior& role2);

	static string CheckResult(Warrior& role1, Warrior& role2);


};



int main() {

	Warrior Thor("Thor", 100, 35, 15);
	Warrior Hulk("Hulk", 125, 25, 10);

	Battle::Fight(Thor, Hulk);


	return 0;
}

Warrior::Warrior(string name, int health, int AttackMax, int BlockMax) {
	this->name = name;
	this->health = health;
	this->AttackMax = AttackMax;
	this->BlockMax = BlockMax;
}

int Warrior::Attack() {
	return rand() % this->AttackMax;
}

int Warrior::Block() {
	return rand() % this->BlockMax;
}

void Battle::Fight(Warrior& role1, Warrior& role2) {
	while (true) {
		if (Battle::CheckResult(role1, role2) == "Game over!" || Battle::CheckResult(role2, role1) == "Game over!") {
			cout << "Game over! \n";
				break;
		}
	}
}

string Battle::CheckResult(Warrior& role1, Warrior& role2) {
	int attackAmt = role1.Attack();
	int blockAmt = role2.Block();
	int damage2role2 = ceil(attackAmt - blockAmt);

	damage2role2 = damage2role2 <= 0 ? 0 : damage2role2;
	role2.health = role2.health - damage2role2;
	cout << role1.name << " attacks " << role2.name << " and deals " << damage2role2 << "damage.\n";
	cout << role1.name << " is down to " << role1.health << " health.\n ";
	
	if (role2.health <= 0) {
		cout << role2.name << " has died and " << role1.name << " won!\n";
		return "Game over!";
	}
	else {
		return "continue...";
	}
}
