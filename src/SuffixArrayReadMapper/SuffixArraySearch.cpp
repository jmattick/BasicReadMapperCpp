#include "SuffixArraySearch.h"

MappedRead::MappedRead()
{
}

MappedRead::MappedRead(Fasta f, std::size_t l)
{
	fasta = f;
	loc = l;
}

void MappedRead::setFasta(Fasta f)
{
	fasta = f;
}

void MappedRead::setLoc(std::size_t l)
{
	loc = l;
}


// binary search of fasta read using suffix array
std::size_t ReadBinarySearch(std::size_t* suffixArray, Fasta fasta, std::string refSeq, std::size_t refSize)
{
	std::size_t low = 0, high = refSize;
	std::string read = fasta.getSeq();
	std::size_t readSize = read.size();

	while (low < high)
	{
		//get middle index
		std::size_t mid = low + (high - low) / 2;

		//get substring of length read at mid index in refSeq
		std::string subSeq = refSeq.substr(suffixArray[mid], readSize);
		
		if (subSeq.compare(read) < 0)
		{
			low = mid + 1;
		}
		else if (subSeq.compare(read) > 0)
		{
			high = mid;
		}
		else
		{
			return suffixArray[mid];
		}
	}

	//if not found 
	return refSize;//return end
}

MappedRead* SearchSuffixArray(std::vector<Fasta> reads, std::size_t* suffixArray, std::string refSeq, std::size_t n)
{
	std::cout << "\nMapping Reads...\n";

	std::size_t numReads = reads.size();
	MappedRead* mappedreads = new MappedRead[numReads];

	for (std::size_t i = 0; i < numReads; i++)
	{
		*(mappedreads + i) = MappedRead(reads[i], ReadBinarySearch(suffixArray, reads[i], refSeq, n));
	}


	return mappedreads;
}
