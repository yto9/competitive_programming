#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define EPS 1e-9
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
    ll a,b; cin >> a >> b;
    double dN = sqrt(1+8*(a+b))/2.0 - 0.5;
    int N = (abs(round(dN)-dN) < EPS) ? round(dN): floor(dN);
    vector<int> minv;
    int smaller = min(a,b);
    int idx = N;
    while(smaller != 0&&idx>0) {
        if (smaller>=idx) {
            minv.push_back(idx);
            smaller -= idx;
            idx--;
        }
        else {
            minv.push_back(smaller);
            smaller -= smaller;
        }
    }
    int s_minv = (int) minv.size();
    if (a == min(a,b)) {
        cout << s_minv << endl;
        for (int i = 0; i < s_minv ; i++) {
            if (i != s_minv-1) cout << minv[i] << " ";
            else cout << minv[i];
        }
        cout << endl;
        cout << N - s_minv << endl;
        int mi = 0;
        int num = N - s_minv;
        for (int i = N; i > 0; i--) {
            if (mi == s_minv ) {
                num--;
                if (num != 0) cout << i << " ";
                else cout << i;
            }
            else if (i != minv[mi]) {
                num--;
                if (num != 0) cout << i << " ";
                else cout << i;
            }
            else {
                mi++;
            }
        }
        cout << endl;
    }
    else {
        cout << N - s_minv << endl;
        int mi = 0;
        int num = N - s_minv;
        for (int i = N; i > 0; i--) {
            if (mi == s_minv) {
                num--;
                if (num != 0) cout << i << " ";
                else cout << i;
            }
            else if (i != minv[mi]) {
                num--;
                if (num != 0) cout << i << " ";
                else cout << i;
            }
            else {
                mi++;
            }
        }
        cout << endl;
        cout << s_minv << endl;
        for (int i = 0; i < s_minv ; i++) {
            if (i != s_minv-1) cout << minv[i] << " ";
            else cout << minv[i];
        }
        cout << endl;
    }
    return 0;
}
