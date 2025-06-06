#include <iostream>
#include <map>
#include <fstream> //file handling
#include <sstream> //parsing strings
#include <string>
using namespace std;

struct StateData { //Structure for the dictionary
        double gdp_per_worker;
        double workforce_in_stem;
        double urbanization_rate;
        double adjusted_disposable_income;
        double disposable_income;
        double true_value_USD;
    };

string clean(string input) { //Cleaning function for data in the .txt file
    string cleaned_string = ""; //Any character that isn't a digit or decimal point is removed
    
    for(int i = 0; i < input.length(); i++){
        char current_char = input[i];
        if (isdigit(current_char) || current_char == '.'){ //If the current char's ASCII value is between 0 and 9's ASCII value or if its a decimal
            cleaned_string += current_char;
        };
    };
    return cleaned_string;
};

int main() {
    ifstream file("merged_gdp_data.txt"); //opens the file for reading
    map <string, StateData> gdp_database; //dictionary for storing values
    

};