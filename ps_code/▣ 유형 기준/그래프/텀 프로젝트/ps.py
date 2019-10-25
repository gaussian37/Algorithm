import sys
sys.setrecursionlimit(1000000)

def dfs(i, cnt, step):    
    if(visited[i] != 0):
        if(S[i] != step):
            return 0
        return cnt - visited[i]

    visited[i] = cnt    
    S[i] = step
    return dfs(A[i], cnt+1, step)    

A = [0]; visited = [0]; S = [0]    
T = int(input())
while True:
    T -= 1
    if(T < 0):
        break
    
    N = int(input())
    A = [int(i) for i in input().split()]; A = [0] + A
    S = [0] * (N+2)
    visited = [0] * (N+2)
    
    ans = 0
    for i in range(1, N+1):
        if(visited[i] == 0):            
            ans  += dfs(i, 1, i)
                
    print(N - ans)