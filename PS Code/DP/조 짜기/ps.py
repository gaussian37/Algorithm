
def solve(i):    
    if(i == 0):
        return 0
    if(dp[i] != -1):
        return dp[i]
    
    dp[i] = 0
    mmax = -1
    mmin = 10**9
    
    for j in range(i, 0, -1):
        mmax = max(mmax, A[j])
        mmin = min(mmin, A[j])
        dp[i] = max(dp[i], solve(j-1) + (mmax - mmin))
    
    return dp[i]
    

N = int(input())
A = [0] * (N+5)
A[1:] = [int(i) for i in input().split()]
dp = [-1] * (N+5)

print(solve(N))