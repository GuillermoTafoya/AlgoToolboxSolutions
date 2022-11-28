/*
Write a program that allows the player to play tic-tac-toe against the computer.
The player can be either X or 0. Provide three skill levels:
Random (computer moves randomly),
Beginner (computer uses minimax with only three levels of recursion),
and Expert (computer uses full mini-max search ).
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <random>

using namespace std;

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

int minimax(const Board& board, char player, int depth, int alpha, int beta) {
    if (board.isWin('X')) return 10 - depth;
    if (board.isWin('O')) return depth - 10;
    if (board.isDraw()) return 0;

    if (player == 'X') {
        int best = -100;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.get(i, j) == ' ') {
                    Board b(board);
                    b.set(i, j, player);
                    int value = minimax(b, 'O', depth + 1, alpha, beta);
                    best = max(best, value);
                    alpha = max(alpha, best);
                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    }
    else {
        int best = 100;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.get(i, j) == ' ') {
                    Board b(board);
                    b.set(i, j, player);
                    int value = minimax(b, 'X', depth + 1, alpha, beta);
                    best = min(best, value);
                    beta = min(beta, best);
                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    }
}

int main() {
    Board board;
    board.print();
    char player = 'X';
    while (true) {
        if (player == 'X') {
            int i = 0;
            int j = 0;
            cout << "Enter row and column: ";
            cin >> i >> j;
            board.set(i, j, player);
            board.print();
            if (board.isWin('X')) {
                cout << "X wins" << endl;
                return 0;
            }
            if (board.isDraw()) {
                cout << "Draw" << endl;
                return 0;
            }
            player = 'O';
        }
        else {
            int bestScore = -100;
            int bestI = 0;
            int bestJ = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board.get(i, j) == ' ') {
                        Board b(board);
                        b.set(i, j, player);
                        int score = minimax(b, 'X', 0, -100, 100);
                        if (score > bestScore) {
                            bestScore = score;
                            bestI = i;
                            bestJ = j;
                        }
                    }
                }
            }
            board.set(bestI, bestJ, player);
            board.print();
            if (board.isWin('O')) {
                cout << "O wins" << endl;
                return 0;
            }
            if (board.isDraw()) {
                cout << "Draw" << endl;
                return 0;
            }
            player = 'X';
        }
    }
}
