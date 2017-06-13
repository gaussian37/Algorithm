# https://www.acmicpc.net/problem/1463
n = int(input())
dp = [int(0) for x in range(n+1)]

dp[1] = 0
for i in range(2, n+1):
    dp[i] = dp[i-1] + 1
    if (i % 3 == 0 and dp[i] > dp[i//3] + 1):
        dp[i] = dp[int(i/3)] + 1
    elif(i % 2 == 0 and dp[i] > dp[i//2] + 1):
        dp[i] = dp[int(i/2)] + 1
        
print(dp[n])      
        
        