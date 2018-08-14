#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string S,T; cin >> S; cin >> T;
    string ans = "You can win";
    map<char,int> score_mp;
    score_mp['@'] = 10;
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r') {
            score_mp[c] = 1;
        }
        else score_mp[c] = 0;
    }
    REP(i, S.size()) {
        if (S[i] != T[i]) {
            if(score_mp[S[i]] + score_mp[T[i]] < 11)ans = "You will lose";
        } 
    }
    cout << ans << endl;
    return 0;
}
