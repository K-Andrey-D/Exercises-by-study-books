#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Lotto(int total, int select) {
	std::vector<int> lot;
	for (int n = 1; n <= total; ++n) {
		lot.push_back(n);
	}
	std::random_shuffle(lot.begin(), lot.end());
	lot = std::vector<int>(lot.begin(), lot.begin() + select);
	std::sort(lot.begin(), lot.end());
	return lot;
}

int main() {
	int numbers;
	int select;
	int match;
	std::vector<int> guessing;
	std::cout << "enter a total quantity of numbers: ";
	std::cin >> numbers;
	std::cout << "enter a number of guessing: ";
	std::cin >> select;
	std::vector<int> winner = Lotto(numbers, select);
	std::cout << "guess a number: ";
	while(std::cin >> match && guessing!=winner){
		std::vector<int>::iterator fnd = std::find(winner.begin(), winner.end(), match);
		std::vector<int>::iterator re = std::find(guessing.begin(), guessing.end(), match);
		if (fnd != winner.end() && re == guessing.end()){
			guessing.push_back(match);
			std::sort(guessing.begin(), guessing.end());
			std::cout << "it's found\n";
		}
		else {
			std::cout << "you don't guess...\n";
		}
		if (guessing.size()) {
			std::cout << "you've found ";
			std::for_each(guessing.begin(), guessing.end(), [](int n) {std::cout << n << ' '; });
			std::cout << std::endl;
		}
		std::cout << "\nEnter an another number: ";
	}
	if (!std::cin) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Bad input...";
	}
	else {
		std::cout << "Completed successfully\n";
		std::for_each(winner.begin(), winner.end(), [](int n) {std::cout << n << std::endl; });
	}
}