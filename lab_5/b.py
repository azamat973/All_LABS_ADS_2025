n = int(input())
stones = list(map(int, input().split()))

while len(stones) > 1:
    
    max1 = 0
    for i in range(1, len(stones)):
        if stones[i] > stones[max1]:
            max1 = i

    stone1 = stones[max1]
    stones[max1] = stones[-1]
    stones.pop()

    if len(stones) == 0:
        break

    max2 = 0
    for i in range(1, len(stones)):
        if stones[i] > stones[max2]:
            max2 = i

    stone2 = stones[max2]
    stones[max2] = stones[-1]
    stones.pop()

    if stone1 != stone2:
        stones.append(abs(stone1 - stone2))

if len(stones) == 0:
    print(0)
else:
    print(stones[0])