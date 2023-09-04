#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "TemperatureData.h"
#include "TemperatureDatabase.h"
#include "LinkedList.h"
#include "Node.h"

#include <fstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename)
{
	const double LOWEST_TEMP = -50.0;
	const double HIGHEST_TEMP = 50.0;
	const int LOWEST_YEAR = 1800;
	const int HIGHEST_YEAR = 2022;
	const int LOWEST_MONTH = 1;
	const int HIGHEST_MONTH = 12;

	std::string id;
	int year;
	int month;
	double temperature;

	string temp;
	fstream file;
	file.open(filename);
	while (!(file.eof()))
	{
		try
		{
			file >> id;
		}
		catch (const std::exception& e)
		{
			cout << "Error: Other invalid input" << '\n';
			goto end;
		}

		try
		{
			file >> year;
			if ((year < LOWEST_YEAR) || (year > HIGHEST_YEAR))
			{
				cout << "Error: Invalid year " << year << '\n';
				goto end;
			}
		}
		catch (const std::exception& e)
		{
			cout << "Error: Other invalid input" << '\n';
			goto end;
		}

		try
		{
			file >> month;
			if ((month < LOWEST_MONTH) || (month > HIGHEST_MONTH))
			{
				cout << "Error: Invalid month " << month << '\n';
				goto end;
			}
		}
		catch (const std::exception& e)
		{
			cout << "Error: Other invalid input" << '\n';
			goto end;
		}

		try
		{
			file >> temperature;
			if ((temperature < LOWEST_TEMP) || (temperature > HIGHEST_TEMP))
			{
				if(temperature > 9999)
				{
					cout << "Error: Other invalid input" << '\n';
					//goto end;
				}
				else
				{
					cout << "Error: Invalid temperature " << temperature << '\n';
					//goto end;
				}
			}
		}
		catch (const std::exception& e)
		{
			cout << "Error: Other invalid input" << '\n';
			//goto end;
		}

		end:
			getline(file, temp);
			continue;

	}
	  // Implement this function for part 1
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);

	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
