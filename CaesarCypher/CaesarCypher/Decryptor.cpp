#include "Decryptor.h"
#include <iostream>

Decryptor::Decryptor(std::string fileName) 
{
	char inputString[100000];
	file.open(fileName, std::ios::in);
	file.getline(inputString, 100000);
	for (int i = 0; i < sizeof(inputString); i++) {
		if (inputString[i] == 3) {
			encryptedStory.push_back(32);
			i++;
		}
		else if (inputString[i] == 1) {
			int number = 100 + (inputString[i + 1] * 10 + inputString[i + 2]);
			encryptedStory.push_back(number);
			i += 2;
		}
		else if (inputString[i] == 0) {
			break;
		}
		else {
			int number = inputString[i] * 10 + inputString[i+1];
			encryptedStory.push_back(number);
			i++;
		}
	}
}

void Decryptor::decrypt(int caesarNumber) 
{
	for (int i = 0; i < encryptedStory.size(); i++) {
		int convertedNumber = encryptedStory.at(i);
		if (convertedNumber != 32) {
			convertedNumber -= caesarNumber;
			if (convertedNumber < 97) {
				convertedNumber = 122 - (97 - convertedNumber);
			}
		}
		baseStory.push_back((char) convertedNumber);
	}
}

void Decryptor::printToConsole()
{
	for (int i = 0; i < baseStory.size(); i++) {
		std::cout << baseStory.at(i);
	}
}