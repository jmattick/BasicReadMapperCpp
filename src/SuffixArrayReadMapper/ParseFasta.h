#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Fasta 
{
private:
	std::string name;
	std::string seq;
public:
	Fasta();
	Fasta(std::string n, std::string s);
	void setName(std::string n);
	void setSeq(std::string s);

	std::string getName() { return name; }
	std::string getSeq() { return seq; }

};

//Parse file contents into Fasta vector
void ParseFasta(std::vector<Fasta>* sequences, std::string filePath);