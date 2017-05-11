from math import factorial as fac

def binomial(x,y):
    try:
        binom = fac(x) // fac(y) // fac(x-y)
    except ValueError:
        binom = 0
    return binom


n = int(raw_input())
i = 0

def my_count(string, substring):
    string_size = len(string)
    substring_size = len(substring)
    count = 0
    for i in xrange(0, string_size - substring_size):
        if string[i:i+substring_size] = substring:
            count = count + 1
    return count



for x in range(n):
    big = str(raw_input())
    small = str(raw_input())
    a = big.count(small)#disjoint occurences


