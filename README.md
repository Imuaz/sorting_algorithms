# 0x1B. C - Sorting algorithms & Big O:signal_strength:
'
**INTRODUCTION**

7The project covered a range of topics related to sorting algorithms, including their definitions, practical applications, and analysis. It explained how to evaluate the time complexity of an algorithm using Big O notation, and how to select the best sorting algorithm for a given input based on its practical requirements and time complexity. Additionally, it defined stable sorting algorithms and how they differ from unstable sorting algorithms. Overall, this project provided a comprehensive overview of sorting algorithms and their importance in software development.

_Background Context_
This project is meant to be done by groups of two students. Each group of two should [pair program](https://en.m.wikipedia.org/wiki/Pair_programming) for at least the mandatory part.

## Resources:books:
- [Sorting algorithm](https://en.m.wikipedia.org/wiki/Sorting_algorithm)
- [Big O notation](https://stackoverflow.com/questions/487258/what-is-a-plain-english-explanation-of-big-o-notation)
- [Sorting algorithms animations](https://www.toptal.com/developers/sorting-algorithms)
- [15 sorting algorithms in 6 minutes](https://youtu.be/kPRA0W1kECg)(**WARNING**: _The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms_)
- [CS50 Algorithms explanation in detail by David Malan](https://youtu.be/yb0PY3LX2x8)
- [All about sorting algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)

## Requirements:pushpin:

**General**
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files end with a new line
- A mandatory [README.md](./README.md) file, at the root of the repo of the project.
- the code should use the `Betty style`. It may be checked using `betty-style.pl` and `betty-doc.pl`
- it is not allowed to use global variables
- No more than 5 functions per file
- Unless specified otherwise, it is not allowed to use the standard library. Any use of functions like `printf`, `puts`, `…` is totally forbidden.
- The prototypes of  functions should be included in the header file called `sort.h` and push to the repo
- The header files should be include guarded
- A list/array does not need to be sorted if its size is less than 2. 

## More Info:scroll:

**Data Structure and Functions**
- For this project, the following functions [print_array](./tests/print_array.c), and [print_list](./tests/print_list.c) has been given.
- the given files `print_array.c` and pr`int_list.c` (containing the `print_array` and `print_list` functions) will be compiled with all functions during the correction.
- the prototype of the functions `print_array` and `print_list` should be declared in the `sort.h` header file.
- the given data structure for doubly linked list contain in the `sort.h` header file should be used.
- note, the following format is used for Quiz and Task questions.
  - `(1)`
  - `O(n)`
  - `O(n!)`
  - n square -> `O(n^2)`
  - log(n) -> `O(log(n))`
  - n * log(n) -> `O(nlog(n))`
  - n + k -> `O(n+k)`
  - …
- the “short” notation (constants should not be used). Example: `O(nk)` or `O(wn)` should be written `O(n)`. If an answer is required within a file, all answers files must have a newline at the end.
- Here is a quick tip that help in testing the sorting algorithms with big sets of random integers: [Random.org](https://www.random.org/integer-sets/)

## Tasks:page_with_curl:

**0. Bubble sort**
- [0-bubble_sort.c](./0-bubble_sort.c): A function that sorts an array of integers in ascending order using the [Bubble sort](https://en.m.wikipedia.org/wiki/Bubble_sort) algorithm.
  - It prints the array after each time the two elements swap.
- the file [0-O](./0-O), contains the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**1. Insertion sort**
- [1-insertion_sort_list.c](./1-insertion_sort_list.c): A function that sorts a doubly linked list of integers in ascending order using the [Insertion sort](https://en.m.wikipedia.org/wiki/Insertion_sort) algorithm.
  - It is not allowed to modify the integer `n` of a node. It swap the nodes themselves.
  - it prints the list after each time ytwo elements swap
- the file [1-O](./1-O) contains the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**2. Selection sort**
- [2-selection_sort.c](./2-selection_sort.c): A function that sorts an array of integers in ascending order using the [Selection sort](https://en.m.wikipedia.org/wiki/Selection_sort) algorithm.
  - it prints the array after each time two elements swap.
- the file [2-O](./2-O) contains the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**3. Quick sort**
- [3-quick_sort.c](./3-quick_sort.c): A function that sorts an array of integers in ascending order using the [Quick sort](https://en.m.wikipedia.org/wiki/Quicksort) algorithm.
  - the `Lomuto` partition scheme is implemented.
  - The pivot is always the last element of the partition being sorted.
  - it prints the array after each time two elements swap.
- The file [3-O](./3-O) contains the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**4. Shell sort - Knuth Sequence**
- [100-shell_sort.c](./100-shell_sort.c): A function that sorts an array of integers in ascending order using the [Shell sort](https://en.m.wikipedia.org/wiki/Shellsort) algorithm, using the `Knuth sequence`
  - It uses the following sequence of intervals (a.k.a the Knuth sequence):
    - `n+1 = n * 3 + 1`
    - `1, 4, 13, 40, 121, ...`
  - it prints the `array` each time the interval decreases.
- **No big O notations of the time complexity of the Shell sort (Knuth sequence) algorithm needed - as the complexity is dependent on the size of array and gap**

**5. Cocktail shaker sort**
- [101-cocktail_sort_list.c](./101-cocktail_sort_list.c): A function that sorts a doubly linked list of integers in ascending order using the [Cocktail shaker sort](https://en.m.wikipedia.org/wiki/Cocktail_shaker_sort) algorithm.
  - It is not allowed to modify the integer n of a node. It swaps the nodes themselves.
  - it prints the list after each time two elements swap.
- The file [101-O](./101-O) contains the big O notations of the time complexity of the Cocktail shaker sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**6. Counting sort**
- [102-counting_sort.c](./102-counting_sort.c): A function that sorts an array of integers in ascending order using the [Counting sort](https://en.m.wikipedia.org/wiki/Counting_sort) algorithm.
  - It is assume that array will contain only numbers `>= 0`
  - it is allowed to use malloc and free for this task
  - it prints the counting array once it is set up.
    - This array is of size `k + 1` where `k` is the largest number in `array`
- The file [102-O](./102-O) contains the big O notations of the time complexity of the Counting sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case
