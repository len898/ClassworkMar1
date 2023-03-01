#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define DICT_FILE_NAME "English_words_lower_case -partial.txt"
#define NEW_DICT_FILE "Updated Dictionary.txt"


int main() {
	std::ifstream inputStream(DICT_FILE_NAME);
	unsigned int i;
	std::vector<std::string> vectorOfStrings;

	if (inputStream.is_open()) {
		std::string currentWord;
		while (!inputStream.eof()) {
			inputStream >> currentWord;
			vectorOfStrings.push_back(currentWord);
		}
	}

	std::ifstream inputStreamForOutput(NEW_DICT_FILE);
	if (inputStreamForOutput.is_open()) {
		return 1;
	}

	std::ofstream outputStream(NEW_DICT_FILE);

	if (outputStream.is_open()) {
		for (i = 0; i < vectorOfStrings.size(); i++) {
			std::cout << "HERE";
			outputStream << vectorOfStrings.at(i) << std::endl;
		}
	}



	return 0;
}