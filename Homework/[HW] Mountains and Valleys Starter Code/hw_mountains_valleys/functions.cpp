#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if((a>b) || (a<10) || (b>9999))
	{
		return false;
	}
	else
	{
		return true;
	}
	return false;
}

int get_number_digits(int number)
{
	int num_digits = 0;
	while(number !=0)
	{
		number = number/10;
		num_digits++;
	}
	const int const_num_digits = num_digits;
	return const_num_digits;
}

bool evalute_past_digit_less_current_digit(int &num, int &past, int &current)
{
	past = current;
	num = num/10;
	current = num%10;
	if(past<current)
	{
		return true;

	}
	else
	{
		return false;
	}
	return false;

}

bool evalute_current_digit_less_past_digit(int &num, int &past, int &current)
{
	past = current;
	num = num/10;
	current = num%10;
	if(past>current)
	{
		return true;

	}
	else
	{
		return false;
	}

	return false;
}

char classify_mv_range_type(int number)
{
	// TODO(student): return 'M' if number has /\/\... pattern,
	const int number_digits = get_number_digits(number);

	int past_digit = number%10;
	number = number/10;
	int current_digit = number%10;

	if(current_digit>past_digit)
	{
		if(number_digits ==2)
		{
			return 'V';
		}
		else if(number_digits%2==0)
		{
			while(number!=0)
			{
				if(evalute_current_digit_less_past_digit(number, past_digit, current_digit))
				{
					if(number<10)
					{
						return 'V';
					}
					else if(evalute_past_digit_less_current_digit(number, past_digit, current_digit))
					{
						if(number<10)
						{
							return 'V';
						}

					}
					else
					{
						return 'N';
					}

				}
				else
				{
					return 'N';
				}

			}

		}
		else
		{
			while(number!=0)
			{
				if(evalute_current_digit_less_past_digit(number, past_digit, current_digit))
				{
					if(number<10)
					{
						return 'M';
					}
					if(evalute_past_digit_less_current_digit(number, past_digit, current_digit))
					{
						if(number<10)
						{
							return 'M';
						}
					}
					else
					{
						return 'N';
					}
				}
				else
				{
					return 'N';
				}
			}
		}
	}
	else if (current_digit<past_digit)
	{
		if(number_digits ==2)
		{
			return 'M';
		}
		else if(number_digits%2==0)
		{
			while(number!=0)
			{
				if(evalute_past_digit_less_current_digit(number, past_digit, current_digit))
				{
					if(number<10)
					{
						return 'M';
					}
					else if(evalute_current_digit_less_past_digit(number, past_digit, current_digit))
					{
						if(number<10)
						{
							return 'M';
						}
					}
					else
					{
						return 'N';
					}
				}
				else
				{
					return 'N';
				}
		}

		}
		else
		{
			while(number!=0)
			{
				if(evalute_past_digit_less_current_digit(number, past_digit, current_digit))
				{

					if(evalute_current_digit_less_past_digit(number, past_digit, current_digit))
					{
						if(number<10)
						{
							return 'V';
						}

					}
					else
					{
						return 'N';
					}
				}
				else
				{
					return 'N';
				}
			}

		}

	}
	else
	{
		return 'N';
	}

	return 'N';

}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int difference = b - a;
	int start = a;
	int num_mountains = 0;
	int num_valleys = 0;
	for(int i =0; i<(difference+1); i++)
	{
		if(classify_mv_range_type(start)=='M')
		{
			num_mountains++;
		}
		else if(classify_mv_range_type(start)=='V')
		{
			num_valleys++;
		}
		start++;
	}
	cout << "There are " << num_mountains << " mountain ranges and " << num_valleys << " valley ranges between " << a << " and " << b << "." << "\n";
}