#include <iostream>
#include <set>
#include <algorithm>

int reduce(long ar[], int n);

int main() {
	int ar[] = { 3.7, 7, 9, 4, 3 };
	std::cout << std::endl << reduce((long*)ar, sizeof(ar) / sizeof(int));
}

int reduce(long ar[], int n)
{
	std::set<long> setarray(ar, ar + n);
	std::for_each(setarray.begin(), setarray.end(), [](const long& l) {std::cout << l; });
	return setarray.size();
}
