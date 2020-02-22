    #include <bits/stdc++.h>
     
    using namespace std; 
    #define REP(i, n) for (int i = 0; i < (n); i++)
    #define NUM_M 1000
    #define MAX_H 10000
    typedef long long ll;
    ll dp[NUM_M + 1][MAX_H + 1]; // dp[i+1][j] -> i番目までの魔法でダメージがj(以上?)になるように選んだ時の魔力消費の最小値
    int main(int argc, char const *argv[])
    {
        cin.tie(0);
       	ios::sync_with_stdio(false);
        ll H, N; cin >> H >> N;
        vector<ll> damage;
        vector<ll> mp;
        REP(i, N) {
            ll tmp_d, tmp_m; cin >> tmp_d >> tmp_m;
            damage.push_back(tmp_d);
            mp.push_back(tmp_m);
        }
        ll INF = 1000000000; // A_i >= 1 H<= 10^4 より　B_i(max) 10^4 * H は越えない
        REP(i, NUM_M + 1) {
            REP(j, MAX_H + 1) {
                dp[i][j] = INF;
            }
        }
        REP(i, NUM_M + 1) {
            dp[i][0] = 0;
        }
        REP(i, N) {
            REP(j, MAX_H + 1) {
                if(j == 0) continue;
                int j_i = max(j-(int)damage[i], 0);
                if (i == 0) {
                    dp[i][j] = dp[i][j_i] + mp[i];
                }
                else dp[i][j] = min(dp[i-1][j], min(dp[i][j_i] + mp[i], dp[i-1][j_i] + mp[i]));
            }
        }
        cout << dp[N-1][H] << endl;
        return 0;
    }