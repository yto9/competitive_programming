#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
#define MOD 1000000007
#define MAX 5100000

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    COMinit();
    ll N; cin >> N;
    string S; cin >> S;
    vector<int> v;
    ll res = 0;
    REP(i, N-1){
        int c1 = S[i] - '0';
        int c2 = S[i+1] - '0';
        v.push_back(abs(c1 - c2));
    }
    REP(i, N-1) {
        if (COM(N-2,i) % 2) {
            continue;
        }
        else {
            if (res % 3 == v[i] % 3) {
                res = 0;
            }
            else {
                if (res % 2 == 1 && v[i] % 2 == 1) {
                    res = 0;
                }
                else if (res % 2 == 1 || v[i] %2 == 1){
                    res = 1;
                }
                else if (res == v[i]) {
                    res = 0;
                }
                else {
                    res = 2;
                }  
            }
        }
    }
    cout << res << endl;
    return 0;
}
