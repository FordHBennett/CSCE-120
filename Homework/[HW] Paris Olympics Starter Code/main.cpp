#include <iostream>
#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;

int main()
{

    // TODO: create arrays needed
    double times[SIZE];
    unsigned int numbers[SIZE];
    unsigned int rank[SIZE];
    string country[SIZE];
    string last_name[SIZE];
    // TOTO: prep all arrays
    prep_double_array(times);
    prep_unsigned_int_array(numbers);
    prep_unsigned_int_array(rank);
    prep_string_array(country);
    prep_string_array(last_name);

    // TODO: prompt until both the file and the contained data are valid
    string filename;
    cout << "< ";
    cin >> filename;
    // prompt_user_if_invalid_filename(filename);
        while (throw_invalid_args(filename))
    {
        cout << "Enter file name: ";
        cin >> filename;
    }
    get_runner_data(filename, times, country, numbers, last_name);
    // TODO: determine ranking, notice the rank array receives the results
    get_ranking(times, rank);

    // TODO: Output results
    print_results(times,country,last_name,rank);

    return 0;
}
