#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    ll n,k; cin >> n >> k;
    if (2 * n <= k) {
        cout << 0 << endl;
        return 0;
    }
    else {
        ll s,l;
        if (k <= 2 || n == 1) {
            cout << 0 << endl;
            return 0;  
        }
        if (k%2 == 0){
            s = k/2 - 1;
            l = k/2 + 1;
        }
        else {
            s = k/2;
            l = k/2 + 1;
        }
        cout << min(s, n - (l - 1)) << endl;
    }
    return 0;
}
