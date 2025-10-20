import sys
from collections import deque

it = iter(list(map(int, sys.stdin.read().split())))
k = next(it)
n = (1 << k) - 1
arr = [next(it) for _ in range(n)]
arr.sort()

class Node:
    __slots__ = ('v', 'l', 'r')  # ✅ дұрыс синтаксис
    def __init__(self, v):       # ✅ init алдында екі қос сызықша керек
        self.v = v
        self.l = None
        self.r = None

def build(l, r):
    if l > r:
        return None
    m = (l + r) // 2
    node = Node(arr[m])
    node.l = build(l, m - 1)
    node.r = build(m + 1, r)
    return node

root = build(0, n - 1)

q = deque([root])
res = []
while q:
    node = q.popleft()
    res.append(str(node.v))
    if node.l:
        q.append(node.l)
    if node.r:
        q.append(node.r)

print(" ".join(res))  
