#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string s; cin >> s;
    string ans = "";
    char pre = ' ';
    REP(i, s.size()) {
        if(s[i] != pre) {
            pre = s[i];
            ans += s[i];
            int cnt = 1;
            while(i < s.size() - 1 && pre == s[i + 1]) {
                i++;
                cnt++;
            }
            ans += to_string(cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
