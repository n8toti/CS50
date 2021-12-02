/*
	Team: G-Force

	Norman, Curt(TTH 6:30)
	Pham, Martin(TTH 6:30)
	Toti, Nathanial(TTH 6:30)

	December 1, 2020

	CS A250
	Project 2
*/

#include <iomanip>
#include <iostream>

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

void CharacterType::setCharacterInfo(const string& newFirstName, const string& newLastName, int newID)
{
	firstName = newFirstName;
	lastName = newLastName;
	id = newID;
}

void CharacterType::printName() const 
{
	cout << lastName << ", " << firstName;
}

void CharacterType::printCharacterInfo() const 
{
	printID();
	cout << " " << firstName << " " << lastName;
}

void CharacterType::printID() const 
{
	cout << "ID# " << setfill('0') << setw(6) << id << setfill(' ');
}