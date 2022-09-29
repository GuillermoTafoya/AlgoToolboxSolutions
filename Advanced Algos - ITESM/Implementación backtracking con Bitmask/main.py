def solve(caps,n):
    ans = []
    def backtrack(mask, caps, n, i, curr):
        if i == n:
            ans.append(tuple(curr))
            return
        for cap in caps[i]:
            if mask & (1 << cap) == 0:
                curr.append(cap)
                backtrack(mask | (1 << cap), caps, n, i + 1, curr)
                curr.pop()
    backtrack(0, caps, n, 0, [])
    return ans


if __name__ == "__main__":
    n = int(input())
    caps = []
    for i in range(n):
        caps.append(list(map(int, input().split())))
    ans = solve(caps, n)
    print(len(ans))
    for i in ans:
        print(i)