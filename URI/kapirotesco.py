n = int(raw_input())
for x in range(n):
    a = []
    PAU = list(map(str, raw_input().split()))
    NO = []
    for x in PAU:
        a.append(len(x))
    for x in range(len(PAU)):
        NO.append([a[x], PAU[x]])
    NO.sort(reverse=True)
    for x in NO:
        print(x[1]),

