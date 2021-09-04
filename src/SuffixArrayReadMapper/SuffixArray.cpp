#include "SuffixArray.h"

int * GenerateSuffixArray(std::string seq, std::size_t n)
{
	std::cout << "Generating Suffix Array..." << std::endl;
	
	int* suffixArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(suffixArray + i) = n - i;
	}

	return suffixArray;
}


