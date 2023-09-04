#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    //cout << add(string{"11111"},string{"11111"})<< '\n';
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    string num;
    string left;
    string right;
    while(true){
        cout << ">> ";
        getline(cin,num);
        cout << "\n";
        int size = num.size();
        for(int j = 0; j<=size; j++)
        {
            for(int i = 0; i <=j; i++)
            {
                if(num[i] == ' ' && num[i+1] == ' ')
                {
                    num.erase(num.begin() + i);
                }
                else if(num[0]== ' ')
                {
                    num.erase(num.begin());
                }
                else if(num[i] == '\0' && num[i-1]== ' ')
                {
                    num.erase(num.end() - 1);
                }
            }
        }
        if(!((num == string{"q"}) || (num == string{"quit"}) || (num == string{"q "}) || (num == string{"quit "})))
        {
            if(num.find(string{"*"}) != string::npos)
            {
                left = num.substr(0,(num.find(string{"*"}) - 1));
                right = num.substr((num.find(string{"*"}) + 2),num.size());
                cout << "ans =" << "\n" << "\n" << "    " << multiply(right,left) << "\n"<< "\n";
            }
            else if(num.find(string{"+"}) != string::npos)
            {
                left = num.substr(0,(num.find(string{"+"})-1));
                right = num.substr((num.find(string{"+"}) + 2),num.size());
                cout << "ans =" << "\n" << "\n" << "    " << add(right,left) << "\n" << "\n";
            }
        }
        else
        {
            cout << "farvel!" << "\n" << "\n";
            break;
        }
    }
    return 0;
    // TODO(student): implement the UI
}
