import random
 
def partition(vector, left, right, pivotIndex):
    pivotValue = vector[pivotIndex]
    vector[pivotIndex], vector[right] = vector[right], vector[pivotIndex]  # Move pivot to end
    storeIndex = left
    for i in range(left, right):
        if vector[i] < pivotValue:
            vector[storeIndex], vector[i] = vector[i], vector[storeIndex]
            storeIndex += 1
    vector[right], vector[storeIndex] = vector[storeIndex], vector[right]  # Move pivot to its final place
    return storeIndex
 
def _select(vector, left, right, k):
    "Returns the k-th smallest, (k >= 0), element of vector within vector[left:right+1] inclusive."
    while True:
        pivotIndex = random.randint(left, right)     # select pivotIndex between left and right
        pivotNewIndex = partition(vector, left, right, pivotIndex)
        pivotDist = pivotNewIndex - left
        if pivotDist == k:
            return vector[pivotNewIndex]
        elif k < pivotDist:
            right = pivotNewIndex - 1
        else:
            k -= pivotDist + 1
            left = pivotNewIndex + 1
 
def select(vector, k, left=None, right=None):
    """\
    Returns the k-th smallest, (k >= 0), element of vector within vector[left:right+1].
    left, right default to (0, len(vector) - 1) if omitted
    """
    if left is None:
        left = 0
    lv1 = len(vector) - 1
    if right is None:
        right = lv1
    assert vector and k >= 0, "Either null vector or k < 0 "
    assert 0 <= left <= lv1, "left is out of range"
    assert left <= right <= lv1, "right is out of range"
    return _select(vector, left, right, k)
 
if __name__ == '__main__':
    n, d = map(int, raw_input().split())
    a = map(int, raw_input().split())
    arr = []
    ans = 0
    median = 0
    for x in a:
        if len(arr) == d:
            if d%2 == 0:
                media = select(arr, d/2) + select(arr, d/2 + 1)
                media = media/2.0
            else:
                media = select(arr,d/2)
            if x >= 2*media:
                ans = ans + 1
            arr.pop(0)
        arr.append(x)
    print(ans)