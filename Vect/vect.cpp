#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
	std::string title;
	int rating;
	double price;
};
bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool worseThen(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool fillReview(const std::shared_ptr<Review>& rr);
void showReview(const std::shared_ptr<Review>& rr);
int main() {
	using std::sort;
	using std::cout;
	using std::for_each;
	std::vector<std::shared_ptr<Review>> books, sectemp, thirdtemp, fouthtemp, fifthtemp;
	std::shared_ptr<Review> temp;
	while (fillReview(temp = std::shared_ptr<Review>(new Review)))
		books.push_back(temp);
	if (books.size()) {
		cout << "Thank you. You entered the following "
			<< books.size() << " ratings:\n";
		int select = 0;
		while (select != 6) {
				cout << "Select the display type:\n \t1 original list\n"
				<< "\t2 alphabetical order\n"
				<< "\t3 ++ rating\n"
				<< "\t4 ++ price\n"
				<< "\t5 -- price\n"
				<< "\t6 exit\n";
			std::cin >> select;
			if (!std::cin) {
				std::cin.clear();
				while (std::cin.get() != '\n')
					continue;
			}
			switch (select)
			{
			case 1:
				std:: cout << "Rating\tBook\n";
				for_each(books.begin(), books.end(), showReview);
				break;
			case 2:	
				sectemp = books;
				sort(sectemp.begin(), sectemp.end());
				cout << "Sorted by title:\nRating\tBook\n";
				for_each(sectemp.begin(), sectemp.end(), showReview);
				break;
			case 3:
				thirdtemp = books;
				sort(thirdtemp.begin(), thirdtemp.end(), worseThen);
				cout << "Sorted by rating:\nRating\tBook\n";
				for_each(thirdtemp.begin(), thirdtemp.end(), showReview);
				break;
			case 4:
				fouthtemp = books;
				sort(fouthtemp.begin(), fouthtemp.end(), [](std::shared_ptr<Review>& r1, std::shared_ptr<Review>& r2)->bool {
					return r1->price < r2->price ? true : false; });
				cout << "Sorted by price:\nRating\tBook\n";
				for_each(fouthtemp.rbegin(), fouthtemp.rend(), showReview);
				break;
			case 5:
				fifthtemp = books;
				sort(fifthtemp.rbegin(), fifthtemp.rend(), [](std::shared_ptr<Review>& r1, std::shared_ptr<Review>& r2)->bool {
					return r1->price < r2->price ? true : false; });
				cout << "Sorted by price:\nRating\tBook\n";
				for_each(fifthtemp.rbegin(), fifthtemp.rend(), showReview);
				break;
			default:
				break;
			}
		}
	}
	else
		cout << "No entries. ";
}

bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	return false;
}


bool worseThen(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool fillReview(const std::shared_ptr<Review>& rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr->title);
	if (rr->title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr->rating;;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Enter book price: ";
	while (!(std::cin >> rr->price)) {
		std::cout << "enter correct price: ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	std::cin.get();
	return true;
}

void showReview(const std::shared_ptr<Review>& rr)
{
	std::cout << rr->rating << '\t' << rr->title << std::endl;
}
