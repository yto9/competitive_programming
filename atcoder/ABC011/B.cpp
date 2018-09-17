#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string S; cin >> S;
    FOR(i, 1, S.size()) S[i] = tolower(S[i]);
    S[0] = toupper(S[0]);
    cout << S << endl;
    return 0;
}
