import sys
sys.setrecursionlimit(999999999)
read = lambda:sys.stdin.readline().rstrip()
sys.stdin = open('input.txt', 'r')

def dp(i, j):
    if i == 0:
        if j == 0:
            return 1
        else:
            return 0
    if d[i][j] != -1:
        return d[i][j]

    d[i][j] = 0
    if j == 0:
        d[i][j] += dp(i-1, 0) + dp(i-1, 1) + dp(i-1, 2)
    if j == 1:
        d[i][j] += dp(i-1, 0) + dp(i-1, 2)
    if j == 2:
        d[i][j] += dp(i-1, 0) + dp(i-1, 1)
    d[i][j] %= MOD    
    return d[i][j]

MOD = 9901
N = int(read())
d = [[-1] * 3 for _ in range(N+2)]
print((dp(N,0) + dp(N,1) + dp(N,2)) % MOD)