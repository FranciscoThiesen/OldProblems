from math import *


def play(piles, player):
    if len(piles) == 1:
        return True
    if len(piles) == 2:
        x = piles[0] ^ piles[1]
        if x == 0:
            return False
        if x != 0:
            return True
    
        
t = int(raw_input())
for x in range(t):
    n = int(raw_input())
