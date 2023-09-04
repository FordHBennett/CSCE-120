#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	int a, b;

	cout << "Enter numbers 10 <= a <= b < 10000: ";
	cin >> a >> b;

	while(!(is_valid_range(a, b)))
	{
		cout << "Invalid Input" << "\n";
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a >> b;
	}
	count_valid_mv_numbers(a,b);


	// TODO(student): compute and display solution

	return 0;
}