#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  std::ifstream file(filename);
    string line;
  if (!(file.is_open())) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }

  double maxTotalDonation = 0;
  int maxTotalCollector = 0;

  double total_money = 0;
  int total_collector = 0;

  file >> total_collector;
  string num_line = "";
  getline(file, line);
  for (int i = 0; i < line.size(); i++)
  {
      if ((line[i] == ' ') || (line[i] == '\r'))
      {
          total_money = total_money + stod(line.substr(i));
      }
  }


  // read data

  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
}
