#include <iostream>
#include <string>
#include <sstream>
#include <limits>


using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_avg,
                   double hw_average,
                   double lw_average,
                   double reading_average,
                   double engagement_average,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO
    double exam = 0.0;
    int exam_count = 0;
    double final = 0.0;
    int final_count = 0;
    double hw = 0.0;
    int hw_count = 0;
    double lw = 0.0;
    int lw_count = 0;
    double reading = 0.0;
    int reading_count = 0;
    double engagement = 0.0;
    int engagement_count = 0;
    double compile = 0.0;
    int compile_zero = 0;
    int compile_count = 0;
    // TODO(student): declare and initialize variables that you want
    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
            exam = exam + score;
            exam_count++;
        } else if (category == "final-exam") {
            // TODO(student): process final score
            final = score;
            exam = exam + score;
            final_count++;
                exam_count++;
        } else if (category == "hw") {
            // TODO(student): process hw score
            hw = hw + score;
            hw_count++;
        } else if (category == "lw") {
            // TODO(student): process lw score
            lw = lw + score;
            lw_count++;
        } else if (category == "reading") {
            // TODO(student): process reading score
            reading = reading + score;
            reading_count++;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engagement = engagement + score;
            engagement_count++;
        }else if  (category == "compile-check") {
            // TODO(student): process compile-check score
            if (score > 0)
            {
                compile = compile + score;
                compile_count++;
            }
            else
            {
                compile_zero++;
                compile_count++;
            }
        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

        // TODO(student): compute component averages
        double exam_average = 0;
        double hw_average = 0;
        double lw_average = 0;
        double reading_average = 0;
        double engagement_average = 0;

        if(final_count == 0)
        {
            exam_count++;
        }
        if (exam_count > 0)
        {
            exam_average = exam/3;
        }
        else
        {
            exam_average = 0.0;
        }
        if (final > exam_average)
        {
            exam_average = final;
        }
        if(hw_count > 0)
        {
            hw_average = hw/ hw_count;
        }
        else
        {
            hw_average = 0.0;
        }
        if (compile > 0)
        {
            if((compile_zero == 0) && (compile_count == 2) )
            {
                lw_average = lw / lw_count;
            }
            else if ((compile_zero == 1) || (compile_count == 1))
            {
                lw_average = lw / lw_count;
                lw_average = lw_average / 2;
            }
            else
            {
                lw_average = 0;
            }
            lw_average = lw_average * 100;
        }
        else
        {
            lw_average = 0.0;
        }
        if(reading_count > 0){
            reading_average = (reading / reading_count) + 15.0;
        }
        else
        {
            reading_average = 15.0;
        }
        if (reading_average > 100.0)
        {
            reading_average = 100.0;
        }
        if(engagement_count>0){
            engagement_average = (engagement / engagement_count) + 15.0;
        }
        else
        {
            engagement_average = 15.0;
        }
        if (engagement_average > 100.0)
        {
            engagement_average = 100.0;
        }

        //compileCheck_average = compile/compile_count;

        // TODO(student): compute weighted total of components
        double weighted_total = exam_average * .4 + hw_average * .4 + lw_average * .1 + reading_average * .05 + engagement_average * .05;

        // TODO(student): compute final letter grade
        char final_letter_grade = 'X';
    if (weighted_total >= 90.0)
    {
            final_letter_grade = 'A';
    }
    else if (weighted_total >= 80.0)
    {
        final_letter_grade = 'B';
    }
    else if (weighted_total >= 70.0)
    {
        final_letter_grade = 'C';
    }
    else if (weighted_total >= 59.2408)
    {
        final_letter_grade = 'D';
    }
    else
    {
        final_letter_grade = 'F';
    }

    print_results(
        exam_average, hw_average, lw_average, reading_average, engagement_average,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement | compile-check" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_avg,
    double hw_average,
    double lw_average,
    double reading_average,
    double engagement_average,
    double weighted_total,
    char final_letter_grade)
{
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_avg << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading_average << endl;
    cout << "        engagement: " << engagement_average << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
