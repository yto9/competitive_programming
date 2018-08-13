#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    char board[4][4];
    REP(i, 4){
        REP(j, 4) {
            cin >> board[i][j];
        }
    }
    REP(i, 4){
        REP(j, 4){
            cout << board[3 - i][3 - j];
            if (j != 3) cout << " ";
        }
        cout << endl;
    } 
    return 0;
}
