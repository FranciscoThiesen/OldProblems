n = int(raw_input())
a = list(map(int, raw_input().split()))
cp = a[:]
cp2 = a[:]
cp.sort()
cp2.sort(reverse=True)



def get_permutations(L1, L2):
    permutation = map(dict((v,i) for i, v in enumerate(L1)).get, L2)
    assert [L1[p] for p in permutation] == L2
    return permutation

def number_of_swaps(permutation):
    nswaps = 0
    seen = set()
    for i in xrange(len(permutation)):
        if i not in seen:
            j = i
            while permutation[j] != i:
                j = permutation[j]
                seen.add(j)
                nswaps = nswaps + 1
    return nswaps

perm = get_permutations(a, cp)
perm2 = get_permutations(a, cp2)
print(min(number_of_swaps(perm), number_of_swaps(perm2)))

