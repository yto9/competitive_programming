#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int t; cin >> t;
    REP(test, t) {
        ll x, y; cin >> x >> y;
        if ((x-y) == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
