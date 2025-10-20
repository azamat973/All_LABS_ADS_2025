import sys
sys.setrecursionlimit(10**7)

class Node:
    def __init__(self, x):  
        self.val = x
        self.left = None
        self.right = None

def insert(root, x):
    if not root:
        return Node(x)
    if x < root.val:
        root.left = insert(root.left, x)
    else:
        root.right = insert(root.right, x)
    return root

total = 0

def convert_to_gst(root):
    global total
    if not root:
        return
    convert_to_gst(root.right)
    total += root.val
    root.val = total
    convert_to_gst(root.left)

def inorder(root, result):
    if not root:
        return
    inorder(root.left, result)
    result.append(root.val)
    inorder(root.right, result)

n = int(sys.stdin.readline())
values = list(map(int, sys.stdin.readline().split()))

root = None
for v in values:
    root = insert(root, v)

convert_to_gst(root)

result = []
inorder(root, result)
print(*result)
