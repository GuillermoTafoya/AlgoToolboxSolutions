import sys

def solution(A):
  # We begin defining a list of rows, we only keep track of the lowest
  # We substitute the row with the closest number, such that this numbers is still bigger
  currentRows = []
  for element in A:
    idx = closestIndex(currentRows,element)
    if idx != -1:
      currentRows[idx] = element
    else:
      currentRows.append(element)
  return len(currentRows)

def closestIndex(currentRows,target):
  closest = 10000
  closest_idx = 0
  for idx,candidate in enumerate(currentRows):
    diff = candidate - target
    if candidate > target and closest > diff:
      closest = diff
      closest_idx = idx
  return closest_idx if closest != 10000 else -1


def main():
  """Read from stdin, solve the problem, write answer to stdout."""
  input = sys.stdin.readline().split()
  A = [int(x) for x in input[0].split(",")]
  sys.stdout.write(str(solution(A)))


if __name__ == "__main__":
  main()