#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll l,r; cin >> l >> r;
    cout << "YES" << endl;
    for (ll i = l; i < r; i+=2) {
        cout << i << " " << i + 1 << endl;
    }
    return 0;
}
