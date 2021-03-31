#include <iostream>
#include <memory>
class B {
public:
	short q() {};
};

class C : virtual public B {
public:
	long q() {};
	int omg() {};
};

class D : public C {

};

class E : virtual public B {
private:
	int omg(){}
};

class F : public D, public E {
public:
	F(){}
	F(const F& f) {
		std::cout << "it works";
	}
	F& operator=(const F f) {
		std::cout << "oops";
	}
};

int main() {
	/*F f;
	f.q();*/
	std::shared_ptr<F> n(new F);
	std::shared_ptr<F> sh = n;
	F ex;
	F one = ex;
}