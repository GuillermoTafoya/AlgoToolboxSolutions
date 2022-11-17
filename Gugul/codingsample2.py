"""
We are given a string text of length N consisting of the letters 'a', 'b' or 'c'. We can insert any of those letters before or after any letter in the string.

The goal is to insert letters into text so that it will follow the pattern "abcabca..."; i.e. it should start with a letter 'a', letter 'a' should be followed by 'b', letter 'b' should be followed by 'c', and letter 'c' by 'a'. The string may end with any of those three letters.
"""



# Works with current cases, lets dive into edge cases
# Can the input start with a letter that is not a? NO! <--FIX-->
def solution(S):
    # We define a hash map according to what we expect to find after each letter
    expectatives = {
        'a': 'b',
        'b': 'c',
        'c': 'a'
    }
    # Now we iterate the string just once and count how many times we did not meet the expectations
    count = 0
    currentExpectative = "a"
    i = 0
    while i < len(S):
        while S[i] != currentExpectative:
            count += 1
            currentExpectative = expectatives[currentExpectative]
        currentExpectative = expectatives[currentExpectative]
        i += 1
    return count
if __name__ == '__main__':
    assert solution('aabcc') == 4
    assert solution('abc') == 0
    assert solution('abcabcabca') == 0
    assert solution('ababababab') == 4
    assert solution('c') == 2