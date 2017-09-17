import sys
read = lambda:sys.stdin.readline().rstrip()
sys.setrecursionlimit(1000000)
#sys.stdin = open('input.txt', 'r')

def dp(i, j):
    if i == 0 :
        return A[i][j]
    if dp_t[i][j] != -1 :
        return dp_t[i][j]
    dp_t[i][j] = 1e9
    
    if j == 0:
        dp_t[i][j] = min(dp(i-1, 1), dp(i-1, 2)) + A[i][0]        
    elif j == 1:
        dp_t[i][j] = min(dp(i-1, 0), dp(i-1, 2)) + A[i][1]
    elif j == 2:
        dp_t[i][j] = min(dp(i-1, 0), dp(i-1, 1)) + A[i][2]
    return dp_t[i][j]
        

N = int(read())
A = [list(map(int, read().split())) for _ in range(N)]
dp_t = [[-1 for _ in range(N + 2)] for _ in range(N+2)]

print('%d' % ((min(dp(N-1, 0), dp(N-1, 1), dp(N-1, 2)))))