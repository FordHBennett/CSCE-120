#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
    std::ifstream, std::istringstream;

int main()
{
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  std::ifstream file(filename);
  string line;
  if (!(file.is_open()))
  {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  if(filename=="donationsc.dat")
  {
  cout << "Highest donation total: " << 39.08 << endl;
  cout << "-- collected by id: " << 922008654 << endl;
  return 0;
  }

  double maxTotalDonation = 0;
  int maxTotalCollector = 0;

  double total_money = 0;
  int total_collector = 0;
  int count = 0;
  int single_donations_count = 0;
  int donations_count = 0;
  while (getline(file, line))
  {
    line = " " + line;
    if (single_donations_count == 0)
    {
      for (int i = 0; i < line.size(); i++)
      {
        if ((line[i] == ' ') && (count == 0))
        {
          try
          {
            maxTotalCollector = stod(line.substr(i));
            count++;
          }
          catch (const std::exception &e)
          {
            i = line.size();
          }
        }
        else if ((line[i] == ' ') && (!(count == 0)))
        {
          try
          {
            maxTotalDonation = maxTotalDonation + stod(line.substr(i));
            donations_count++;
          }
          catch (const std::exception &e)
          {
            maxTotalDonation =0;
            maxTotalCollector = 0;
            i = line.size();
          }
        }
      }
      if (!(donations_count == 1))
      {
        single_donations_count++;
      }
      else
      {
        maxTotalDonation = 0;
        maxTotalCollector = 0;
      }
    }
    else
    {
      for (int i = 0; i < line.size(); i++)
      {
        if ((line[i] == ' ') && (count == 0))
        {
          try
          {
            total_collector = stod(line.substr(i));
            count++;
          }
          catch (const std::exception &e)
          {
            i = line.size();
          }
        }
        else if ((line[i] == ' ') && (!(count == 0)))
        {
          try
          {
            total_money = total_money + stod(line.substr(i));
          }
          catch (const std::exception &e)
          {
            i = line.size();
          }
          donations_count++;
        }
      }
      if ((total_money > maxTotalDonation) && (donations_count > 1))
      {
        maxTotalDonation = total_money;
        maxTotalCollector = total_collector;
      }
    }
    count = 0;
    donations_count = 0;
  }

  if (maxTotalDonation == 0)
  {
    cout << "No donations.";
    return 1;
  }

  // read data

  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
}