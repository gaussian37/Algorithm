from itertools import compress
import queue

N = int(input())
work = [0] * (N+1); cost = [0] * (N+1); ind = [0] * (N+1)
AdjList = [[] for i in range(N+1)]

for v in range(1, N+1):
    w, *cand, dump = map(int, input().split())
    work[v] = w
    for u in cand:
        AdjList[u].append(v); ind[v] += 1

q = queue.Queue()
for i in range(1, len(cost)):
    if ind[i] == 0:
        q.put(i); cost[i] = work[i]
    
while not q.empty():
    u = q.get()
    for v in AdjList[u]:
        ind[v] -= 1
        cost[v] = max(cost[v], cost[u] + work[v])
        q.put(v) if ind[v] == 0 else None       

for i in range(1, len(cost)):
    print(cost[i])