def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
    return arr

def heapify(arr, n, root):
    largest_index = root
    left = 2 * root + 1
    right = 2 * root + 2

    if left < n and arr[left] > arr[largest_index]:
        largest_index = left

    if right < n and arr[right] > arr[largest_index]:
        largest_index = right

    if largest_index != root:
        arr[root], arr[largest_index] = arr[largest_index], arr[root]
        heapify(arr, n, largest_index)

arr = [4,2,3,1,5]
print(heap_sort(arr))


