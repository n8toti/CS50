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

#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CandidateType::CandidateType(const CandidateType& otherCandidateType)
	: CharacterType(otherCandidateType.getFirstName(),
					otherCandidateType.getLastName(),
					otherCandidateType.getID())
{
	totalVotes = otherCandidateType.getTotalVotes();
	numOfKingdoms = otherCandidateType.numOfKingdoms;

	kingdomVotes = new int[numOfKingdoms];
	for (int i = 0; i < numOfKingdoms; i++)
	{
		kingdomVotes[i] = otherCandidateType.getVotesByKingdom(i);
	}
}

CandidateType& CandidateType::operator=(const CandidateType& rightHandSide)
{
	if (&rightHandSide != this)
	{
		totalVotes = rightHandSide.getTotalVotes();
		setCharacterInfo(rightHandSide.getFirstName(),
										rightHandSide.getLastName(),
										rightHandSide.getID());

		if (rightHandSide.numOfKingdoms != numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[rightHandSide.numOfKingdoms];
		}

		for (int i = 0; i < numOfKingdoms; i++)
		{
			kingdomVotes[i] = rightHandSide.getVotesByKingdom(i);
		}
	}
	else
	{
		cerr << "Instance self-assignment is not allowed.";
	}

	return *this;
}

void CandidateType::updateVotesByKingdom(int index, int votes)
{
	totalVotes -= kingdomVotes[index];
	kingdomVotes[index] = votes;
	totalVotes += votes;
}

void CandidateType::printCandidateInfo() const
{
	printID();
	cout << " - ";
	printName();
}

void CandidateType::printCandidateTotalVotes() const 
{
	printName();
	cout << "\n=> Total Votes (all kingdoms): " << setfill('0') << setw(3) << getTotalVotes();
}

CandidateType::~CandidateType()
{
	delete[] kingdomVotes;
	kingdomVotes = nullptr;
}