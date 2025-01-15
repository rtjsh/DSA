import random
import time

def Merge(A, l, m, r):
    B = [0] * 100000  # Temporary array
    j = m
    k = l
    while i < m and j <= r:
        if A[i] < A[j]:
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1
        k += 1
    while i < m:
        B[k] = A[i]
        i += 1
        k += 1
    while j <= r:
        B[k] = A[j]
        j += 1
        k += 1
    for k in range(l, r + 1):
        A[k] = B[k]

def MergeSort(A, l, r):
    if l < r:
        m = (l + r) // 2
        MergeSort(A, l, m)
        MergeSort(A, m + 1, r)
        Merge(A, l, m + 1, r)

def display(A, n):
    for i in range(n):
        print(A[i], end=" ")
    print()

A = [0] * 100000
print("Enter n:", end=" ")
n = int(input())
for i in range(n):
    A[i] = random.randint(0, 100000)
start = time.time()
MergeSort(A, 0, n - 1)
end = time.time()
print("The sorted numbers are:")
print(f"The time taken is {end - start} seconds")
