#include <string>
#include <iostream>
#include "Encryptor.h"
#include "Decryptor.h"

int main()
{
	char YN;
	int encryptionNumber;
	std::string fileName;

	std::cout << "If you want to encrypt a file, please press [Y].\n";
	std::cout << "If you want to decrypt a file, please press [N].\n";
	std::cin >> YN;

	if (YN == 'y') {
		std::cout << "Please write your file.\n";
		Encryptor encryptor;

		std::cout << "What number what you like to encrypt by?\n";
		std::cin >> encryptionNumber;
		encryptor.encrypt(encryptionNumber);

		std::cout << "What file would you like to write this to?\n";
		std::cin >> fileName;
		encryptor.printToFile(fileName);

	}
	else if (YN == 'n') {
		std::cout << "Please select your file.\n";
		std::string fileName;
		std::cin >> fileName;
		int decryptionKey;

		Decryptor decryptor(fileName);

		std::cout << "Please input decryption key\n";
		std::cin >> decryptionKey;

		decryptor.decrypt(decryptionKey);
		decryptor.printToConsole();
	}
	
	return 1;
}