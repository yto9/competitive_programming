#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string res = "AC\n";
    int cnt = 0; 
    string S; cin >> S;
    if (S[0] != 'A') res = "WA\n";
    FOR(i, 1, S.size()){
        if (isupper(S[i])){
            if (i == 1 || i == S.size() - 1 || S[i] != 'C'){
                res = "WA\n";
            }
            cnt++;
        }
    }
    if (cnt != 1) res = "WA\n";
    cout << res;
    return 0;
}
