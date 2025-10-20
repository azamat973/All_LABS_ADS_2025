class Node:
    __slots__ = ('v', 'l', 'r')
    def __init__(self, v):
        self.v = v
        self.l = None
        self.r = None

def insert(root, x):
    if x < root.v:
        if root.l:
            insert(root.l, x)
        else:
            root.l = Node(x)
    else:
        if root.r:
            insert(root.r, x)
        else:
            root.r = Node(x)

import sys
input = sys.stdin.readline

n = int(input().strip())
a = list(map(int, input().split()))

root = Node(a[0])
for x in a[1:]:
    insert(root, x)

stack = [root]
cnt = 0
while stack:
    nd = stack.pop()
    if nd.l and nd.r:
        cnt += 1
    if nd.l:
        stack.append(nd.l)
    if nd.r:
        stack.append(nd.r)

print(cnt)
