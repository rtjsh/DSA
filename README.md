# DSA
Class Assignments of DSA

# Radix Sort

# Flow of Execution

Input: User enters 10 numbers.
Find Maximum: getMax identifies the largest number to determine the number of digits.
Radix Sort:
For each digit (from least significant to most significant):
Call countSort to sort the array based on that digit.
Output: Print the sorted array.
Example Run
Input:

Enter 10 numbers: 170 45 75 90 802 24 2 66 200 123

Steps:

Find maximum: 802 (3 digits).

Sort by units place:

170, 90, 802, 2, 123, 24, 45, 75, 200, 66

Sort by tens place:

802, 2, 123, 24, 45, 66, 170, 75, 200, 90

Sort by hundreds place:

2, 24, 45, 66, 75, 90, 123, 170, 200, 802

Output:
Array before sorting:
170 45 75 90 802 24 2 66 200 123
Array after sorting:
2 24 45 66 75 90 123 170 200 802

Time Complexity

Best/Worst/Average Case: 

O(d⋅(n+k)), where:
𝑑
d: Number of digits in the largest number.
𝑘
k: Range of digits (0-9 for decimal).
𝑛
n: Number of elements in the array.

# Shell Sort

# Example Walkthrough

Example Input: 45 12 33 10 8 23 5 19 22 1

Array before sorting:
45 12 33 10 8 23 5 19 22 1

Initial Gap Calculation:

gap = n / 2 = 10 / 2 = 5
Compare and sort elements that are 5 positions apart.

Array after first gap:
[5 12 33 10 8 23 45 19 22 1]

Reduce Gap:
gap = 5 / 2 = 2

Compare and sort elements that are 2 positions apart.

Array after second gap:
[5 8 23 10 12 19 22 33 45 1]

Reduce Gap:
gap = 2 / 2 = 1
Perform standard insertion sort.

Final sorted array:
[1 5 8 10 12 19 22 23 33 45]

4. Array After Sorting
The sorted array is displayed:
printArray(arr, n);

Output:
Array after sorting:
1 5 8 10 12 19 22 23 33 45

5. Program Ends
The program returns 0 to indicate successful execution.

Summary
The Shell Sort algorithm reduces the sorting time by first sorting elements far apart and then reducing the gap, leading to fewer shifts compared to standard insertion sort. The user inputs an array of integers, which is then sorted and displayed.

# Time Complexity
Best Case: 
O(nlogn) (with optimal gap sequences).

Average Case: 
O(n^3/2).

Worst Case: 
O(n^2) (for poorly chosen gap sequences).