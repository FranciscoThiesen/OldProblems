from math import *

n = float(raw_input())
n100= n50= n20= n10= n5= n2= m100= m50= m25= m10= m5= m1 = 0
n100 = n/100
n = n%100
    n50 = n/50
    n = n%50
    n20 = n/20
    n = n%20
    n10 = n/10
    n = n%10
    n5 = n/5
    n = n%5
    n2 = n/2
    n = n%2
    m100 = n/1
    n = n%1
    m50 = n/0.5
    n = n%0.5
    m25 = n/25
    n = n%0.25
    m10 = n/0.1
    n = n%0.1
    m5 = n/0.05
    n = n%0.05
    m1 = n/0.01
    n = n%0.01
print("NOTAS:\n%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\nMOEDAS:\n%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n" %  (n100, n50, n20, n10, n5, n2, m100, m50, m25, m10, m5, m1))
  
