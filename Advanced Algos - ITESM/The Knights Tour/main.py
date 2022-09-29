# Given an integer N, print a possible solution to the knights tour problem.

# Input : 
# N = 8
# Output:
# 0 59 38 33 30 17 8 63
# 37 34 31 60 9 62 29 16
# 58 1 36 39 32 27 18 7
# 35 48 41 26 61 10 15 28
# 42 57 2 49 40 23 6 19
# 47 50 45 54 25 20 11 14
# 56 43 52 3 22 13 24 5
# 51 46 55 44 53 4 21 12

from array import array


def print_matrix(matrix)->None:
    # Print the matrix
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            print(matrix[i][j],end=" ")
        print()
def solve(N):
    if N%2 != 0:
        print("No solution")
        return None
    if N in [1,2,4]:
        print("No solution")
        return None
    board = [[0 for i in range(N)] for j in range(N)]
    # Try diferent starting points
    for i in range(N):
        for j in range(N):
            # Warnsdorff’s  algorithm
            # 1. Find the position with the fewest number of possible moves
            # 2. Move to that position
            # 3. Repeat until all squares are visited
            # 4. If no more moves are possible, backtrack
            # 5. If all squares are visited, stop
            wandorff(board,i,j,0)
row = [-2,-1,1,2,2,1,-1,-2]
col = [1,2,2,1,-1,-2,-2,-1]
def wandorff(board,i,j,move):
    # Check if the move is valid
    if i < 0 or i >= len(board) or j < 0 or j >= len(board) or board[i][j] != 0:
        return False
    # If the move is valid, make the move
    board[i][j] = move
    # If all the moves are done, print the board
    if move == len(board)**2-1:
        print_matrix(board)
        return True
    # Try all the possible moves
    for k in range(8):
        if wandorff(board,i+row[k],j+col[k],move+1):
            return True
    # If no move is possible, backtrack
    board[i][j] = 0
    return False

if __name__ == "__main__":
    N = int(input())
    board = solve(N)
    if board:
        print_matrix(board)