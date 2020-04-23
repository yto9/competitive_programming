#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll X; cin >> X;
    ll res = 0;
    res += (X / 500) * 1000;
    res += ((X % 500) / 5) * 5;
    cout << res << endl;
    return 0;
}
