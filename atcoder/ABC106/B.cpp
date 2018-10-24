#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    int d[201] = {};
    int ans = 0;
    for (int i = 1; i <= N; i+=2) {
        for (int j = 1; j <= i; j++) {
            if (i%j == 0) d[i]++;
        }
        if (d[i] == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}
