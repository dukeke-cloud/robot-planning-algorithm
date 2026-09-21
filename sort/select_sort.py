num = [4,2,1,6,3,5]

for i in range(len(num)-1):#最后一个元素不用处理
    min_index = i
    for j in range(i+1, len(num)):
        if num[j] < num[min_index]:
            min_index = j
    num[i], num[min_index] = num[min_index], num[i]

print(num)
    
    
