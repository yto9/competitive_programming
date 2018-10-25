#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int H, W; cin >> H >> W;
    char board[100][100];
    int I[100] = {};
    int J[100] = {};
    REP(i, H) {
        REP(j,W) {
            cin >> board[i][j];
            if (board[i][j] == '#') {
                I[i]++;
                J[j]++;
            }
        }
    }
    REP(i, H) {
        if (I[i] == 0) continue;
        REP(j, W) {
            if (J[j] == 0) continue;
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
