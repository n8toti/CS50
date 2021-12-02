/*
	Team: G-Force

	Norman, Curt(TTH 6:30)
	Pham, Martin(TTH 6:30)
	Toti, Nathanial(TTH 6:30)

	December 1, 2020

	CS A250
	Project 2
*/

#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <string>

class CharacterType
{
public:
	// Default constructor
	CharacterType() : id(0) {}
	// Overloaded constructor
	CharacterType(const std::string& newFirstName, const std::string& newLastName, int newID) :
		firstName(newFirstName),
		lastName(newLastName),
		id(newID)
	{}
	
	// setCharacterInfo
	void setCharacterInfo(const std::string& newFirstName, const std::string& newLastName, int newID);
	
	// getFirstName
	std::string getFirstName() const { return firstName; }
	// getLastName
	std::string getLastName() const { return lastName; }
	// getID
	int getID() const { return id; }

	// printName
	void printName() const;
	// printCharacterInfo
	void printCharacterInfo() const;
	// printID
	void printID() const;
	
	// Destructor
	~CharacterType() {}
private:
	std::string firstName;	
	std::string lastName;	
	int id;					
};
#endif
