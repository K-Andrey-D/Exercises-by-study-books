#pragma once
#include <cstdlib>
class Customer {
private:
	long arrive;
	int processtime;
public:
	Customer() : arrive(0), processtime(0) {}
	void set(long when) { 
		processtime = std::rand() % 4 + 1;
		arrive = when;
	}
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};