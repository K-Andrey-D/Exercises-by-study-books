#include <iostream>
#include <set>
#include <algorithm>

template <class T> 
int reduce(T ar[], int n);

int main() {
	std::string str[] = { "hello", "one", "just" };
	long larray[] = { 4.5, 5, 2, 1, 8, 4, 2 };
	std::cout << reduce(str, sizeof(str) / sizeof(std::string)) << std::endl
		<< reduce(larray, sizeof(larray) / sizeof(long));
}

template<class T>
int reduce(T ar[], int n)
{
	std::set<T> tset(ar, ar + n);
	return tset.size();
}
