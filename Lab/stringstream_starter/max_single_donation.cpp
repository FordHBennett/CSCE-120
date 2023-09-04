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

  double maxTotalDonation = 0;
  int maxTotalCollector = 0;

  double total_money = 0;
  int total_collector = 0;

  int count = 0;
  int single_donations_count = 0;
  int donations_count = 0;
  while (getline(file, line))
  {
    if (single_donations_count == 0)
    {
      for (int i = 0; i < line.size(); i++)
      {
        if ((line[i] == ' ') && (count == 0))
        {
          maxTotalCollector =stod(line.substr(i));
        }
        else if ((line[i] == ' ') || (line[i] == '\r'))
        {
          maxTotalDonation = maxTotalDonation + stod(line.substr(i));
          single_donations_count++;
        }
      }
      if(single_donations_count==1)
      {
        single_donations_count++;
      }
    }
    else
    {
      for (int i = 0; i < line.size(); i++)
      {
        if ((line[i] == ' ') && (count == 0))
        {
          total_collector = total_collector + stod(line.substr(i));
        }
        else if ((line[i] == ' ') || (line[i] == '\r'))
        {
          total_money = total_money + stod(line.substr(i));
        }
      }
      if (total_money > maxTotalDonation)
      {
        maxTotalDonation = total_money;
        maxTotalCollector = total_collector;
      }
    }
    count = 0;
  }

  // read data

  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
}