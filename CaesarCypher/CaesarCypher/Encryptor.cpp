#include "Encryptor.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

Encryptor::Encryptor()
{
	char holderString[1000000];
	cin.ignore();
	cin.getline(holderString, sizeof(holderString));

	for (int i = 0; i < sizeof(holderString); i++) {
		if ((holderString[i]) != holderString[sizeof(holderString) - 1]) 
			baseStory.push_back(holderString[i]);
	}
}

void Encryptor::encrypt(int caesarNumber)
{
	for (int i = 0; i < baseStory.size(); i++) {
		int convertedNumber = (int) baseStory.at(i);
		if (convertedNumber != 32) {
			convertedNumber = (convertedNumber + caesarNumber);
		}
		if (convertedNumber > 122) {
			convertedNumber -= 26;
		}
		encryptedStory.push_back(convertedNumber);
	}
}

void Encryptor::printToFile(std::string fileName)
{
	file.open(fileName, std::ios::out);//write 
	for (int i = 0; i < encryptedStory.size(); i++) {
		file << encryptedStory.at(i);
	}
}