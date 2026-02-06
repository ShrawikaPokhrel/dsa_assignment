# Documentation: Program 8 – Sorting Random Numbers with User-Selected Algorithm
# 1. Objective
Generate a list of `N` random integers in the range [1, 1000], then sort the list using a user-selected sorting algorithm from the following:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort

The program also tracks and displays the total number of comparisons and swaps (where applicable) during sorting.

# 2. Data Structures Used

-> 2.1 Array of Integers
- An integer array of size `N` to store randomly generated numbers.

-> 2.2 Counters
- Variables to count the number of **comparisons** and **swaps** performed during sorting.

# 3. Functions Implemented

-> 3.1 `void generateRandomNumbers(int arr[], int N)`
- Fills the array `arr` with `N` random integers between 1 and 1000.

-> 3.2 Sorting Algorithms
- Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order.
- Selection Sort: Selects the minimum element and swaps it with the first unsorted element.
- Insertion Sort: Builds the sorted array one element at a time by inserting elements into their correct position.
- Merge Sort: Recursively divides the array into halves, sorts and merges them.

Each sorting function:
- Sorts the array in-place (except merge sort which may use temporary arrays).
- Counts the number of comparisons and swaps during execution.

->3.3 `void printArray(int arr[], int N)`
- Prints the array elements.

# 4. Overview of `main()`
- Reads the number `N` of elements from the user.
- Generates the random list of `N` integers.
- Displays the unsorted list.
- Asks the user to choose a sorting algorithm.
- Calls the corresponding sorting function.
- Prints the sorted list.
- Displays the total number of comparisons and swaps.

# 5. Sample Output

Enter number of elements: 3
Unsorted array: 789 456 123

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 1

Sorted array: 123 456 789
Total comparisons: 3
Total swaps: 2
