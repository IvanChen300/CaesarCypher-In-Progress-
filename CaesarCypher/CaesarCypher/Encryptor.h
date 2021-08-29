#pragma once
#include <fstream>
#include <vector>

class Encryptor
{
	private:
		std::fstream file;
		std::vector<char> baseStory;
		std::vector<int> encryptedStory;

	public:
		Encryptor();
		void encrypt(int caesarNumber);
		void printToFile(std::string fileName);
};

