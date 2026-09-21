num = [1,23,5,2,7]
n = len(num)

for i in range(n-1):
    for j in range(n-1-i):
        if num[j] > num[j+1]:
            num[j],num[j+1] = num[j+1],num[j]

print(num)


