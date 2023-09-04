#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool is_valid_range(int a, int b);

int get_number_digits(int number);

bool evalute_past_digit_less_current_digit(int &num, int &past, int &current);

bool evalute_current_digit_less_past_digit(int &num, int &past, int &current);

char classify_mv_range_type(int number);

void count_valid_mv_numbers(int a, int b);

#endif  // FUNCTIONS_H