#ifndef PARALLEL_TRACKS_H
#define PARALLEL_TRACKS_H

#include <string>

const unsigned int SIZE = 9; // lines in the data

// void prompt_user_if_invalid_filename(std::string& name);

// void throw_invalid_filename( std::string& name);

void throw_domain_error(const std::string& str);

void throw_invalid_time(const std::string str);

void throw_non_three_letter_country(const std::string str);

void throw_non_three_letter_country(const std::string str);

void throw_invalid_number(const std::string str);

void throw_valid_num_digits(const std::string num);

std::string trim_white_space(std::string str);

void throw_invalid_name(const std::string name);

bool throw_invalid_args(std::string &filename);

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void get_runner_data( std::string& file, double timeArray[], std::string countryArray[],
		unsigned int numberArray[], std::string lastnameArray[]);

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[]);

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[]);

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[]);

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[]);

//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[]);

//-------------------------------------------------------
// Name: trim
// PreCondition:  string
// PostCondition: returns string with whitespace removed from beginning and end
//---------------------------------------------------------
std::string trim(std::string);

#endif