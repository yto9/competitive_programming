#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    REP(i, T) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        string ans = "YES";
        REP(j, n/2) {
            if (s[j] != s[n - 1 - j] && abs(s[j] - s[n - 1 -j]) != 2){
                ans = "NO";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
