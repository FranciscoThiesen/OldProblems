def bs(l, h, n, m):
    lo = l
    hi = h
    while lo < hi:
        #print(lo, hi)
        mid = (hi + lo)/2
        #print(m+1, m + mid)
        #print(val, n +(mid-1)*m)
        val = m + mid
        #print(val, n-(mid-1))
        if val >= n - (mid - 1):
            hi = mid
        else:
            lo = mid + 1
    if m + lo < n - lo + 1:
        return hi
    return lo

n, m = map(int, raw_input().split())
m = min(n, m)
if( n <= m + 1):
    print(n)
else :
    k = n
    print(bs(1, k, n, m) + m)
