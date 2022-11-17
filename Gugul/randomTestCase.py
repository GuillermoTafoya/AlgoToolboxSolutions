import pyperclip as p
import random
"""
Assume that:

N is an integer within the range [1..30];
each element of array segments is an integer within the range [1..1,000].
"""
A = []
for i in range(1, 31):
    A.append(random.randint(150, 180))
p.copy(str(A))
[173, 168, 177, 159, 159, 161, 155, 173, 176, 170, 165, 155, 159, 154, 173, 174, 169, 172, 161, 160, 178, 156, 152, 172, 178, 179, 176, 157, 167, 168]