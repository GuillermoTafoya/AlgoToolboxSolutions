# Generate a random string of lowercase letters of length n
# Copy the result to the clipboard

import random
import pyperclip

def random_string(n):
    s = ''
    for i in range(n):
        s += chr(random.randint(ord('a'), ord('z')))
    return s

if __name__ == '__main__':
    n = 176839#int(input("Enter the length of the random string: "))
    s = random_string(n)
    #print("Random string: ", s)
    pyperclip.copy(s)
    print("Random string copied to clipboard")