#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    string a,b;
    ll n_0 = 0, n_1 = 0;
    ll N_0 = 0, N_1 = 0;
    cin >> a;
    cin >> b;

    REP(i,n){
        if (b[i] == '0') {
            if (a[i] == '0') n_0++;
            else n_1++;
        }
        if (a[i] == '0') N_0++;
        else N_1++;
    }
    ll ans = n_0 * N_1 + n_1 * N_0 - n_0 * n_1;
    cout << ans << "\n";
    return 0;
}
