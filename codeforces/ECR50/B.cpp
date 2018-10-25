#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int q; cin >> q;
    REP(i, q) {
        ll n,m,k;
        cin >> n >> m >> k;
        ll res = 0;
        if (n > k || m > k) {
            cout << -1 << endl;
            continue;
        }
        if ((n + m) % 2 == 0) {
            res += max(n,m);
            k -= max(n,m);
            if (k % 2 == 0) res += k;
            else res += k - 2;
        }
        else {
            res = k - 1;
        }
        cout << res << endl;
    }
    return 0;
}
