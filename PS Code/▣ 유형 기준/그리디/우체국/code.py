import bisect
N = int(input())
total, A, B = 0, [], []
for i in range(N):
    a, b = map(int, input().split())
    A.append((a, b))    
    total += A[-1][1]    
A.sort()
B = [A[0][1]]
for i in range(1, len(A)):
    B.append(B[i-1] + A[i][1])
    
total //= 2
idx = int(bisect.bisect_left(B, total))

print(A[idx][0])