def quick_sort(arr, low = 0, high = None):
    if high == None:
        high = len(arr) - 1

    if low < high:
        pivot_index = partition(arr, low, high)

        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)

    return arr

def partition(arr, low, high):
    pivot = arr[low]
    i = low + 1
    for j in range(low + 1, high+ 1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i - 1], arr[low] = arr[low], arr[i - 1]

    return i - 1


arr = [2,5,3,4,7]
print(quick_sort(arr))