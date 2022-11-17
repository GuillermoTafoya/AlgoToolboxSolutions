import pyperclip as pc
import random
s = ""
listSum = 100001
while listSum > 100000:
    for i in range(1000):
        s += str(random.randint(1,200))+","
    s = s[:-1]
    listSum = sum([int(x) for x in s.split(",")])
pc.copy(s)
print(listSum)
