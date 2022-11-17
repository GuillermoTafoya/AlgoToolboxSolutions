import sys

def solution(A):
  # We optimize the previous solution by using bitmasking
  # We first get the total sum of the values
  total = sum(A)
  # Now we can keep track of the two computers by substracting from the total
  # We keep the lowest of those iterations
  minDiff = float("inf")
  for i in range(1, 2**len(A)):
    sum1 = 0
    for j in range(len(A)):
      if i & (1 << j):
        sum1 += A[j]
    minDiff = min(minDiff, abs(total-2*sum1))
    if minDiff == 0:
      return 0
  return minDiff

def main():
  """Read from stdin, solve the problem, write answer to stdout."""
  A = [int(x) for x in input().split(",")]
  sys.stdout.write(str(solution(A)))


if __name__ == "__main__":
  main()