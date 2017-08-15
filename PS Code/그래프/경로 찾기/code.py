N = int(input())
AdjMat = [list(map(int, input().split())) for i in range(N)]

for k in range(N):
    for j in range(N):
        for i in range(N):
            if AdjMat[i][j] == 0:
                AdjMat[i][j] = AdjMat[i][k] * AdjMat[k][j]

for i in range(N):
    for j in range(N):
        print(AdjMat[i][j], end = ' ')
    print()     