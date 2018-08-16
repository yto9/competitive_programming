#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int A, B, C; cin >> A >> B >> C;
    char ans;
    if (A + B == C && A - B == C) ans = '?';
    else if (A + B == C) ans = '+';
    else if (A - B == C) ans = '-';
    else ans = '!';
    cout << ans << endl;
    return 0;
}
