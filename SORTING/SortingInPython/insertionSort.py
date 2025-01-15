import time
import random

def insertionSort(arr,n):
    for i in range(n):
        key=arr[i]
        j=i-1
        while j>=0 and key<arr[j]:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key
    return arr  
    


# Generate a random list of 10 integers between 0 and 100
random_array = [random.randint(0, 100) for _ in range(10)]
print("Random array:", random_array)
print("Before Sorting: ",random_array)
start=time.time()
Arr = insertionSort(random_array,len(random_array))
end=time.time()
print("After Sorting: ",Arr)
print("Time taken: ",end-start)