import sys
N, M = map(int, input().split())
dist = [[float('inf') for i in range(N+2)] for j in range(N+2)]
for i in range(M):
    u, v, w = map(int, input().split())
    dist[u][v] = w

for k in range(1, N+1):
    for i in range(1, N+1):        
        for j in range(1, N+1):
            if dist[i][k] == float('inf') or dist[k][j] == float('inf'):
                continue
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
            
ans = float('inf')
for i in range(1, N+1):
    ans = min(ans, dist[i][i])

print(-1 if ans == float('inf') else ans)