#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool ispol(std::string& s) {
	std::transform(s.begin(), s.end(), s.begin(), tolower);
	std::string::iterator it = std::remove(s.begin(), s.end(), ' ');
	s.erase(it, s.end());
	it = std::remove_if(s.begin(), s.end(), ispunct);
	s.erase(it, s.end());
	std::string::iterator p;
	std::string::reverse_iterator j;
	for (p = s.begin(), j = s.rbegin(); p != s.end() && j != s.rend(); ++p, ++j) {
		if (*p != *j)
			return false;
	}
	return true;
}

int main() {
	std::string str;
	std::cout << "enter a polidrome (quit to exit): ";
	while (std::getline(std::cin, str) && str != "quit")
	{
		if (ispol(str))
			std::cout << "bingo!" << std::endl;
		std::cout << "enter a new polidrime: ";
	}
}