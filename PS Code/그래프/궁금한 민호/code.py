import sys
N = int(input())
dist = [list(map(int, input().split())) for i in range(N)]
use = [[1 for i in range(N)] for j in range(N)]
for k in range(N):
    for i in range(N):
        for j in range(N):
            if i == k or i == j or j == k:
                continue
            if dist[i][j] > dist[i][k] + dist[k][j]:
                print(-1)
                sys.exit()
            
            if dist[i][j] == dist[i][k] + dist[k][j]:
                use[i][j] = 0
ans = 0
for i in range(N):
    for j in range(N):
        if use[i][j]:
            ans += dist[i][j]

ans /= 2
print(int(ans))