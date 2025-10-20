n = int(input())
arr = list(map(int, input().split()))

total_cost = 0

def extract_min(a, size):

    min_index = 0
    for i in range(1, size):
        if a[i] < a[min_index]:
            min_index = i
    val = a[min_index]
    a[min_index] = a[size - 1]
    return val

size = n
while size > 1:
    x = extract_min(arr, size)
    size -= 1
    y = extract_min(arr, size)
    size -= 1

    merged = x + y
    total_cost += merged

    arr[size] = merged
    size += 1

print(total_cost)
