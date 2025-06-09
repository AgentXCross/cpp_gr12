#include <iostream>
using namespace std;

//Conversion Functions
int kelvin_to_celsius(int kelvin) {
    return kelvin - 273;
}

int celsius_to_kelvin(int celsius) {
    return celsius + 273;
}

int celsius_to_fahrenheit(int celsius) {
    return (celsius * 9 / 5) + 32;
}

int fahrenheit_to_celsius(int fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

//Return Results Function
void convert_and_display(int temperature, char unit) {
    switch(unit) {
        case 'C':
        case 'c': {
            int converted_kelvin = celsius_to_kelvin(temperature);
            int converted_fahrenheit = celsius_to_fahrenheit(temperature);
            cout << "Celsius: " << temperature << "°C\n";
            cout << "Fahrenheit: " << converted_fahrenheit << "°F\n";
            cout << "Kelvin: " << converted_kelvin << " K\n";
            break;
        }
        case 'F':
        case 'f': {
            int converted_celsius = fahrenheit_to_celsius(temperature);
            int converted_kelvin = celsius_to_kelvin(fahrenheit_to_celsius(temperature));
            cout << "Celsius: " << converted_celsius << "°C\n";
            cout << "Fahrenheit: " << temperature << "°F\n";
            cout << "Kelvin: " << converted_kelvin << " K\n";
            break;
        }
        case 'K':
        case 'k': { 
            int converted_celsius = kelvin_to_celsius(temperature);
            int converted_fahrenheit = celsius_to_fahrenheit(kelvin_to_celsius(temperature));
            cout << "Celsius: " << converted_celsius << "°C\n";
            cout << "Fahrenheit: " << converted_fahrenheit << "°F\n";
            cout << "Kelvin: " << temperature << " K\n";
            break;
        }
        default: {
            cout << "Invalid Unit Input. Please enter either K, C, or F.";
            break;
        }
    }
}

//Main function for inputs
int main() {
    char unit;
    int temperature;

    cout << "Enter the unit of your input temperature--> ";
    cin >> unit;
    if (cin.fail()) { //Catch error
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid unit input. Please enter a character K, C, or F.\n";
        return 1; 
}
    cout << "Enter the temperature in that unit--> ";
    cin >> temperature;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid temperature input. Please enter an integer.\n";
        return 1;
}

    convert_and_display(temperature, unit);
    return 0;
}