from random import *

somaDados = 0
for i in xrange(10 ** 7):
    k = randint(1, 6)
    somaDados = somaDados + k

print(somaDados)
