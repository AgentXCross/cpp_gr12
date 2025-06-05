#include <iostream>
#include <map>
#include <fstream> //file handling
#include <sstream> //parsing strings
#include <string>
using namespace std;

struct StateData { //Object structure for the dictionary
        double gdp_per_worker;
        double workforce_in_stem;
        double urbanization_rate;
        double adjusted_disposable_income;
        double disposable_income;
        double true_value_USD;
    };

string clean(const string & s) { //Cleaning function for data in the .txt file
    string result; //Any character that isnt a digit or decimal point is removed
    for (char c : s) {
        if (isdigit(c) || c == '.') result += c;
    }
    return result;
};

int main() {
    ifstream file("merged_gdp_data.txt"); //opens the file for reading
    map <string, StateData> gdp_database = {
        
};