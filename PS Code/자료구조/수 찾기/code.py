N = input()
s = set(input().split())
M = input()

print('\n'.join([str(1) if x in s else str(0) for x in input().split()]))
        