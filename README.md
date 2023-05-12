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

## Header files:open_file_folder:
- [sort.h](./sort.h): The hearder file that contain the prototypes of all functions and structure definitions use some functions.

|File|Prototype/structure|
|----|-------------------|
|`0-bubble_sort.c`, `0-O`|`void bubble_sort(int *array, size_t size);`|
|`1-insertion_sort_list.c`, `1-O`|`void insertion_sort_list(listint_t **list);`|
|`2-selection_sort.c`, `2-O`|`void selection_sort(int *array, size_t size);`|
|`3-quick_sort.c`, `3-O`|`void quick_sort(int *array, size_t size);`|
|`100-shell_sort.c`|`void shell_sort(int *array, size_t size);`|
|`101-cocktail_sort_list.c`, `101-O`|`void cocktail_sort_list(listint_t **list);`|
|`102-counting_sort.c`, `102-O`|`void counting_sort(int *array, size_t size);`|
|`103-merge_sort.c`, `103-O`|`void merge_sort(int *array, size_t size);`|
|`104-heap_sort.c`, `104-O`|`void heap_sort(int *array, size_t size);`|
|`105-radix_sort.c`|`void radix_sort(int *array, size_t size);`|
|`106-bitonic_sort.c`, `106-O`|`void bitonic_sort(int *array, size_t size);`|
|`107-quick_sort_hoare.c`, `107-O`|`void quick_sort_hoare(int *array, size_t size);`|
|Data Structure|
--------------
|``typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;``|

- [deck.h](./deck.h): Header file that contains the structure definitions and function prototypes for the task `1000-sort_deck.c`.

|File|Prototype|
|----|---------|
|`1000-sort_deck.c`|`void sort_deck(deck_node_t **deck);`|
|Data Structure|
|--------------|
|``typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;``|
|``typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;
``|
|``typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;``|

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

**7. Merge sort**
- [103-merge_sort.c](./103-merge_sort.c): A function that sorts an array of integers in ascending order using the [Merge sort](https://en.m.wikipedia.org/wiki/Merge_sort) algorithm.
  - it implements the top-down merge sort algorithm
    - When an array is devided into two sub-arrays, the size of the left array is always `<=` size of the right array. i.e. `{1, 2, 3, 4, 5} -> {1, 2}`, `{3, 4, 5}`
    - it sorts the left array before the right array
  - It is allowed to use `printf`
  - it is allowed to use `malloc` and `free` only once (only one **call**)
- The file [103-O](./103-O) contains the big O notations of the time complexity of the Merge sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**8. Heap sort**
- [104-heap_sort.c](./104-heap_sort.c): A function that sorts an array of integers in ascending order using the [Heap sort](https://en.m.wikipedia.org/wiki/Heapsort) algorithm.
  - it implements the sift-down heap sort algorithm
  - it prints the array after each time two elements swap.
- The file [104-O](./104-O) contains the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**9. Radix sort**
- [105-radix_sort.c](./105-radix_sort.c): A function that sorts an array of integers in ascending order using the [Radix sort] algorithm.
  - itt implements the `LSD` radix sort algorithm
  - it is assume that array will contain only numbers `>= 0`
  - it is allowed to use `malloc` and `free` for this task
  - it print the `array` each time the `significant digit` increases.

**10. Bitonic sort**
- [106-bitonic_sort.c](./106-bitonic_sort.c): A function that sorts an array of integers in ascending order using the [Bitonic sort](https://en.m.wikipedia.org/wiki/Bitonic_sorter) algorithm.
  - It is assume that size will be equal to `2^k`, where `k >= 0` (when `array` is not `NULL` …)
  - It is allowed to use printf
  - it prints the `array` each time two elements swap
- The file [106-O](./106-O) contains the big O notations of the time complexity of the Bitonic sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**11. Quick Sort - Hoare Partition scheme**
- [107-quick_sort_hoare.c](./107-quick_sort_hoare.c): A function that sorts an array of integers in ascending order using the [Quick sort](https://en.m.wikipedia.org/wiki/Quicksort) algorithm.
  - It implements the `Hoare` partition scheme.
  - The pivot is always the last element of the partition being sorted.
  - it prints the `array` after each time two elements swap.
- The file [107-O](./107-O) contains the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
  - in the best case
  - in the average case
  - in the worst case

**12. Dealer**
- [1000-sort_deck.c](./1000-sort_deck.c): A function that sorts a deck of cards.
  - It is allowed to use the C standard library function `qsort`
  - the [deck.h](./deck.h) is the header file, containing the given data structures' definition for the task.
  - Each node of the doubly linked list contains a card that cannot be modified.
  - it swaps the nodes.
  - it is assume there is exactly `52` elements in the doubly linked list.
  - any sorting algorithm can be used
  - The deck must be ordered:
    - From `Ace` to `King`
    - From Spades to Diamonds

## Tests:100::heavy_check_mark:
- [tests](./tests): Folder of test (`main.c` functions) files provided by ALX and some written files use for testing.
