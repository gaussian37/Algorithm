def update(tree, i, diff):
    while i <= N:
        tree[i] += diff
        i+= i&-i

def range_sum(tree, i):
    ans = 0
    while i > 0:
        ans += tree[i]
        i -= i&-i
    return ans

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

pos = {}
for i, num in enumerate(B):
    pos[num] = i+1

ans = 0
tree = [0] * 4* N
for num in A:
    left = pos[num] + 1
    right = N
    ans += range_sum(tree, N) - range_sum(tree, left-1)
    update(tree, pos[num], 1)

print('%d' % ans) 

    