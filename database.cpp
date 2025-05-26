#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map <string, int> inventory = {
        {"apples", 5},
        {"bananas", 4},
        {"cherrys", 10},
        {"grapes", 20},
        {"oranges", 7}
    };

    string fruit;
    cout << "Enter fruit for amount: " << endl;
    getline(cin, fruit);
    cout << "You have " << inventory[fruit] << " " << fruit << endl;
}