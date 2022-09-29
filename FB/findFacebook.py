# Find if facebook is contained in a string
def solve(string):
    target = "facebook"
    currentCharTarget = 0
    for i in range(len(string)):
        if string[i] == target[currentCharTarget]:
            currentCharTarget += 1
        if currentCharTarget == len(target):
            return "YES"
    return "NO"

if __name__ == "__main__":
    with open("finding_facebook_output.txt", "w") as f:
        f.write("")
    with open("finding_facebook_input.txt", "r") as f:
        t = int(f.readline())
        for i in range(t):
            line = f.readline()
            with open("finding_facebook_output.txt", "a") as f2:
                f2.write("Case #" +str(i+1) + ": " + solve(line) + "\n")
    print("Done")