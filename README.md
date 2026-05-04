# RecursionLab
Lab 12 on recursion for CISC 187
### Task 1: Identify the base case in the following function
#### Given function:
```
def print_every_other(low, high) 
    return if low > high
    puts low
    print_every_other(low + 2, high)
end
```

The base case for the given function is line 2:
```
return if low > high
```
If this condition is met the recursion stops and the stack unwinds.

### Task 2: Predict what will happen in the following function if factorial(10) is called
#### Given function:
```
def factorial(n)
    return 1 if n == 1
    return n * factorial(n - 2)
end
```
The factorial will produce infinite recursion due to the fact the base case will be skipped over, returning when n == 1. The factorial will be called in the following order:
factorial(10), 10 * factorial(8), 8 * factorial(6), 6 * factorial(4), 4 * factorial(2), and where the problem occurs 2 * factorial(0), following this call the recursion will continue infinitely into negative integers which will lead to stack overflow.
### Task 3: Add the correct base case to the following code:
#### Given function:
```
def sum(low, high)
    return high + sum(low, high - 1)
end
```

#### Function with the base case added:
```
def sum(low, high)
    return high if low == high
    return high + sum(low, high - 1)
end
```
When low is equal to high we have correctly decremented through all numbers between our upper and lower bounds and we are done. We make sure we account for that last value by returning it, which in this case can be either high or low since they are equal.
### Task 4: Write a recursive function that prints all numbers (and just numbers)
#### My Recursive function:
```cpp
//using get_if over holds_alternative since I want to access the data to cout as well, don't want 2 separate calls with get
void printNums(const vector<elements>& arr) {
    for (const auto& e : arr){
        //if the datatype we run into is an int, print it, no more complexity needed
        if(const int* num = get_if<int>(&e)){
            cout << *num << "\n";
        } else if (const innerArr* nested = get_if<innerArr>(&e)){ //if it is not an int it is an innerArr
            printNums(nested->nums); //Recursive call for any nested arrays, which continues until an integer is hit, which then gets printed
        }
    }
}
```
In this function I have utilized the variant library, which has allowed me to consider my elements as being either integers or a structure known as innerArr, which is a vector that can also hold that multi-typing and is representative of the nested nature the given problem presented. A const reference for our vector holding those elements is passed as the argument, we then iterate through all of its elements. The element is accessed through the variant function get_if, which I prefered over holds_alternative as I would not need to make a separate "get" call to access the element after analyzing it. If the element is an integer it is put into a cout statement, if it is an innerArr we then use our recursive call on that innerArr to access all of its elements, which may include both integers and deeper innerArrays. The base case is that we hit an integer (our goal) in which case we merely print it out with no recursive call being made, with our for loop providing the necessary iteration for each level. 
