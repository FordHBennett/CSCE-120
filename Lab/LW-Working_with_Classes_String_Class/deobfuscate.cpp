#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string line;
    string num;
    string sentence = string{""};
    cout << "Please enter obfuscated sentence: ";
    cin >> line;
    cout << "Please enter deobfuscation details: ";
    cin >> num;
    int count = 0;
    for (int i = 0; i<static_cast<int>(num.size()); i++)
    {
        int index = static_cast<int>(num[i]);
        index = index - 48;
        sentence = sentence + line.substr(count,index) + string{" "};
        count += index;
    }
    cout << "Deobfuscated sentence: " << sentence;

    return 0;
}
