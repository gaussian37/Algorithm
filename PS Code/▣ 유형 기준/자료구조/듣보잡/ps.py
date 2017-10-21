N, M = map(int, input().split())
s = set()
for i in range(N):
    s.add(input())

candi = []
for i in range(M):
    temp = input()
    if(temp in s):
        candi.append(temp)

candi.sort()
print(len(candi))
for ans in candi:
    print(ans)