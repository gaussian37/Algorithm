def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

for i in range(int(input())):    
    A = list(map(int, input().split()))    
    s = 0
    for j in range(1, len(A)):
        for k in range(j+1, len(A)):
            s += gcd(A[j], A[k])
    print(s)    