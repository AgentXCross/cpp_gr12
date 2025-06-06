#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    string output; 
    bool more = true; //If user wants to continue to enter values

    while(more) {
        string append;
        cout << "\nEnter your string --> ";
        getline(cin, append);
        output += " ";
        output += append;
        
        char y_or_n;
        cout << "\nWould you like to continue entering strings (Y or N) --> ";
        cin >> y_or_n;
        cin.ignore(numeric_limits <streamsize> ::max(), '\n'); //Clear leftover newline

        switch(y_or_n) {
            case 'Y':
            case 'y':
                more = true;
                break;
            case 'N':
            case 'n':
                more = false;
                break;
            default:
                cout << "Invalid input";
                more = false;
                return 1;
       }
    }

    cout << output;
}