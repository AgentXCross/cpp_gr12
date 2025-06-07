#include <iostream>
#include <string>
using namespace std;

//& in the function parameter makes the program faster as the function doesn't make a copy
bool is_palindrome(const string& input_string, const string& reverse_string) { //const makes the function not change the original string
    return input_string == reverse_string;
}

string find_reverse(const string& input_string) {
    int length = input_string.length();
    string reverse;
    for(int i = length - 1; i >= 0; i--) {
        reverse += input_string[i];
    }
    return reverse;
}

int main() {
    cout << "Enter the string you want to analyze --> ";
    string input_string;
    getline(cin, input_string);
    string reverse_string = find_reverse(input_string);
    
    if(is_palindrome(input_string, reverse_string)) {
        cout << "The string " << input_string << " is a palindrome as its reverse is " << reverse_string;
    } else {
        cout << "The string " << input_string << " is not a palindrome as its reverse is " << reverse_string;
    }
}
