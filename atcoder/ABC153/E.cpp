#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define NUM_M 1000
#define MAX_H 10000
typedef long long ll;
int dp[MAX_H + 1]; // dp[i+1][j] -> i番目までの魔法でダメージがj(以上?)になるように選んだ時の魔力消費の最小値
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int H, N; cin >> H >> N;
    vector<int> damage;
    vector<int> mp;
    REP(i, N) {
        int tmp_d, tmp_m; cin >> tmp_d >> tmp_m;
        damage.push_back(tmp_d);
        mp.push_back(tmp_m);
    }
    int INF = 1000000000; // A_i >= 1 H<= 10^4 より　B_i(max) 10^4 * H は越えない
    REP(j, MAX_H + 1) dp[j] = INF;
    dp[0] = 0;
    REP(i, N) {
        REP(j, MAX_H + 1) {
            int j_i = max(j-damage[i], 0);
            dp[j] = min(dp[j], dp[j_i] + mp[i]);
        }
    }
    cout << dp[H] << endl;
    return 0;
}
