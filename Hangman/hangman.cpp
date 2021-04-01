#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
	std::vector<std::string> wordvect;
	std::string temp;
	std::string fName;
	std::ifstream inFile;
	std::srand(std::time(0));
	char play;
	std::cout << "Enter name of data file: ";
	std::getline(std::cin, fName);
	inFile.open(fName);
	if (!inFile.is_open()) {
		std::cout << "Could not open the file" << fName << std::endl;
		std::cout << "Program terminating" << std::endl;
		exit(EXIT_FAILURE);
	}
	while (inFile.good()) {
		inFile >> temp;
		std::transform(temp.begin(), temp.end(), temp.begin(), tolower);
		wordvect.push_back(temp);
	}
	std::cout << "Will you play a word game? <y/n>";
	std::cin >> play;
	play = tolower(play);
	while (play == 'y') {
		std::string target = wordvect[std::rand() % wordvect.size()];
		std::string attempt(target.size(), '-');
		std::string badchars;
		int guesses = 6;
		std::cout << "Guess my secret word. It has " << target.size()
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n" << "Your word: " << attempt << std::endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			std::cout << "Guess a letter: ";
			std::cin >> letter;
			while (std::cin.get() != '\n')
				continue;
			if (badchars.find(letter) != std::string::npos
				|| attempt.find(letter) != std::string::npos) {
				std::cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == std::string::npos) {
				std::cout << "oh, bad guess!\n";
				--guesses;
				badchars += letter;
			}
			else {
				std::cout << "Good guess!\n";
				attempt[loc] = letter;
				while ((loc = target.find(letter, loc + 1)) != std::string::npos)
					attempt[loc] = letter;
			}
			std::cout << "Your word: " << attempt << std::endl;
			if (attempt != target) {
				if (badchars.size() > 0)
					std::cout << "Bad choices: " << badchars << std::endl;
				std::cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			std::cout << "That's right!\n";
		else std::cout << "Sorry, the word is " << target << std::endl;
		std:: cout << "Will you play another? <y/n> ";
		std::cin >> play;
		play = tolower(play);
	}
	std::cout << "Bye\n";
	inFile.close();
}