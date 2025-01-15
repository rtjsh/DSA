import random
import time

def partition(A, l, r):
    X = l
    Y = r
    pivot = A[l]
    while X < Y:
        while A[X] <= pivot and X <= r:
            X += 1
        while A[Y] > pivot and Y > l:
            Y -= 1
        if X < Y:
            A[X], A[Y] = A[Y], A[X]
    A[l], A[Y] = A[Y], A[l]
    return Y

def QuickSort(A, l, r):
    if l < r:
        p = partition(A, l, r)
        QuickSort(A, l, p - 1)
        QuickSort(A, p + 1, r)

def display(A, n):
    for i in range(n):
        print(A[i])
    print()

A = [0] * 100000
print("Enter n:")
n = int(input())
for i in range(n):
    A[i] = random.randint(0, 100000)
display(A, n)
start = time.time()
QuickSort(A, 0, n - 1)
end = time.time()
print("The sorted numbers are:")
display(A, n)
print(f"The time taken is {end - start} seconds")
