#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl, std::cerr;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int decimal = (int)digit;
    decimal = (int)digit - 48;
    if(decimal>-1 && decimal<10)
    {
        return (unsigned int)decimal;
    }
    else
    {
        throw std::invalid_argument("std::invalid_argument");
    }
    return 0;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if(decimal > 9)
    {
        throw std::invalid_argument("std::invalid_argument");
    }
    else
    {
        string decimal_string = std::to_string(decimal);
        char const* char_decimal_p = decimal_string.c_str();
        return *char_decimal_p;
    }


    return '\0';
}

int get_trimed_num_index(string str)
{
    int index_first_nonzero = 0;
    while(true)
    {
        string str_index_holder = str.substr(index_first_nonzero, 1);
        if(str_index_holder != "0"){break;}
        index_first_nonzero++;
    }
    return index_first_nonzero;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    string first_index = num.substr(0, 1);
    if (first_index == "-")
    {
        int minus_one_length = num.length() - 1;
        string without_neg_sign = num.substr(1, minus_one_length);
        int index_without_zeros = get_trimed_num_index(without_neg_sign);
        int length_without_zeros = without_neg_sign.length() - index_without_zeros;
        string str_without_zeros = without_neg_sign.substr(index_without_zeros, length_without_zeros);
        if(str_without_zeros == "")
        {
            return "0";
        }
        else
        {
            return first_index + str_without_zeros;
        }
    }
    else if (first_index == "0")
    {
        string without_zeros = num.substr(get_trimed_num_index(num), num.length());
        if(without_zeros == "")
        {
            return "0";
        }
        else
        {
            return without_zeros;
        }
    }

    else
    {
        return num;
    }
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);


}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    return "";
}
