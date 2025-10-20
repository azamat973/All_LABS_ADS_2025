import sys
input=sys.stdin.readline

n=int(input())
from collections import deque,defaultdict

children = {i:[0,0] for i in range(1,n+1)}
for _ in range(n-1):
    x,y,z = map(int,input().split())
    children[x][z]=y

q=deque([(1,0)])
level_count=defaultdict(int)
maxw=0
while q:
    node,lev=q.popleft()
    level_count[lev]+=1
    if level_count[lev]>maxw: maxw=level_count[lev]
    l,r = children[node]
    if l: q.append((l,lev+1))
    if r: q.append((r,lev+1))

print(maxw)