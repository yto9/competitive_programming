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
    int l, r; cin >> l >> r;
    for(int x = l; x<=r; x++) {
        map<string,int> mp;
        mp[to_string(x % 10)]++;
        if (x >= 10) {
            mp[to_string((x/10)%10)]++;
        }
        if (x >= 100) {
            mp[to_string((x/100)%10)]++;
        }
        if (x >= 1000) {
            mp[to_string((x/1000)%10)]++;
        }
        if (x >= 10000) {
            mp[to_string((x/10000)%10)]++;
        }
        if (x >= 100000) {
            mp[to_string((x/100000)%10)]++;
        }
        bool ans = true;
        for (auto d: mp){
            if (d.second > 1) ans = false;
        }
        if(ans) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
