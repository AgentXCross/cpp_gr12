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
    
    for(int i = 0; i < input.length(); i++) {
        char current_char = input[i];
        if (isdigit(current_char) || current_char == '.') { //If the current char is a digit or a decimal
            cleaned_string += current_char;
        }
    }
    return cleaned_string;
}

int main() {
    ifstream file("merged_gdp_data.txt"); //opens the file for reading
    map <string, StateData> gdp_database; //dictionary for storing values
    string state, word;
    string gdp, stem, urban, adj, disp, value;

    while (file >> word) { //reads one word at a time, then loops back to start for the next line
        state = word; //state is set to the first word
        file >> word; //move onto next word

        if(word[0] != '$'){ //If the next word doesn't start with $, its still apart of the state name
            state += " " + word;
            file >> word;
        }

        gdp = word;
        file >> stem >> urban >> adj >> disp >> value; //go through the rest of the words and store 

        StateData d; //Initialize a structure
        d.gdp_per_worker = stod(clean(gdp)); 
        d.workforce_in_stem = stod(clean(stem));
        d.urbanization_rate = stod(clean(urban));               
        d.adjusted_disposable_income = stod(clean(adj));
        d.disposable_income = stod(clean(disp));
        d.true_value_USD = stod(value);

        gdp_database[state] = d; //save to state key
    };

    string input;
    while(true) {
        cout << "\nEnter which state you would like to analyze (or enter 'Exit' to quit)? " ;
        getline(cin, input);

        if(input == "Exit" || input == "exit") {
            break; //end the loop
        }

        if (gdp_database.count(input)){
            StateData d = gdp_database[input];
            cout << "\nGDP Per Worker: $" << d.gdp_per_worker << endl;
            cout << "% STEM Workforce: " << d.workforce_in_stem << "%" << endl;
            cout << "% Urbanization Rate: " << d.urbanization_rate << "%" << endl;
            cout << "True Value Adjusted Disposable Income: $" << d.adjusted_disposable_income << endl;
            cout << "Average Disposable Income: $" << d.disposable_income << endl;
            cout << "True value of $1 USD: " << d.true_value_USD << endl;
        } else {
            cout << "State not found. Please check your spelling." << endl;
        }
    };
    return 0;
};   
