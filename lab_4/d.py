class Node:
    def __init__(self, v):     
        self.v = v
        self.l = None
        self.r = None

def insert(root, x):
    level = 0
    cur = root
    while True:
        if x < cur.v:
            if cur.l:
                cur = cur.l
                level += 1
            else:
                cur.l = Node(x)
                return level + 1
        else:
            if cur.r:
                cur = cur.r
                level += 1
            else:
                cur.r = Node(x)
                return level + 1

n = int(input())
a = list(map(int, input().split()))

root = Node(a[0])
level_sums = {0: a[0]}
max_level = 0

for x in a[1:]:
    lvl = insert(root, x)
    level_sums[lvl] = level_sums.get(lvl, 0) + x
    if lvl > max_level:
        max_level = lvl

print(max_level + 1)
for i in range(max_level + 1):
    print(level_sums.get(i, 0), end=' ')
