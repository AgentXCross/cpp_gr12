#include <iostream>
#include <ctime>
using namespace std;

int main() {
    cout << "Enter the number of Pascal Triangle rows--> " << endl;
    int rows;
    cin >> rows;
    time_t start_time = time(NULL); //Start the timer
    static int triangle[2000][2000] = {0}; //Fill with all 0's, don't print the 0's later

    for(int i = 0; i < rows + 1; i++) {
        triangle[i][0] = 1; //First element 1
        triangle[i][i] = 1; //Last element 1

        for(int j = 1; j < i; j++) { 
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]; //Add number above to the left and just above
        }
    }

    for(int k = 0; k < rows; k++) {
        for(int n = 0; n < rows; n++) {
            if (triangle[k][n] != 0) {
            cout << triangle[k][n] << " ";
            }
        }
        cout << "\n";
    }
    time_t end_time = time(NULL);
    cout << "\nTime taken: " << end_time - start_time << " seconds" << endl;
    return 0;
}