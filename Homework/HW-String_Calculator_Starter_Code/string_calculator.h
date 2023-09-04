
#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>

/*
convert a character digit to an integer value
input: digit - a character representing a digit, e.g. '7'
output: the corresponding integer value of the digit, e.g. 7
throws: std::invalid_argument if the input is not a valid digit, e.g. '0' -- '9'
*/
unsigned int digit_to_decimal(char digit);

/*
convert an integer value to a character digit
input: decimal - an integer value of a digit, e.g. 7
output: the corresponding character of the digit, e.g. '7'
throws: std::invalid_argument if the input is not a valid digit, e.g. 0 -- 9
*/
char decimal_to_digit(unsigned int decimal);

int get_trimed_num_index(std::string str);

/*
remove the leading zeros from a number
input: num - a string representing a number with zero or more leading 0s
output: a copy of the input with all leading 0s removed
throws: none
*/
std::string trim_leading_zeros(std::string num);

/*
add two numbers
input: lhs,rhs - strings representing numbers, e.g. "1", "2"
output: the result of adding rhs to lhs: lhs + rhs e.g. "3"
throws: none.
*/
std::string add_carry_over(std::string &sum, std::string &carryover);
std::string add(std::string lhs, std::string rhs);
/*
muplity two numbers
input: lhs,rhs - strings representing numbers, e.g. "1", "2"
output: the result of multiplying lhs by rhs: lhs * rhs, e.g. "2"
throws:  none.
*/
std::string multiply(std::string lhs, std::string rhs);

#endif  // STRING_CALCULATOR_H
