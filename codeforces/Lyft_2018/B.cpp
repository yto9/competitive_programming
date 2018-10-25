#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
ll mod_pow(ll x, ll n, ll mod){//x^n % mod
    if (n == 0)
        return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1)
        res = res * x % mod;
    return res;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int t; cin >> t;
    REP(test, t) {
        ll a, b; cin >> a >> b;
        if(a-b != 1) {
            cout << "NO" << endl;
            continue;
        }
        bool pri = true;
        for (ll i = 2; i * i <= a+b; i++) {
            if ((a+b)%i == 0) {
                pri = false;
                break;
            }
        }
        if (pri) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
