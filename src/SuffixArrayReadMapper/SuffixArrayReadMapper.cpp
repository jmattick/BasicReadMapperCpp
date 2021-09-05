// SuffixArrayReadMapper.cpp : Defines the entry point for the application.
//

#include "ParseFasta.h"
#include "SuffixArrayReadMapper.h"
#include "SuffixArray.h"
#include "SuffixArraySearch.h"

#include <string>
#include <vector>
#include <array>
#include <iterator>
#include "ParseMappedReads.h"

int SuffixArrayMapWorkflow(int argc, char* argv[])
{
	// minimum argc is 4
	if (argc < 4) {
		std::cout << "Help text" << std::endl;
		return 1;
	}

	//set paths from arguments
	std::string refPath = argv[1];
	std::string readPath = argv[2];
	std::string outPath = argv[3];
	

	std::cout << "Hello From Suffix Array Read Mapper!" << std::endl;
	
	//parse fasta files
	std::vector<Fasta> refFastas;
	ParseFasta(&refFastas, refPath);
	Fasta refFasta = refFastas.at(0); // only want first sequence 
	
	std::cout << "Reference.fasta file path: " << refPath << std::endl;
	/*std::cout << "Reference fasta: \n>";
	std::cout << refFasta.getName() << std::endl;
	std::cout << refFasta.getSeq() << std::endl;
	std::cout << "Reference sequence length : " << refFasta.getSeq().length() << std::endl;*/

	std::vector<Fasta> readFastas;
	ParseFasta(&readFastas, readPath);

	std::cout << "Reads.fasta File Path: " << readPath << std::endl;
	/*std::cout << "Number of reads in " << readPath << ": " 
		<< readFastas.size() << std::endl;*/

	//suffix array code
	std::string refSeq = refFasta.getSeq();
	const std::size_t refSize= refSeq.size();

	std::size_t* suffixArray;
	suffixArray = GenerateSuffixArray(refSeq, refSize);

	////print out suffixArray
	//for (std::size_t i = 0; i < refSize; i++)
	//{
	//	std::cout << suffixArray[i] << " ";
	//}
	
	//std::cout << "\nOrdered Suffixes (first 20 char): \n";
	////print out suffixes
	//for (std::size_t i = 0; i < refSize; i++)
	//{
	//	std::cout << refSeq.substr(suffixArray[i], refSize).substr(0,20) << "\n";
	//}

	//std::vector<Fasta> reads, std::size_t* suffixArray, std::string refSeq, std::size_t n
	MappedRead *mappedReads = SearchSuffixArray(readFastas, suffixArray, refSeq, refSize);
	

	//output
	ParseMappedReadsOut(refFasta, mappedReads, readFastas.size(), outPath);
	std::cout << "\nOutput file: " << outPath << std::endl;
	


	return 0;
}
