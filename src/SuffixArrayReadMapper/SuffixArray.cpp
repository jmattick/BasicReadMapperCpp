#include "SuffixArray.h"
#include <cstring>
#include <algorithm>

//suffix structure
struct suffix
{
	std::size_t index;
	int rank[2];
};

//comparison function for suffixes
int compareSuffix(struct suffix a, struct suffix b)
{
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}

std::size_t * GenerateSuffixArray(std::string seq, std::size_t n)
{
	std::cout << "Generating Suffix Array..." << std::endl;

	//structure to store suffixes
	suffix* suffixes = new suffix[n];

	//store suffixes and index in array
	for (std::size_t i = 0; i < n; i++) 
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = seq[i] - 'a';
		suffixes[i].rank[1] = ((i + 1) < n) ? (seq[i + 1] - 'a') : -1;
	}

	//sort the suffixes according to the first two characters rank
	std::sort(suffixes, suffixes + n, compareSuffix);

	std::size_t* ind = new std::size_t[n]; //array to get ind in suffixes from original index

	for (std::size_t i = 4; i < 2 * n; i = i * 2)
	{
		//assign rank and index for first suffix
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = 0;
		ind[suffixes[0].index] = 0;

		//assign rank to remaining suffixes
		for (std::size_t j = 1; j < n; j++)
		{
			//if first rank and next rank are the same as previous suffix in array
			if (suffixes[j].rank[0] == prev_rank && suffixes[j].rank[1] == prev_rank)
			{
				//assign the same new rank to suffix
				prev_rank = suffixes[j].rank[0];
				suffixes[j].rank[0] = rank;
			}
			else //increment rank and assign
			{
				prev_rank = suffixes[j].rank[0];
				suffixes[j].rank[0] = ++rank;
			}
			ind[suffixes[j].index] = j;
		}

		//asign next rank to suffixes
		for (std::size_t k = 0; k < n; k++)
		{
			std::size_t modifier = (k % 2 == 0) ? k / 2 : (k - 1) / 2;
			std::size_t nextInd = suffixes[k].index + modifier;
			suffixes[k].rank[1] = (nextInd < n)? suffixes[ind[nextInd]].rank[0]: -1;
		}
		
		//sort suffixes according to first i characters
		std::sort(suffixes, suffixes + n, compareSuffix);


	}
	//suffix array
	std::size_t* suffixArray = new std::size_t[n];

	//store indexes of all sorted suffixes in suffix array
	for (std::size_t i = 0; i < n; i++)
	{
		suffixArray[i] = suffixes[i].index;
	}


	return suffixArray;
}


