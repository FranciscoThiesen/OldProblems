t = int(raw_input())
q = raw_input()
for x in range(t):
    num = 0
    total = 0
    while(True):
        cur = raw_input()
        if(cur == ''):
            if(total%num == 0):
                print("YES")
            else:
                print("NO")
            break
        else:
            cur = int(cur)
            total = total + cur
            num = num + 1
    
    
