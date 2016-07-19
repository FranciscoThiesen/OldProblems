p = 1
caso = 1
while(p != 0):
    p = int(raw_input())
    if p == 0:
        break
    aldo = 0
    beto = 0
    i = 0
    while i < p:
        a,b = map(int, raw_input().split())
        aldo = aldo + a
        beto = beto + b
        i = i + 1
    if(aldo > beto):
        print("Teste %d\nAldo\n") %caso
    else:
        print("Teste %d\nBeto\n") %caso
    caso = caso + 1

