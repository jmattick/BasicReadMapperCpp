#pragma once
#include <string>
#include <iostream>
#include <algorithm>

#include "ParseFasta.h"

class MappedRead
{
private:	
	Fasta fasta;
	std::size_t loc;
public:
	MappedRead();
	MappedRead(Fasta f, std::size_t l);
	void setFasta(Fasta f);
	void setLoc(std::size_t l);

	Fasta getFasta() { return fasta; }
	std::size_t getLoc() { return loc; }

};

//std::size_t ReadBinarySearch(std::size_t* suffixArray, Fasta fasta, std::string refSeq, std::string refSize);
std::size_t ReadBinarySearch(std::size_t* suffixArray, Fasta fasta, std::string refSeq, std::size_t refSize);

MappedRead* SearchSuffixArray(std::vector<Fasta> reads, std::size_t* suffixArray, std::string refSeq, std::size_t n);