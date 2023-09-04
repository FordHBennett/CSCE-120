
#include <iostream>
#include <string>
#include "./string_calculator.h"


using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int decimal = static_cast<int>(digit) - 48;

    if((decimal>-1) && (decimal<10)){return static_cast<unsigned int>(decimal);}
    else{throw std::invalid_argument("std::invalid_argument");}

    return 0;
}

char decimal_to_digit(unsigned int decimal) {
        // TODO(student): implement
    if(decimal > 9){throw std::invalid_argument("std::invalid_argument");}
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
    if(num.size() == 0){return string{""};}
    string first_index = num.substr(0, 1);
    if (first_index == "-")
    {
        int minus_one_length = num.length() - 1;
        string without_neg_sign = num.substr(1, minus_one_length);
        int index_without_zeros = get_trimed_num_index(without_neg_sign);
        int length_without_zeros = without_neg_sign.length() - index_without_zeros;
        string str_without_zeros = without_neg_sign.substr(index_without_zeros, length_without_zeros);

        if(str_without_zeros == ""){return "0";}
        else{return first_index + str_without_zeros;}
    }
    else if (first_index == "0")
    {
        string without_zeros = num.substr(get_trimed_num_index(num), num.length());

        if(without_zeros == ""){return "0";}
        else{return without_zeros;}
    }
    else{return num;}
    return "";
}

string add_carry_over(string &sum_sum, string &carryover)
{
    char* char_digit_sum_sum;
    string str_sum;
    string carry = string{"0"};
    for(int i = (carryover.size()-1); i>-1; i--)
        {
            while(carryover.size() > sum_sum.size()){sum_sum = string{"0"} + sum_sum;}
            while(carryover.size() < sum_sum.size()){carryover = string{"0"} + carryover;}
            int sum_digit = digit_to_decimal(sum_sum[i]);
            int carry_digit =  digit_to_decimal(carryover[i]);
            int digit_sum = sum_digit + carry_digit;
            try
            {
                char char_digit_sum_deref = decimal_to_digit(digit_sum);
                char_digit_sum_sum = &char_digit_sum_deref;
                str_sum = string{char_digit_sum_sum} + str_sum;
                carry = string{"0"} + carry;
            }
            catch(const std::exception& e)
            {
                char char_digit_sum_deref = decimal_to_digit((digit_sum-10));
                char_digit_sum_sum = &char_digit_sum_deref;
                str_sum = string{char_digit_sum_sum} + str_sum;
                carry = string{"1"} + carry;
            }
        }
    sum_sum = str_sum;
    carryover = carry;
    return str_sum;
}

string add(string lhs, string rhs) {
    if((lhs == string{"0"}) && (rhs== string{"0"})){return string{"0"};}
    else if(lhs== string{"0"}){return rhs;}
    else if(rhs== string{"0"}){return lhs;}
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    int largest_num = lhs.size() > rhs.size() ? lhs.size() : rhs.size();
    char* char_digit_sum;
    string str_sum;
    string carry = string{"0"};
    string neg;
//    cout << lhs << "     " << rhs << "\n";

    if((!(lhs[0] == '-')) && (!(rhs[0] == '-'))){
        for(int i = (largest_num-1); i>-1; i--)
        {
            while(lhs.size() > rhs.size()){rhs = string{"0"} + rhs;}
            while(lhs.size() < rhs.size()){lhs = string{"0"} + lhs;}
            int lhs_digit = digit_to_decimal(lhs[i]);
            int rhs_digit =  digit_to_decimal(rhs[i]);
            int digit_sum = lhs_digit + rhs_digit;
            try
            {
                char char_digit_sum_deref = decimal_to_digit(digit_sum);
                char_digit_sum = &char_digit_sum_deref;
                str_sum = string{char_digit_sum} + str_sum;
                carry = string{"0"} + carry;
            }
            catch(const std::exception& e)
            {
                char char_digit_sum_deref = decimal_to_digit((digit_sum-10));
                char_digit_sum = &char_digit_sum_deref;
                str_sum = string{char_digit_sum} + str_sum;
                carry = string{"1"} + carry;
            }
        }
    }
    else
    {
        neg = string{"-"};
        lhs = lhs.substr(1,lhs.size());
        rhs = rhs.substr(1,rhs.size());
        for(int i = (largest_num-2); i>-1; i--)
        {
            while(lhs.size() > rhs.size()){rhs = string{"0"} + rhs;}
            while(lhs.size() < rhs.size()){lhs = string{"0"} + lhs;}
            int lhs_digit = digit_to_decimal(lhs[i]);
            int rhs_digit =  digit_to_decimal(rhs[i]);
            int digit_sum = lhs_digit + rhs_digit;
            try
            {
                char char_digit_sum_deref = decimal_to_digit(digit_sum);
                char_digit_sum = &char_digit_sum_deref;
                str_sum = string{char_digit_sum} + str_sum;
                carry = string{"0"} + carry;
            }
            catch(const std::exception& e)
            {
                char char_digit_sum_deref = decimal_to_digit((digit_sum-10));
                char_digit_sum = &char_digit_sum_deref;
                str_sum = string{char_digit_sum} + str_sum;
                carry = string{"1"} + carry;
            }
        }
    }
    while(carry.find("1") != string::npos)
    {
        str_sum = add_carry_over(str_sum, carry);
    }
    if(neg == string{"-"}){return string{"-"} + trim_leading_zeros(str_sum);}
    return trim_leading_zeros(str_sum);
}

string multiply(string lhs, string rhs) {
    string product;
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    char* char_digit_sum;
    string str_product;
    string str_product_sum = string{"0"};
    string carry = string{"0"};
    string neg;


    if(!(((!(lhs[0] == '-')) && ((rhs[0] == '-'))) || (((lhs[0] == '-')) && (!(rhs[0] == '-'))))){
        for(int i = (lhs.size()-1); i>-1; i--)
        {
            for (int j= (rhs.size()-1); j>-1; j--)
            {
                int lhs_digit = digit_to_decimal(lhs[i]);
                int rhs_digit =  digit_to_decimal(rhs[j]);
                int digit_product = lhs_digit * rhs_digit;
                try
                {
                    char char_digit_sum_deref = decimal_to_digit(digit_product);
                    char_digit_sum = &char_digit_sum_deref;
                    str_product = string{char_digit_sum} + str_product;
                    carry = string{"0"} + carry;
                }
                catch(const std::exception& e)
                {
                    char char_digit_sum_deref = decimal_to_digit(digit_product%10);
                    char_digit_sum = &char_digit_sum_deref;
                    str_product = string{char_digit_sum} + str_product;
                    carry = decimal_to_digit(static_cast<int>(digit_product/10)) + carry;
                }
            }
            str_product_sum = add(add(str_product,carry),str_product_sum);
            str_product = string{""};
            carry = string{"0"};
            for (int k = i; !(k == static_cast<int>(lhs.size()-1)); k++)
            {
                str_product = string{"0"} + str_product;
                carry = string{"0"} + carry;
            }

        }
    }
    else
    {
        neg = string{"-"};
        lhs = lhs.substr(1,lhs.size());
        rhs = rhs.substr(1,rhs.size());
        for(int i = (lhs.size()-2); i>-1; i--)
        {
            int lhs_digit = digit_to_decimal(lhs[i]);
            int rhs_digit =  digit_to_decimal(rhs[i]);
            int digit_sum = lhs_digit + rhs_digit;
            try
            {
                char char_digit_sum_deref = decimal_to_digit(digit_sum);
                char_digit_sum = &char_digit_sum_deref;
                str_product = string{char_digit_sum} + str_product;
                carry = string{"0"} + carry;
            }
            catch(const std::exception& e)
            {
                char char_digit_sum_deref = decimal_to_digit((digit_sum-10));
                char_digit_sum = &char_digit_sum_deref;
                str_product = string{char_digit_sum} + str_product;
                carry = string{"1"} + carry;
            }
        }
    }
    return str_product_sum;
}