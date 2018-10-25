#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    ll n;
    int q; cin >> n >> q;
    REP(i, q) {
        int x, y; cin >> x >> y;
        ll base = ((x + y) % 2) ? n*n / 2 + (n % 2 != 0) + 1 : 1;
        cout << base + (n * (x - 1) + (y - 1))/2 << endl;
    }
    return 0;
}
