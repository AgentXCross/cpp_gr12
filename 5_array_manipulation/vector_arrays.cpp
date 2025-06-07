#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Mad Libs Game made using vector arrays

Deleting from a vector array wasn't done in the program but the following will do it:
array.pop_back() removes the last element
array.erase(array.begin + index) removes at an index
*/

int main() {
    vector <string> word_inputs; //Initialize the input array
    string input;

    vector<string> prompts = { //Prompt array
        "Enter an adjective-> ",
        "Enter a superlative (best, worst, biggest)-> ",
        "Enter a singular noun-> ",
        "Enter another adjective-> ",
        "Enter another singular noun-> ",
        "Enter another adjective-> ",
        "Enter another singular noun-> ",
        "Enter a verb-> ",
        "Enter another singular noun-> ",
        "Enter another verb-> ",
        "Enter another singular noun-> ",
        "Enter another adjective-> ",
        "Enter another adjective-> ",
        "Enter another plural noun-> ",
        "Enter a city-> ",
        "Enter another singular noun-> ",
        "Enter one last singular noun-> "
    };

    for(const string& prompt : prompts){ //for prompt in prompts
        cout << prompt;
        getline(cin, input);
        word_inputs.push_back(input);
    }

    cout << "My cubicle is " << word_inputs[0] << ". It is the " << word_inputs[1]
         << " cubicle in the office. I have a " << word_inputs[2]
         << " on my desk next to a(n) " << word_inputs[3] << " " << word_inputs[4]
         << ". In my drawer, I also have a(n) " << word_inputs[5] << " " << word_inputs[6]
         << ". One time a coworker tried to " << word_inputs[7] << " my "
         << word_inputs[8] << " on my desk.\n"
         << "I said to him, \"Hey! how would you like it if I " << word_inputs[9]
         << " your " << word_inputs[10] << "? I'll do it if you don't leave.\"\n\n"

         << "My one complaint about my cubicle is that it is " << word_inputs[11]
         << ". I think everyone here at the office complains about this. "
         << "We also complain that our cubicle is " << word_inputs[12]
         << ". If we had money in our budget, my boss could purchase some "
         << word_inputs[13] << " to help alleviate this problem. "
         << "Our boss doesn't understand. His office is the size of "
         << word_inputs[14] << ". He has enough room in his office to put a "
         << word_inputs[15] << " and a " << word_inputs[16] << " in there.\n";

    return 0;
}


