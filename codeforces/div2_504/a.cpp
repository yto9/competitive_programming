#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n, m; cin >> n >> m;
    string s,t;
    cin >> s;
    cin >> t;
    string ans = "YES";
    auto apos = s.find("*");
    if (apos == string::npos){
        if (s != t) ans = "NO";
    } 
    else {
        REP(i, apos) {
            if (s[i] != t[i]) {
                ans = "NO";
                break;
            }
        }
        int num_rest_s = n - (apos + 1);
        if (m - apos < num_rest_s) ans = "NO";
        else {
            REP(i, num_rest_s) {
                if(s[n - i - 1] != t[m - i - 1]) {
                    ans = "NO";
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
