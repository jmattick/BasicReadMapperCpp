#include "ParseFasta.h"

//Fasta class
Fasta::Fasta(std::string n, std::string s)
{
	setName(n);
	setSeq(s);
}

void Fasta::setName(std::string n)
{
	name = n;
}

void Fasta::setSeq(std::string s)
{
	seq = s;
}

//ParseFasta Function
void ParseFasta(std::vector<Fasta>* sequences, std::string filePath)
{
	std::ifstream infile(filePath);
	if (!infile.is_open())
	{
		std::cout << "Unable to open file: " << filePath << std::endl;
	}
	else
	{
		std::string line;
		std::string name;
		std::string seq;

		while (std::getline(infile, line))
		{
			if (line[0] == '>') //check for fasta name
			{
				name = line.erase(0, 1);
			}
			else
			{
				seq = line;
				Fasta curr = Fasta(name, seq);
				sequences->push_back(curr);
			}
		}
	}

}
