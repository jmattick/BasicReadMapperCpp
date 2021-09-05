#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "ParseFasta.h"
#include "SuffixArraySearch.h"
#include "SuffixArraySearch.h"

void ParseMappedReadsOut(Fasta refSeq, MappedRead* mappedReads, std::size_t n, std::string outPath);