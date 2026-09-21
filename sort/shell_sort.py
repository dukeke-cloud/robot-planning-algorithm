num = [8, 9, 1, 7, 2, 6, 3, 5, 4]

n = len(num)
gap = n // 2

while gap > 0:
    for i in range(gap, n):
        key = num[i]
        j = i
        while num[j - gap] > key and j >= gap:
            num[j] = num[j - gap]
            j -= gap

        num[j] = key

    gap = gap // 2

print(num)


