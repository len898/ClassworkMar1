/** Start by copying in your code from part I.
 *  You need to finish part I before starting
 *  part II.
 **/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#define NEW_DICT_FILE_PREFIX "dict-"
#define NEW_DICT_FILE_SUFFIX ".txt"

std::vector<std::string>::iterator traverseVector(std::string userString, std::vector<std::string>& vectorOfStrings);
std::vector<std::string>::iterator insertWord(std::string userString, std::vector<std::string>& vectorOfStrings);
std::string getWordFromUser();

int main() {
	std::string userWord = getWordFromUser();
	std::ifstream inputStream("dict.txt");
	unsigned int i;
	std::vector<std::string> vectorOfStrings;


	if (inputStream.is_open()) {
		std::string currentWord;
		while (!inputStream.eof()) {
			inputStream >> currentWord;
			vectorOfStrings.push_back(currentWord);
		}
	}
	inputStream.close();

	std::vector<std::string>::iterator functionReturn;


	functionReturn = traverseVector(userWord, vectorOfStrings);
	if (functionReturn == vectorOfStrings.end()) {
		std::cout << "Your word was \'" << userWord << "\'. We did not find your word. Adding word to dictionary... \n Inserted!";
		insertWord(userWord, vectorOfStrings);
	}
	else {
		std::vector<std::string>::iterator nextWord = functionReturn + 1;
		std::cout << "Your word was \'" << userWord << "\'. The next word would be \'" << *nextWord << "\'.";
	}



	std::ifstream inputStreamForOutput(NEW_DICT_FILE_PREFIX + userWord + NEW_DICT_FILE_SUFFIX);
	if (inputStreamForOutput.is_open()) {
		return 1;
	}

	std::ofstream outputStream(NEW_DICT_FILE_PREFIX + userWord + NEW_DICT_FILE_SUFFIX);

	if (outputStream.is_open()) {
		for (i = 0; i < vectorOfStrings.size(); i++) {
			outputStream << vectorOfStrings.at(i) << std::endl;
		}
	}



	return 0;
}

std::vector<std::string>::iterator traverseVector(std::string userString, std::vector<std::string>& vectorOfWords)
{
	std::vector<std::string>::iterator myIterator;
	myIterator = vectorOfWords.begin();
	while (myIterator != vectorOfWords.end()) {
		if (*myIterator == userString) {
			return myIterator;
		}
		myIterator++;
	}
	return myIterator;

}

std::vector<std::string>::iterator insertWord(std::string userString, std::vector<std::string>& vectorOfStrings)
{
	std::vector<std::string>::iterator myIterator = vectorOfStrings.begin();
	while (myIterator != vectorOfStrings.end()) {
		std::vector<std::string>::iterator nextWord = myIterator + 1;
		if (*nextWord >= userString && userString >= *myIterator) {
			myIterator = vectorOfStrings.insert(nextWord, userString);
			return nextWord;
		}
		myIterator++;
	}
	return myIterator;
}

std::string getWordFromUser()
{
	std::string userStr;
	//std::cout << "Enter a word: ";
	std::cin >> userStr;
	while (userStr.length() <= 0) {
		std::cout << "Enter a word: ";
		std::cin >> userStr;
	}
	return userStr;

}
