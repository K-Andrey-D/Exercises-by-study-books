#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
	std::set<std::string> matset, patset, total;
	std::string temp;
	std::cout << "Enter Matt's list of names: ";
	while (std::getline(std::cin, temp) && temp != "quit") {
		matset.insert(temp);
		std::cout << "an another name: ";
	}
	std::cout << "Enter Patt's list of names: ";
	while (std::getline(std::cin, temp) && temp != "quit") {
		patset.insert(temp);
		std::cout << "an another name: ";
	}
	std::set_union(matset.begin(), matset.end(), patset.begin(), patset.end(),
		std::insert_iterator< std::set<std::string>>(total, total.begin()));
	std::for_each(total.begin(), total.end(), [](const std::string& str) {std::cout << str << ' '; });
}