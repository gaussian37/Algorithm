import sys
sys.setrecursionlimit(100000)
read = lambda:sys.stdin.readline().rstrip()
#sys.stdin = open('input.txt', 'r')

# dp(i, j) = i행 j열에서 N행까지 도달할 수 있는 경로 점수의 최대 합
def dp(i, j):
    if i == N - 1:
        return A[i][j]

    if d[i][j] != -1:
        return d[i][j]
    
    d[i][j] = max(dp(i+1, j), dp(i+1, j+1)) + A[i][j]
    return d[i][j]

N = int(read())
A = []
d = [[-1 for _ in range(N+1)] for _ in range(N+1)]
for _ in range(N):
    A.append(list(map(int, read().split())))
    
print("%d\n" % dp(0, 0))
