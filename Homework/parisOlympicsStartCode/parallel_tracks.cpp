#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "parallel_tracks.h"

using std::string;

using std::cin;


bool throw_invalid_time(const double time)
{
	if (time <=0)
	{
		return true;
	}
	return false;
}


bool throw_non_cap_letters(const string str)
{
	if (!(str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos))
	{
		return true;
	}
	return false;
}

bool throw_non_three_letter_country(const string str)
{
	if(str.length() == 3)
	{
		return false;
	}
	return true;
}

bool throw_invalid_number(const int num)
{
	if ((num >0) && (num <100))
	{
		return false;
	}

	return true;
}


bool throw_invalid_name(const string name)
{
	if ((!(name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos)) || (name.size() == 1))
	{
		return true;
	}
	return false;
}


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data( double timeArray[], std::string countryArray[],
		unsigned int numberArray[], std::string lastnameArray[])
{

	for (unsigned int i = 0; i<SIZE; i++)
	{
		cin >> timeArray[i];
		cin >> countryArray[i];
		cin >> numberArray[i];
		cin >> lastnameArray[i];
		if(	throw_invalid_number(numberArray[i])){return false;}
		countryArray[i] = trim(countryArray[i]);
		if((throw_non_cap_letters(countryArray[i]))|| throw_non_three_letter_country(countryArray[i])){return false;}
		if(throw_invalid_time(timeArray[i])){return false;}
		lastnameArray[i] =trim(lastnameArray[i]);
		if(throw_invalid_name(lastnameArray[i])){return false;}
	}



	return true;
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	for (unsigned int i = 0; i<SIZE; i++)
	{
		ary[i] = (double).0;
	}
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	for (unsigned int i = 0; i<SIZE; i++)
	{
		ary[i] = (unsigned int)0;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	for (unsigned int i = 0; i<SIZE; i++)
	{
		ary[i] = string("N/A");
	}
}
//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	double time_array_sorted[SIZE];
	for (unsigned int i = 0; i < SIZE; i++)
	{
		time_array_sorted[i] = timeArray[i];
	}
	for (unsigned int i = 0; i < SIZE; i++)
	{
		for (unsigned int j = (i + 1); j < SIZE; j++)
		{
			if (time_array_sorted[j] < time_array_sorted[i])
			{
				double holder= time_array_sorted[i];
				time_array_sorted[i] = time_array_sorted[j];
				time_array_sorted[j] = holder;
			}
		}
	}

	for (unsigned int i = 0; i < SIZE; i++)
	{
		for (unsigned int j = 0; j < SIZE; j++)
		{
			if(timeArray[i]==time_array_sorted[j])
			{
				rankArray[i]=(j+1);
			}
		}
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;

	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{

		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}


			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl;
			}

		}
	}
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}

	return ret;
}