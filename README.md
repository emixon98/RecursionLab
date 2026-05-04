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

### Task 2: Predict what will happen in the following function if factorial(10) is called
#### Given function:
```
def factorial(n)
    return 1 if n == 1
    return n * factorial(n - 2)
end
```

### Task 3: Add the correct base case to the following code:
#### Given function:
```
def sum(low, high)
    return high + sum(low, high - 1)
end
```

#### Function with the base case added:

### Task 4: Write a recursive function that prints all numbers (and just numbers)

