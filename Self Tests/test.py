import re


def binarySearch(arr,target):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def pairs(k,arr):
    total = 0
    arr.sort()
    for i in range(len(arr)):
        if binarySearch(arr,arr[i] - k) != -1:
            total += 1
    return total

