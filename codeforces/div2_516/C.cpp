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
    int n; cin >> n;
    unordered_map<char,int> ump;
    vector<char> res(n);
    string s;
    cin >> s;
    REP(i, n) {
        ump[s[i]]++;
    }
    int idx = 0;
    for (auto itr = ump.begin(); itr != ump.end(); itr++) {
        for(int pre = idx; idx < pre + itr->second; idx++) {
            res[idx] = itr->first;
        }
    }
    REP(i, n) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
