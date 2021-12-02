/*
	Team: G-Force

	Norman, Curt(TTH 6:30)
	Pham, Martin(TTH 6:30)
	Toti, Nathanial(TTH 6:30)

	December 1, 2020

	CS A250
	Project 2
*/

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	candidates.push_back(newCandidate);
}

int CandidateList::getWinner() const
{
	list<CandidateType>::const_iterator curr = candidates.cbegin();
	int max = curr->getTotalVotes();
	int winnerID = curr->getID();
	for (; curr != candidates.cend(); ++curr)
	{
		if (curr->getTotalVotes() > max)
		{
			max = curr->getTotalVotes();
			winnerID = curr->getID();
		}
	}
	return winnerID;
}

bool CandidateList::searchCandidate(int id) const
{
	list<CandidateType>::const_iterator itrCandidate = candidates.cbegin();
	return searchCandidate(id, itrCandidate);
}

void CandidateList::printCandidateName(int id) const
{
	list<CandidateType>::const_iterator itrCandidate = candidates.cbegin();
	if (searchCandidate(id, itrCandidate))
	{
		itrCandidate->printName();
	}
}

void CandidateList::printAllCandidates() const
{
	for (const auto& e : candidates)
	{
		e.printCandidateInfo();
		cout << '\n';
	}
}

void CandidateList::printKingdomVotes(int id, int index) const
{
	list<CandidateType>::const_iterator currentCandidateVotes = candidates.cbegin();
	if (searchCandidate(id, currentCandidateVotes))
	{
		cout << "    * " << setw(2) << currentCandidateVotes->getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << "\n";
	}
}

void CandidateList::printCandidateTotalVotes(int id) const
{
	list<CandidateType>::const_iterator candidateTotalVotes = candidates.cbegin();
	if (searchCandidate(id, candidateTotalVotes))
	{
		cout << "    => Total votes: " << candidateTotalVotes->getTotalVotes() << '\n';
	}
}

void CandidateList::printFinalResults() const
{
	printHeader();

	size_t len = candidates.size();
	int pos(0);
	list<CandidateType>::const_iterator* candidatesDesc =
		new list<CandidateType>::const_iterator[len]();

	list<CandidateType>::const_iterator itr = candidates.cbegin();
	list<CandidateType>::const_iterator itrEnd = candidates.cend();
	while (itr != itrEnd)
	{
		candidatesDesc[pos] = itr;
		++itr;
		++pos;
	}

	itr = candidates.cbegin();
	int idxOfHighestVotes = itr->getTotalVotes();
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			idxOfHighestVotes = i;
			if (candidatesDesc[j]->getTotalVotes() > candidatesDesc[idxOfHighestVotes]->getTotalVotes())
			{
				idxOfHighestVotes = j;
				list<CandidateType>::const_iterator temp = candidatesDesc[i];
				candidatesDesc[i] = candidatesDesc[idxOfHighestVotes];
				candidatesDesc[idxOfHighestVotes] = temp;
			}
		}

		int rank = i + 1;
		printCandidate(candidatesDesc[i], (rank));
		if (rank % 5 == 0)
		{
			cout << string(40, '-');
			cout << '\n';
		}

		++itr;
	}

	delete[] candidatesDesc;

	cout << string(40, '_');
}

/*********************************************
* FUNCTION ADDED FOR SELECTION #6
*********************************************/
void CandidateList::printCandidateByRank(int rank) const
{
	if (rank > 0 && rank <= static_cast<int>(candidates.size()))
	{
		size_t len = candidates.size();
		int pos(0);
		list<CandidateType>::const_iterator* candidatesDesc =
			new list<CandidateType>::const_iterator[len]();

		list<CandidateType>::const_iterator itr = candidates.cbegin();
		list<CandidateType>::const_iterator itrEnd = candidates.cend();
		while (itr != itrEnd)
		{
			candidatesDesc[pos] = itr;
			++itr;
			++pos;
		}

		itr = candidates.cbegin();
		int idxOfHighestVotes = itr->getTotalVotes();
		for (int i = 0; i < len; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				idxOfHighestVotes = i;
				if (candidatesDesc[j]->getTotalVotes() > candidatesDesc[idxOfHighestVotes]->getTotalVotes())
				{
					idxOfHighestVotes = j;
					list<CandidateType>::const_iterator temp1 = candidatesDesc[i];
					candidatesDesc[i] = candidatesDesc[idxOfHighestVotes];
					candidatesDesc[idxOfHighestVotes] = temp1;
				}
			}

			++itr;
		}

		cout << "\nRank " << rank << " was: \n";
		candidatesDesc[rank - 1]->printCandidateInfo();
		cout << '\n';

		delete[] candidatesDesc;
	}
	else
	{
		cerr << "\nPlease enter a valid rank.\n";
	}
}

bool CandidateList::searchCandidate(int id, list<CandidateType>::const_iterator& itrCandidate) const
{
	itrCandidate = find(itrCandidate, candidates.end(), id);
	if (itrCandidate == candidates.end())
	{
		cerr << "    => ID not in the list." << "\n";
	}
	return itrCandidate != candidates.end();
}

void CandidateList::printHeader() const
{
	cout << string(12, '*') << " FINAL RESULTS " << string(12, '*') << "\n";
	cout << "\n" << left << setw(15) << "LAST" << setw(10) << left << "FIRST" << setw(9) << left << "TOTAL" << setw(3) << "POS";
	cout << "\n" << left << setw(15) << "NAME" << setw(10) << left << "NAME" << setw(9) << left << "VOTES" << setw(3) << "  #";
	cout << "\n" << string(40, '_');
	cout << "\n\n";
}

void CandidateList::printCandidate(list<CandidateType>::const_iterator& theCandidate, int rank) const
{
	cout << left << setw(15) << theCandidate->getLastName()
		<< setw(12) << left << theCandidate->getFirstName()
		<< setw(7) << left << theCandidate->getTotalVotes()
		<< right << setw(3) << rank << '\n';
}