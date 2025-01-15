import time
import random

def bubbleSort(arr,n):
    for i in range(n):
        for j in range(n-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    return arr


# Generate a random list of 10 integers between 0 and 100
random_array = [random.randint(0, 100) for _ in range(10)]
print("Random array:", random_array)
print("Before Sorting: ",random_array)
start=time.time()
Arr = bubbleSort(random_array,len(random_array))
end=time.time()
print("After Sorting: ",Arr)
print("Time taken: ",end-start)