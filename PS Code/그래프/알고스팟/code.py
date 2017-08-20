from heapq import *

M, N = map(int, input().split())
data = [list(map(int, list(input()))) for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]
dy = [-1, 0, 0, 1]
dx = [0, -1, 1, 0]

pq = [[0, 0, 0]] #[ºÎ¼ø È½¼ö, y, x]
while pq:    
    now = heappop(pq)
    num, y, x = now
    if [y, x] == [N-1, M-1]:
        print(num)
        break
    
    if visited[y][x]:
        continue
    visited[y][x] = 1
    
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if ny >= 0 and nx >= 0 and ny < N and nx < M:
            heappush(pq, [num + data[ny][nx], ny, nx])
