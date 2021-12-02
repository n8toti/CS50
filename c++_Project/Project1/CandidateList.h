/*
	Team: G-Force

	Norman, Curt(TTH 6:30)
	Pham, Martin(TTH 6:30)
	Toti, Nathanial(TTH 6:30)

	December 1, 2020

	CS A250
	Project 2
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

class CandidateList
{
public:
	// Default constructor
	CandidateList() {}

	// addCandidate
	void addCandidate(const CandidateType& newCandidate);
	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const { return static_cast<int>(candidates.size()) == 0; }

	// searchCandidate
	bool searchCandidate(int id) const;

	// printCandidateName
	void printCandidateName(int id) const;
	// printAllCandidates
	void printAllCandidates() const;
	// printKingdomVotes
	void printKingdomVotes(int id, int index) const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes(int id) const;

	// printFinalResults
	void printFinalResults() const;

	/*********************************************
	* FUNCTION ADDED FOR SELECTION #6
	*********************************************/
	void printCandidateByRank(int rank) const;

	// Destructor
	~CandidateList() {}

private:
	std::list<CandidateType> candidates;

	// searchCandidate
	bool searchCandidate(int id, std::list<CandidateType>::const_iterator& itrCandidate) const;
	
	// printHeader
	void printHeader() const;
	//printCandidate
	void printCandidate(std::list<CandidateType>::const_iterator& printCand, int rank) const;
};

#endif