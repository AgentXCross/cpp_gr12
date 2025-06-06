#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    cout << "\nEnter a string you want to slice--> ";
    string input;
    getline(cin, input);

    int index_1, index_2; //Take inputs for slicing indexes
    cout << "\nEnter the starting index--> ";
    if (!(cin >> index_1)) {
        cout << "Starting index was not a valid integer.\n";
        return 1;
    };
    cout << "\nEnter the ending index (index not apart of string)--> ";
    if (!(cin >> index_2)){
        cout << "Ending index was not a valid integer.\n";
    };

    int length = input.length(); //Check for valid indices
    if(index_1 < 0 || index_1 >= length || index_2 > length || index_1 > index_2) {
        cout << "You entered invalid indices for your string.\n";
        return 1;
    }

    int slice_len = index_2 - index_1;
    cout << input.substr(index_1, slice_len) << "\n";
    return 0;
}