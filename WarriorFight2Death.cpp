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

	static void CheckResult(Warrior& role1, Warrior& role2);


};



int main() {

	Warrior Thor("Thor", 100, 30, 15);


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
		if()
	}
}

void Battle::CheckResult(Warrior& role1, Warrior& role2) {

}
