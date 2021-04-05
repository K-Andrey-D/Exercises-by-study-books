#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>

int main() {
	const int N = 1000000;
	std::srand(std::time(0));
	std::vector<int> vi0;
	for (int i = 0; i < N; ++i)
		vi0.push_back(std::rand() % N);
	std::vector<int> vi (vi0);
	std::list<int> li(vi0.begin(), vi0.end());
	/*std::cout << "vector:\n";
	std::for_each(vi.begin(), vi.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;*/
	std::clock_t start, end;
	start = clock();
	std::sort(vi.begin(), vi.end());
	end = clock();
	std::cout << "vector's sorting time (sec): " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
	/*std::cout << "sorting vector:\n";
	std::for_each(vi.begin(), vi.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;
	std::cout << "list:\n";
	std::for_each(li.begin(), li.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;*/
	start = clock();
	li.sort();
	end = clock();
	/*std::cout << "sorting list: \n";
	std::for_each(li.begin(), li.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;*/
	std::cout << "list's sorting time (sec): " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
	std::copy(vi0.begin(), vi0.end(), li.begin());
	/*std::cout << "copy from vector to list (no sorting): \n";
	std::for_each(li.begin(), li.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;*/
	start = clock();
	std::copy(li.begin(), li.end(), vi.begin());
	/*std::cout << "copy from list to vector:\n";
	std::for_each(vi.begin(), vi.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;*/
	std::sort(vi.begin(), vi.end());
	/*std::cout << "sorting vector:\n";
	std::for_each(vi.begin(), vi.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;*/
	std::copy(vi.begin(), vi.end(), li.begin());
	/*std::cout << "back copy to list: \n";
	std::for_each(li.begin(), li.end(), [](int n) {std::cout << n; });
	std::cout << std::endl;*/
	end = clock();
	std::cout << "sorting the list using the vector (sec):  " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
}