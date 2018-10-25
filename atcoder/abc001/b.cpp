#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int m; cin >> m;
    int ans;
    if (m < 100) ans = 0;
    else if (m <= 5000) ans = m * 10 / 1000;
    else if (m <= 30000) ans = m / 1000 + 50;
    else if (m <= 70000) ans = (m - 30000) / 5000 + 80;
    else ans = 89;
    cout << setfill('0') << setw(2) << right << ans << endl;
    return 0;
}
