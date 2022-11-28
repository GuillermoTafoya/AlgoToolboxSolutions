
/*
2. Modify the programs written for Exercise 1 so that the user can place one
or more starting pieces on a tic-tac-toe board and then count the number of times X wins,
0 wins, and is tied from that point. How many total games are possible from each of
X's nine initial moves? (Do you need to calculate all nine?)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

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
        cout << "  0 1 2" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    private:
    char
        board[3][3];
};

void play(Board& board, char c) {
    if (board.isWin('X')) {
        cout << "X wins" << endl;
        return;
    }
    if (board.isWin('0')) {
        cout << "0 wins" << endl;
        return;
    }
    if (board.isDraw()) {
        cout << "Draw" << endl;
        return;
    }
    board.print();
    int i, j;
    cout << "Enter row and column: ";
    cin >> i >> j;
    if (!board.set(i, j, c)) {
        cout << "Illegal move" << endl;
        return;
    }
    play(board, c == 'X' ? '0' : 'X');
}

void setInitialPieces(Board& board, char c) {
    int i, j;
    cout << "Enter row and column: ";
    cin >> i >> j;
    if (!board.set(i, j, c)) {
        cout << "Illegal move" << endl;
        return;
    }
    cout << "Do you want to place another piece? (y/n): ";
    char answer;
    cin >> answer;
    if (answer == 'y') {
        setInitialPieces(board, c);
    }
}

void play(Board& board, char c, map<string, int>& results) {
    if (board.isWin('X')) {
        results["X wins"]++;
        return;
    }
    if (board.isWin('0')) {
        results["0 wins"]++;
        return;
    }
    if (board.isDraw()) {
        results["Draw"]++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.get(i, j) == ' ') {
                Board b(board);
                b.set(i, j, c);
                play(b, c == 'X' ? '0' : 'X', results);
            }
        }
    }
}

int main() {
    Board board;
    setInitialPieces(board, 'X');
    board.print();
    map<string, int> results;
    play(board, '0', results);
    for (map<string, int>::iterator it = results.begin(); it != results.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    return 0;
}