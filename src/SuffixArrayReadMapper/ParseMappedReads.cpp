#include "ParseMappedReads.h"

void ParseMappedReadsOut(std::string refSeq, MappedRead* mappedReads, std::size_t n, std::string outPath)
{
	std::string outTxt = refSeq + "\n";
	for (std::size_t i = 0; i < n; i++)
	{
		MappedRead read = mappedReads[i];
		std::size_t start = read.getLoc();

		//if read not mapped skip
		if (start > refSeq.size())
		{
			continue;
		}
		std::size_t end = start + read.getFasta().getSeq().size();
		for (std::size_t i = 0; i < start; i++) {
			outTxt += "-";
		}

		outTxt += mappedReads[i].getFasta().getSeq();

		for (std::size_t i = end; i < refSeq.size(); i++) {
			outTxt += "-";
		}

		outTxt += "\n";
	}

	std::ofstream outFile;
	outFile.open(outPath);
	outFile << outTxt;
	outFile.close();

}
