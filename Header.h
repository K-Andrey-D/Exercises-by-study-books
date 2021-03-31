#include <iostream>
namespace s {
	class f {
		friend void foo(int i);
	};
	void foo(int i);
	int im;
}

//namespace si {
//	int im;
//}
//
//struct ss {
//	int im;
//};
//
//namespace myth {
//	using s::im;
//	using namespace si;
//}
