def searchNeighbours(matrix,i,j,queue):
    #cardinal
    if i > 0:
        if matrix[i-1][j] == 1:
            queue.append((i-1,j))
    if i < len(matrix)-1:
        if matrix[i+1][j] == 1:
            queue.append((i+1,j))
    if j > 0:
        if matrix[i][j-1] == 1:
            queue.append((i,j-1))
    if j < len(matrix[0])-1:
        if matrix[i][j+1] == 1:
            queue.append((i,j+1))
    #diagonal
    if i > 0 and j > 0:
        if matrix[i-1][j-1] == 1:
            queue.append((i-1,j-1))
    if i < len(matrix)-1 and j < len(matrix[0])-1:
        if matrix[i+1][j+1] == 1:
            queue.append((i+1,j+1))
    if i > 0 and j < len(matrix[0])-1:
        if matrix[i-1][j+1] == 1:
            queue.append((i-1,j+1))
    if i < len(matrix)-1 and j > 0:
        if matrix[i+1][j-1] == 1:
            queue.append((i+1,j-1))
def solve(matrix):
    visited = [[False for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    maxIsland = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if visited[i][j]:
                continue
            if matrix[i][j] == 1:
                maxIsland = max(maxIsland,helper(matrix,visited,i,j))
    return maxIsland
def helper(matrix,visited,i,j):
    queue = []
    current = 0
    queue.append((i,j))
    while queue:
        i,j = queue.pop(0)
        if visited[i][j]:
            continue
        visited[i][j] = True
        current += 1
        searchNeighbours(matrix,i,j,queue)
    return current
if __name__ == "__main__":
    with open("maximal_mexican_mates_output.txt", "w") as f:
        f.write("")
    with open("maximal_mexican_mates_input.txt", "r") as f:
        testcases = int(f.readline())
        for i in range(testcases):
            n = int(f.readline())
            m = int(f.readline())
            matrix = []
            for j in range(n):
                matrix.append(list(map(int,f.readline().split())))
            with open("maximal_mexican_mates_output.txt", "a") as f2:
                f2.write("Case #" + str(i+1) + ": " + str(solve(matrix)) + "\n")
    print("Done")
