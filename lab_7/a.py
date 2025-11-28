
t = int(input())  

for _ in range(t):
    words = input().split()

    words.sort(key=len)
    print(" ".join(words))
