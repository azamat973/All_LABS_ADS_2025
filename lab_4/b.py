class Node:
    def __init__(self, v):
        self.v = v
        self.l = None
        self.r = None

def insert(root, x):
    if root is None:
        return Node(x)
    if x < root.v:
        root.l = insert(root.l, x)
    elif x > root.v:
        root.r = insert(root.r, x)
    return root

def find(root, x):
    while root:
        if root.v == x:
            return root
        root = root.l if x < root.v else root.r
    return None

def size(root):
    if not root:
        return 0
    return 1 + size(root.l) + size(root.r)

n = int(input())
a = list(map(int, input().split()))
x = int(input())
root = None
for v in a:
    root = insert(root, v)
node = find(root, x)
print(size(node))
