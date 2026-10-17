#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<vector<char>> board = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void printBoard() {
    cout << "\n    a   b   c   d   e   f   g   h\n";
    cout << "  +--------------------------------+\n";
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << " |";
        for (int j = 0; j < 8; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << " " << 8 - i << "\n";
        cout << "  +--------------------------------+\n";
    }
    cout << "    a   b   c   d   e   f   g   h\n\n";
}

bool parseCoord(string s, int &r, int &c) {
    if (s.length() != 2) return false;
    c = s[0] - 'a';
    r = 8 - (s[1] - '0');
    return (r >= 0 && r < 8 && c >= 0 && c < 8);
}

bool movePiece(string from, string to, bool isWhiteTurn) {
    int r1, c1, r2, c2;
    if (!parseCoord(from, r1, c1) || !parseCoord(to, r2, c2)) return false;

    char piece = board[r1][c1];
    
    if (piece == '.' || (isWhiteTurn && !isupper(piece)) || (!isWhiteTurn && !islower(piece))) {
        return false;
    }

    char target = board[r2][c2];
    if (target != '.' && ((isWhiteTurn && isupper(target)) || (!isWhiteTurn && islower(target)))) {
        return false;
    }

    board[r2][c2] = piece;
    board[r1][c1] = '.';
    return true;
}

int main() {
    bool whiteTurn = true;
    string from, to;

    cout << "=== PERMAINAN CATUR SEDERHANA (CLI) ===\n";
    cout << "Format input: ketik posisi awal lalu posisi tujuan (contoh: e2 e4)\n";
    cout << "Ketik 'exit' untuk keluar.\n";

    while (true) {
        printBoard();
        cout << (whiteTurn ? "Giliran Putih (Huruf Besar)" : "Giliran Hitam (Huruf Kecil)") << "\n";
        cout << "Masukkan langkah (cth: e2 e4): ";
        cin >> from;
        if (from == "exit") break;
        cin >> to;

        if (movePiece(from, to, whiteTurn)) {
            whiteTurn = !whiteTurn; 
        } else {
            cout << "[!] Langkah tidak valid! Coba lagi.\n";
        }
    }

    return 0;
}