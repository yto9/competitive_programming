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
    int N; cin >> N;
    map<int, int> sorted_mp;
    REP(i, N) {
        int tmp; cin >> tmp;
        sorted_mp.insert(make_pair(tmp, i+1));
    }
    for (auto itr = sorted_mp.begin(); itr != sorted_mp.end(); ++itr) {
        if (itr == sorted_mp.end()) cout << itr->second << endl;
        else cout << itr->second << " ";
    }
    return 0;
}
