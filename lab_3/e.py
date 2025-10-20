n, k = map(int, input().split())
x1 = [0] * n
y1 = [0] * n
x2 = [0] * n
y2 = [0] * n

for i in range(n):
    x1[i], y1[i], x2[i], y2[i] = map(int, input().split())

left = 0
right = 2000000000
result = 2000000000

while left <= right:
    mid = left + (right - left) // 2
    count = 0
    
    for i in range(n):
        
        if x2[i] <= mid and y2[i] <= mid:
            count += 1
    
    if count >= k:
        result = mid
        right = mid - 1
    else:
        left = mid + 1

print(result)