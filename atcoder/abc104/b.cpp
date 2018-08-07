#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    bool ac = true;
    int count = 0; 
    int idx = 0;
    string S; cin >> S;
    if (S[0] != 'A') ac = false;
    REP(i, S.size()) {
        if (S[i] == 'C') {
            count++;
            idx = i;
        }
    }
    if (count != 1) ac = false;
    if (idx < 2 || S.size() - 3 < idx) ac = false;
    FOR(i, 1, S.size()) {
        if (i == idx) continue;
        else if(S[i] < 94) ac = false;
    }
    if (ac) cout << "AC\n";
    else cout << "WA\n";
    return 0;
}
