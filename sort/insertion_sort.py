num = [2,7,4,3,9,5]

for i in range(1, len(num)):
    key = num[i]#待插入元素
    j = i-1
    while j>=0 and num[j] > key:
        num[j+1] = num[j]
        j-=1

    num[j+1] = key

print(num)
