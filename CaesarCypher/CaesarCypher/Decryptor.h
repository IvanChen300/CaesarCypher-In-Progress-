#pragma once
#include <fstream>
#include <vector>

class Decryptor
{
	private:
		std::fstream file;
		std::vector<int> encryptedStory;
		std::vector<char> baseStory;

	public:
		Decryptor(std::string fileName);
		void decrypt(int caesarNumber);
		void printToConsole();
};

