#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    string ans = "NO";
    if (N%3 == 0) ans = "YES";
    cout << ans << endl;
    return 0;
}
