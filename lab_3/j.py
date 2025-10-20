n, h = map(int, input())
bags = list(map(int, input()))

total = sum(bags)
left = 1
right = total
result = total

while left <= right:
    mid = left + (right - left) 
    hours = 0
    
    for bag in bags:
        hours += (bag + mid - 1) 
    
    if hours <= h:
        result = mid
        right = mid - 1
    else:
        left = mid + 1

print(result)