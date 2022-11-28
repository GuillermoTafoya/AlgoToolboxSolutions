#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

/*
1. Write a program that exhaustively searches the tic-tac-toe game tree and counts
the number of times X wins, 0 wins, and the game ends in a draw. What are those amounts?
And what is the total number of possible games? Do the numbers give advantage to one player or the other?
*/

class Board {
    public:
    Board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    Board(const Board& b) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = b.board[i][j];
            }
        }
    }

    char get(int i, int j) const {
        return board[i][j];
    }

    bool set(int i, int j, char c) {
        if (board[i][j] != ' ') return false;
        board[i][j] = c;
        return true;
    }

    bool isWin(char c) const {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
        return false;
    }

    bool isDraw() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    void print() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }

private:
    char board[3][3];
};

void search(const Board& board, char player, int& xWins, int& oWins, int& draws) {
    if (board.isWin('X')) {
        xWins++;
        return;
    }
    if (board.isWin('O')) {
        oWins++;
        return;
    }
    if (board.isDraw()) {
        draws++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.get(i, j) != ' ') continue;
            Board b(board);
            b.set(i, j, player);
            search(b, player == 'X' ? 'O' : 'X', xWins, oWins, draws);
        }
    }
}

int main() {
    Board board;
    int xWins = 0;
    int oWins = 0;
    int draws = 0;
    search(board, 'X', xWins, oWins, draws);
    cout << "X wins: " << xWins << endl;
    cout << "O wins: " << oWins << endl;
    cout << "Draws: " << draws << endl;
    cout << "Total: " << xWins + oWins + draws << endl;
    return 0;
}
