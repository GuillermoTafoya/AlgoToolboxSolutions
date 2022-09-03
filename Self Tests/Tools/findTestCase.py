# Find the n test case, reading input from a file
# and writing output to a file.

import sys
import os
import re

# The input starts with t, the number of test cases
# The next t lines contain the test cases

# Each test case contains an integer n
# Followed by n lines of input of n length strings

def find_test(n, txt):
    currentTestCase=0
    for line in txt:
        # If the line starts with a number, it's a test case
        if re.match(r'^\d+$', line):
            currentTestCase += 1
            if currentTestCase == n:
                # Return the line number of the test case
                return txt.index(line)

def main():
    # Read the input file
    with open("input10.txt", 'r') as f:
        txt = f.readlines()
    # Find the test case
    n = 80
    line = find_test(n, txt)
    print("Test case {} starts on line {}".format(n, line))
    # Write the output to a file
    with open("outputfile.txt", 'w') as f:
        f.write(str(line))

if __name__ == "__main__":
    main()