import random
import time

def selectionSort(A, n):
    for i in range(n):
        least = A[i]
        pos = i
        for j in range(i + 1, n):
            if A[j] < least:
                least = A[j]
                pos = j
        A[i], A[pos] = A[pos], A[i]

def display(A, n):
    for i in range(n):
        print(A[i], end=" ")
    print()

A = [0] * 100000
random.seed(time.time())
print("Enter n:", end=" ")
n = int(input())
for i in range(n):
    A[i] = random.randint(0, 100000)
display(A, n)
start = time.time()
selectionSort(A, n)
end = time.time()
print("The sorted numbers are:")
display(A, n)
print(f"The time taken is {end - start} seconds")
