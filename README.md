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
If this condition is met the recursion ends and the stack created up to that point is processed.

### Task 2: Predict what will happen in the following function if factorial(10) is called
#### Given function:
```
def factorial(n)
    return 1 if n == 1
    return n * factorial(n - 2)
end
```
The factorial will produce infinite recursion due to the fact the base case will be skipped over. The factorial will be called in the following order:
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
### Task 4: Write a recursive function that prints all numbers (and just numbers)

