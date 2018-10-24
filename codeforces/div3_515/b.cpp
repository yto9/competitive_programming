#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
// ll mod_pow(ll x, ll n, ll mod){//x^n % mod
//     if (n == 0)
//         return 1;
//     ll res = mod_pow(x * x % mod, n / 2, mod);
//     if (n & 1)
//         res = res * x % mod;
//     return res;
// }
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n, r; cin >> n >> r;
    vector<int> h(n);
    vector<int> v(n);
    REP(i, n) {
        cin >> h[i];
        v[i] = 0;
    }
    int i = 0;
    int res = 0;
    while(i < n) {
        if (v[i] == 0) {
            int current = i;
            for (int j = min(i + r - 1,n-1); j >= max(0, i - r + 1);j--) {
                if (h[j] == 1) {
                    for (; i <= min(j + r - 1,n-1); i++) {
                        v[i] = 1;
                    }
                    res++;
                    break;
                }
            }
            if (v[current] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
        else {
            i++;
        }
    }
    cout << res << endl;
    return 0;
}
