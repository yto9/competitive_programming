#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    vector<string> board(9);
    REP(i,9) {
        string white = ".........";
        board[i] = white;
    }
    board[0][2] = '#';
    board[1][6] = '#';
    board[2][1] = '#';
    board[2][8] = '#';
    board[3][3] = '#';
    board[4][4] = '#';
    board[5][5] = '#';
    board[6][0] = '#';
    board[6][7] = '#';
    board[7][2] = '#';
    board[8][6] = '#';
    REP(i,9) {
        cout << board[i] << endl;
    }
    return 0;
}
