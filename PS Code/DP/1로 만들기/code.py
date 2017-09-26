import sys
sys.setrecursionlimit(999999999)
read = lambda:sys.stdin.readline().rstrip()
#sys.stdin = open('input.txt', 'r')

N = int(read())
d = [0] * (N+2)

for i in range(2, N+1):
    d[i] = d[i-1] + 1
    d[i] = min(d[i], d[i//2] + 1) if i%2==0 else d[i]
    d[i] = min(d[i], d[i//3] + 1) if i%3==0 else d[i]

print('%d\n' % d[N])