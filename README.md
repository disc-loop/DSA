A tool to learn data structures and algorithms in C. 

# Use
Generate exercises:
```
dsa -g binarySearch
dsa -g insertionSort quickSort
dsa -g binarySearch -o some/path
```
Test solutions:
```
dsa -t some/path
```
Show profiles:
```
dsa binarySearch
dsa insertionSort
dsa quickSort
```

# Resources
- [Library of algorithms and data structures](https://xlinux.nist.gov/dads/)

# TODO
- Create a profile for an algorithm
    - Name of algorithm
    - Implementation
    - Kind of algorithm (search, filter, divide and conquer, etc.)
    - Time complexity
        - Best case, worst case, average case
    - Space complexity
    - Limitations
    - Use cases
    - Properties
        - Like non-adaptive, adaptive, stable, etc.
- Write generic tests for each kind of algorithm
    - e.g.
    - Array based
        - Search
        - Sort
        - Filter
    - Optional:
        - Runtime analysis on solutions for exercises
- Write generic tests for each kind of data structure
- Tests for both should check knowledge too
  - Runtime
  - Limitations
  - How they compare to others of similar kind
  - Use cases
- Create exercise builder
    - Input: name of exercise to build
    - Output: files containing skeleton code for exercises
- Create test runner
    - Run tests for the exercise session
    - Run tests for specified exercise
- Organise project
    - Figure out what how to organise the DSA references
- Output stats
    - Percentage passed
    - Time taken
    - Weak points
    - Strong points
    - Stratistics over time
- Visualise stats
