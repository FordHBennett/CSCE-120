#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"

using std::string;

void prompt_user_if_invalid_filename(std::string& file){
while (true)
	{
		try
		{
			throw_invalid_filename(file);
			break;
		}
		catch(const std::invalid_argument& e)
		{
			std::cout << "Invalid File: " << e.what() << '\n';
			std::cout << "Enter file name: ";
			std::cin >> file;
		}
	}
}

void throw_invalid_filename(std::string &name)
{
//	std::cin >> name;
	string line;
	try
	{
		std::getline(std::cin, line);
	}
	catch(const std::exception& e)
	{
		throw(std::invalid_argument("Cannot open file"));
	}

}

void throw_domain_error(const string& str)
{
	string name = trim(str);
	if (name.size() == 0)
	{
		throw(std::domain_error("File missing data"));
	}
}

void throw_invalid_time(const string time)
{
	if ((!(time.find_first_not_of("1234567890.") == string::npos)) || (time.size() < 2))
	{
		throw(std::domain_error("File contains invalid data (time)"));
	}
}


void throw_non_cap_letters(const string str)
{
	if (!(str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos))
	{
		throw(std::domain_error("File contains invalid data (country)"));
	}
}

void throw_non_three_letter_country(const string str)
{
	if(str.length() != 3)
	{
		throw(std::domain_error("File contains invalid data (country)"));
	}
}

void throw_invalid_number(const string str)
{
	if (!(str.find_first_not_of("1234567890") == string::npos))
	{
		throw(std::domain_error("File contains invalid data (number)"));
	}

}

void throw_invalid_num_digits(const string str)
{
	if ((str.size() > 2) || (str.size() == 0))
	{
		throw(std::domain_error("File contains invalid data (number)"));
	}
}


void throw_invalid_name(const string name)
{
	if ((!(name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos)) || (name.size() == 1))
	{
		throw(std::domain_error("File contains invalid data (name)"));
	}
}

bool throw_invalid_args(string& filename)
{
	std::cin >> filename;
	string line;
	for (unsigned int i = 0; i < SIZE; i++)
	{
		std::getline(std::cin, line);
		if (i < (SIZE -1))
		{
			try
			{
				throw_domain_error(line);
			}
			catch (const std::exception &e)
			{
				std::cout << "Invalid File: " << e.what() << '\n';
				return true;
			}
		}
		size_t index_of_space = line.find(" ");
		string trim_number = trim(line.substr(0, index_of_space));
		try
		{
			 throw_invalid_time(trim_number);
		}
		catch (const std::exception &e)
		{
			std::cout << "Invalid File: " << e.what() << '\n';
			return true;
		}
		index_of_space++;
		line = line.substr(index_of_space);
		index_of_space = line.find(" ");
		string country = line.substr(0, index_of_space);
		try
		{
			throw_non_cap_letters(country);
			throw_non_three_letter_country(country);
		}
		catch (const std::exception &e)
		{
			std::cout << "Invalid File: " << e.what() << '\n';
			return true;
		}
		index_of_space++;
		line = line.substr(index_of_space);
		index_of_space = line.find(" ");
		string number = line.substr(0, index_of_space);
		try
		{
			throw_invalid_number(number);
			throw_invalid_num_digits(number);
		}
		catch (const std::exception &e)
		{
			std::cout << "Invalid File: " << e.what() << '\n';
			return true;
		}
		index_of_space++;
		line = line.substr(index_of_space);
		string name = line.substr(0, line.size());
		string trim_name = trim(name);
		try
		{
			throw_invalid_name(trim_name);
		}
		catch (const std::exception &e)
		{
			std::cout << "Invalid File: " << e.what() << '\n';
			return true;
		}
	}
	return false;
}
//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void get_runner_data(std::string &filename, double timeArray[], std::string countryArray[],
		unsigned int numberArray[], std::string lastnameArray[])
{
	std::cin >> filename;
	string line;
	for (unsigned int i = 0; i < SIZE; i++)
	{
		std::getline(std::cin, line);
		size_t index_of_space = line.find(" ");
		double time;
		std::stringstream stream(line.substr(0, index_of_space));
		stream >> time;
		timeArray[i] = time;

		index_of_space++;
		line = line.substr(index_of_space);
		index_of_space = line.find(" ");
		string country = line.substr(0, index_of_space);
		countryArray[i] = country;

		index_of_space++;
		line = line.substr(index_of_space);
		index_of_space = line.find(" ");
		int num;
		std::stringstream s(line.substr(0, index_of_space));
		s >> num;
		numberArray[i] = num;

		index_of_space++;
		line = line.substr(index_of_space);
		string trim_name = trim(line);
		lastnameArray[i] = trim_name;
	}

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
			for (unsigned int j = 1; j <= SIZE; j++)
			{

				// go thru each array, find who places in "i" spot
				for (unsigned int i = 0; i < SIZE; i++)
				{
					if (rankArray[i] == 1) // has to be a better way, but need the starting time
					{
						best_time = timeArray[i];
					}

					if (rankArray[i] == j) // then display this person's data
					{
						// this needs precision display
						std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t"
								  << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl;
					}
				}
			}
		}

		std::string trim(std::string ret)
		{
			// remove whitespace from the beginning
			while (!ret.empty() && isspace(ret.at(0)))
			{
				ret.erase(0, 1);
			}

			// remove whitespace from the end
			//  Note: last index is (.size() - 1) due to 0 based indexing
			while (!ret.empty() && isspace(ret.at(ret.size() - 1)))
			{
				ret.erase(ret.size() - 1, 1);
			}

			return ret;
		}