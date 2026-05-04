#include <iostream>
#include <vector>
#include <variant>

using namespace std;

struct innerArr;

//using variant since we need both arrays and integers in our vector
using elements = variant<int, innerArr>;

//an array inside our or array is treated as a vector that can also contain elements being either integers or another arr
struct innerArr {
    vector<elements> nums;
};

//using get_if over holds_alternative since I want to access the data to cout as well, don't want 2 separate calls with get
void printNums(const vector<elements>& arr) {
    for (const auto& e : arr){
        //if the datatype we run into is an int, print it, no more complexity needed
        if(const int* num = get_if<int>(&e)){
            cout << *num << "\n";
        } else if (const innerArr* nested = get_if<innerArr>(&e)){ //if it is not an int it is an innerArr
            printNums(nested->nums); //Recursive call for any nested arrays, which will in turn let us print
            //their ints to console, until another array is reached
        }
    }
}

int main() {
    //trying to setup the given array as provided
    //contains our defined elements that are of innerArr or int type
vector<elements> array = {
        1, 2, 3,
        innerArr{{4, 5, 6}},
        7,
        innerArr{{8, innerArr{{9, 10, 11, innerArr{{12, 13, 14}}}}}},
        innerArr{{15, 16, 17, 18, 19,
            innerArr{{20, 21, 22,
                innerArr{{23, 24, 25,
                    innerArr{{26, 27, 29}}
                }}, 30, 31
            }}, 32            
        }},
        33                     
    };
    printNums(array);
    return 0;
}

