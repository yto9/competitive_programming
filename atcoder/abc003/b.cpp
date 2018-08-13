#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string S,T; cin >> S; cin >> T;
    string ans = "You can win";
    REP(i, S.size()) {
        if (S[i] != T[i]) {
            if (S[i] != '@' && T[i] != '@') ans = "You will lose";
            else if(S[i] == '@') {
                if (T[i] != 'a' && T[i] != 't' && T[i] != 'c' && T[i] != 'o' && T[i] != 'd' && T[i] != 'e' && T[i] != 'r') ans = "You will lose";
            }
            else {
                if (S[i] != 'a' && S[i] != 't' && S[i] != 'c' && S[i] != 'o' && S[i] != 'd' && S[i] != 'e' && S[i] != 'r') ans = "You will lose";
            }
        } 
    }
    cout << ans << endl;
    return 0;
}
