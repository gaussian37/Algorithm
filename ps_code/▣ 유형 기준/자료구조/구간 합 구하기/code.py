import sys
read = lambda:sys.stdin.readline().rstrip()
#sys.stdin = open('input.txt', 'r')

def range_sum(i):
    ans = 0
    while i > 0:
        ans += tree[i]
        i -= i&-i
    return ans
    
def update(i, diff):
    while i <= N:
        tree[i] += diff
        i += i&-i


N, M, K = map(int, read().split())

A = [0] * (N+10)
tree = [0] * (N+10)
for i in range(1, N+1):
    n = int(read())
    A[i] = n    
    update(i, n)
    
for _ in range(M+K):
    a, b, c = map(int, read().split())
    if a is 1:
        diff = c - A[b]
        A[b] = c
        update(b, diff)
    elif a is 2:
        print('%d' % (range_sum(c) - range_sum(b-1)))