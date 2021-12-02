/*
	Team: G-Force

	Norman, Curt(TTH 6:30)
	Pham, Martin(TTH 6:30)
	Toti, Nathanial(TTH 6:30)

	December 1, 2020

	CS A250
	Project 2
*/

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "CharacterType.h"

const int NUM_OF_KINGDOMS = 7;	// this is the capacity of the array
const std::string KINGDOMS[] = {
	"The North",
	"The Vale",
	"The Stormlands",
	"The Reach",
	"The Westerlands",
	"The Iron Islands",
	"Dorne"
};

class CandidateType : public CharacterType
{
public:
	// Default constructor
	CandidateType() : totalVotes(0), numOfKingdoms(NUM_OF_KINGDOMS), kingdomVotes(new int[numOfKingdoms]{0}) {} 
	// Copy constructor
	CandidateType(const CandidateType& otherCandidateType);

	// Copy assignment operator
	CandidateType& operator=(const CandidateType& rightHandSide);

	// Comparison operator
	bool operator==(int id) const
	{
		return getID() == id;
	}

	// updateVotesByKingdom
	void updateVotesByKingdom(int index, int votes);

	// getTotalVotes
	int getTotalVotes() const { return totalVotes; }
	// getVotesByKingdom
	int getVotesByKingdom(int index) const { return kingdomVotes[index]; }

	// printCandidateInfo
	void printCandidateInfo() const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes() const;

	// Destructor
	~CandidateType();

private:
	int totalVotes;
	int numOfKingdoms;
	int* kingdomVotes;
};
#endif