#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int Q; cin >> Q;
    string ans = "";
    if (Q == 1) ans = "ABC";
    else if (Q == 2) ans = "chokudai";
    cout << ans << endl;
    return 0;
}
