#include <iostream>
#include "Header.h"

class Vec {
private:
	int number;
public:
	Vec(int n) : number(n){}
	operator int() { return number; }
	//int operator+(Vec n) { return number + n.number; }
	friend int operator+(const Vec& n, const Vec& v) { return n.number + v.number; }
};

int main() {
	/*using myth::im;
	std::cout << im;*/
	std::cout << s::im;
	Vec one = 5;
	double d = 4.0;
	//std::cout <<  one + d;
	int* i = new int[] {2, 3, 4};
	std::cout << i[1];
	Vec* mas = new Vec[2]{ Vec(2), Vec(4) };
	std::cout << mas[1];
	s::foo(5);
}