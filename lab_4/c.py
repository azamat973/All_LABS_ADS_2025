import sys
sys.setrecursionlimit(10**7)

class Node:
    def __init__(self, x):   
        self.val = x
        self.left = None
        self.right = None

def insert(root, x):
    if root is None:
        return Node(x)
    if x < root.val:
        root.left = insert(root.left, x)
    else:
        root.right = insert(root.right, x)
    return root

def find(root, k):
    if root is None:
        return None
    if root.val == k:
        return root
    if k < root.val:
        return find(root.left, k)
    else:
        return find(root.right, k)

def preorder(root):
    if root is None:
        return
    print(root.val, end=" ")
    preorder(root.left)
    preorder(root.right)

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    n = int(next(it))
    root = None

    for _ in range(n):
        x = int(next(it))
        root = insert(root, x)

    k = int(next(it))
    start = find(root, k)

    preorder(start)

if __name__ == "__main__":  
    main()
