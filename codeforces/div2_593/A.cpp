#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int t; cin >> t;
    REP(i, t) {
        int l, c, r; cin >> l >> c >> r;
        int res = 0;
        while(c >= 1 && r >= 2) {
            c--; r-=2;
            res += 3;
        }
        while(l >= 1 && c >= 2) {
            l--; c-=2;
            res += 3;
        }
        cout << res << endl;
    }

    return 0;
}
