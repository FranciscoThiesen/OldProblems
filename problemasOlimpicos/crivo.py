from math import sqrt

maior_num = int(input("Escolha ate qual numero voce quer achar primos: "))
raiz = sqrt(maior_num)
nums = []

for num in range(2, maior_num + 1):
    nums.append(num)

for num in nums:
    if num == 2:
        pass
    elif num % 2 == 0:
        nums.remove(num)
for num in nums:
    if num == 3:
        pass
    elif num % 3 == 0:
        nums.remove(num)
for num in nums:
    if num == 5:
        pass
    elif num % 5 == 0:
        nums.remove(num)

print(nums)