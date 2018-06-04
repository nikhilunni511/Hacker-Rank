#include <bits/stdc++.h>

using namespace std;

bool check(const vector<vector<char> >& board)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'N') {
                for (int dx : { -2, -1, 1, 2 })
                    for (int dy : { -2, -1, 1, 2 })
                        if (abs(dx) != abs(dy)) {
                            int x = i + dx, y = j + dy;
                            if (x < 0 || x >= 8 || y < 0 || y >= 8)
                                continue;
                            if (board[x][y] == 'k')
                                return true;
                        }
            }
            else if (board[i][j] == 'P') {
                int x = i - 1;
                for (int y : { j - 1, j + 1 })
                    if (x >= 0 && y >= 0 && y < 8) {
                        if (board[x][y] == 'k')
                            return true;
                    }
            }
            if (board[i][j] == 'R' || board[i][j] == 'Q') {
                for (int dx : { -1, 0, 1 })
                    for (int dy : { -1, 0, 1 })
                        if (abs(dx) != abs(dy)) {
                            for (int x = i + dx, y = j + dy; x >= 0 && x < 8 && y >= 0 && y < 8; x += dx, y += dy) {
                                if (board[x][y] == 'k')
                                    return true;
                                if (board[x][y] != '#')
                                    break;
                            }
                        }
            }
            if (board[i][j] == 'B' || board[i][j] == 'Q') {
                for (int dx : { -1, 1 })
                    for (int dy : { -1, 1 }) {
                        for (int x = i + dx, y = j + dy; x >= 0 && x < 8 && y >= 0 && y < 8; x += dx, y += dy) {
                            if (board[x][y] == 'k')
                                return true;
                            if (board[x][y] != '#')
                                break;
                        }
                    }
            }
        }
    }
    return false;
}

int waysToGiveACheck(const vector<vector<char> >& board)
{
    int res = 0;
    string v = "QRBN";
    for (int i = 0; i < 8; ++i)
        if (board[1][i] == 'P' && board[0][i] == '#') {
            auto b = board;
            b[1][i] = '#';
            for (char c : v) {
                b[0][i] = c;
                res += check(b);
            }
        }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        vector<vector<char> > board(8, vector<char>(8));
        for (int board_i = 0; board_i < 8; board_i++) {
            for (int board_j = 0; board_j < 8; board_j++) {
                cin >> board[board_i][board_j];
            }
        }
        int result = waysToGiveACheck(board);
        cout << result << endl;
    }
    return 0;
}
