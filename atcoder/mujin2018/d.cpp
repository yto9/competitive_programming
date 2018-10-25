#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int dp[1000][1000];

int main(int argc, char const *argv[])
{   
    int N,M; cin >> N >> M;
    int r = 12;
    REP(i, 100) {
        REP(j, 100) {
            if (i < 13) dp[i][j] = 0;
            else if (j < 13) dp[i][j] = 0;
            else if (i % 10 == 0) dp[i][j] = 0;
            else if (15 - r <= j && j <= 15 + r && i % 10 == 1) dp[i][j] = 0;
            else if (25 - r <= j && j <= 25 + r && i % 10 == 2) dp[i][j] = 0;
            else if (35 - r <= j && j <= 35 + r && i % 10 == 3) dp[i][j] = 0;
            else if (45 - r <= j && j <= 45 + r && i % 10 == 4) dp[i][j] = 0;
            else if (55 - r <= j && j <= 55 + r && i % 10 == 5) dp[i][j] = 0;
            else if (65 - r <= j && j <= 65 + r && i % 10 == 6) dp[i][j] = 0;
            else if (75 - r <= j && j <= 75 + r && i % 10 == 7) dp[i][j] = 0;
            else if (85 - r <= j && j <= 85 + r && i % 10 == 8) dp[i][j] = 0;
            else if (95 - r <= j && j <= 95 + r && i % 10 == 9) dp[i][j] = 0;
            else dp[i][j] = 7;
        }
    }
    REP (i, 100) {
        REP (j, 100) {
            printf ("%d ", dp[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
