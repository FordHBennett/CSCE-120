#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string pass;
    cout << "Please enter your text input: ";
    cin >> pass;
    cout << "input: " << pass << "\n";
    while(!((pass.find(string{"a"}) == string::npos) && (pass.find(string{"e"}) == string::npos) && (pass.find(string{"i"}) == string::npos) && (pass.find(string{"o"}) == string::npos) && (pass.find(string{"u"})== string::npos)))
    {
        if(!(pass.find(string{"a"}) == string::npos)){pass = pass.replace(pass.find(string{"a"}),1, string{"@"});}
        else if(!(pass.find(string{"e"}) == string::npos)){pass = pass.replace(pass.find(string{"e"}),1, string{"3"});}
        else if(!(pass.find(string{"i"}) == string::npos)){pass = pass.replace(pass.find(string{"i"}),1, string{"!"});}
        else if(!(pass.find(string{"o"}) == string::npos)){pass = pass.replace(pass.find(string{"o"}),1, string{"0"});}
        else if(!(pass.find(string{"u"}) == string::npos)){pass = pass.replace(pass.find(string{"u"}),1, string{"^"});}
    }
    string new_pass = pass;


    // Swap character starting from two
    // corners
    int len = new_pass.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        std::swap(new_pass[i],new_pass[n]);
        n = n-1;
        i = i+1;
    }
    pass = pass + new_pass;

    cout << "output: " << pass << "\n";
    return 0;
}
