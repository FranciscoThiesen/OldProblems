from math import *
t = int(raw_input())
for x in range(t):
    s, sg, fg, d, t = map(int, raw_input().split())
    mps =float(float(d*50)/t);
    ns = float(s + (mps*3.6))
    if abs(sg - ns) < abs(fg-ns):
        print("SEBI")
    elif abs(fg - ns) < abs(sg - ns):
        print("FATHER")
    else:
        print("DRAW")
