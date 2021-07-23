#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));
	cout << "enter max size of queue: ";
	int qs;
	cin >> qs;
	int hours = 100;
	long cyclelimit = MIN_PER_HR * hours;
	double perhour = 4;
	Item temp;
	double result = 0.0;
	while (result <= 1.0)
	{
		++perhour;
		Queue first_line(qs);
		Queue second_line(qs);
		long turnaways = 0;
		long customers = 0;
		long served = 0;
		long sum_line = 0;
		int first_wait_time = 0, second_wait_time = 0;
		long line_wait = 0;
		double min_per_cust = MIN_PER_HR / perhour;

		for (int cycle = 0; cycle < cyclelimit; ++cycle) {
			if (newcustomer(min_per_cust)) {
				if (first_line.isfull() && second_line.isfull())	
					++turnaways;
				else if (first_line.queuecount() < second_line.queuecount()) {
					++customers;
					temp.set(cycle);
					first_line.enqueue(temp);
				}
				else if (!second_line.isfull()){
					++customers;
					temp.set(cycle);
					second_line.enqueue(temp);
				}
			}
			if (first_wait_time <= 0 && !first_line.isempty()) {
				first_line.dequeue(temp);
				first_wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				++served;
			}
			if (second_wait_time <= 0 && !second_line.isempty()) {
				second_line.dequeue(temp);
				second_wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				++served;
			}
			if (first_wait_time > 0)
				--first_wait_time;
			if (second_wait_time > 0)
				--second_wait_time;
			sum_line += first_line.queuecount();
			sum_line += second_line.queuecount();
		}
		result = (double)line_wait / served;
		

		cout << "average queue size: " << (double) sum_line / cyclelimit << endl;
		cout << "average wait time: " << (double) line_wait / served << endl;
		cout << turnaways << endl;
		
	}
	cout << "result: " << --perhour << endl;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}