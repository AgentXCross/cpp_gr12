#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 0 && i % 5 == 0) { //If i is divisible by both, print fizzbuzz and ignore other conditions
            cout << "fizzbuzz" << endl;
        }
        else if (i % 3 == 0) { //Fizz if divisible by 3
            cout << "fizz" << endl;
        }
        else if (i % 5 == 0) {
            cout << "buzz" << endl; //Buzz if diviside by 5
        }
        else {
            cout << i << endl; //Else print the number
        }
    }
}