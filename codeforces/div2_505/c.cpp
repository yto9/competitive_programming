#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string s; cin >> s;
    int res = 0;
    int count = 0;
    char pre = (s[0] == 'b') ? 'w':'b';
    REP(i, s.size()){
        if (pre == s[i]) {
            res = max(res, count);
            count = 1;
        }
        else {
            count++;
            pre = s[i];
        }
    }
    res = max(res,count);
    if(s[0] != s[s.size()-1]) {
        char pre = (s[0] == 'b') ? 'w':'b';
        int f = 0;
        int fc = 0;
        REP(i, s.size()){
            if (pre == s[i]) {
                f = max(0, fc);
                break;
            }
            else {
                fc++;
                pre = s[i];
            }
        }
        char post = (s[s.size()-1] == 'b') ? 'w': 'b';
        int p = 0;
        int pc = 0;
        REP(i, s.size()){
            if (post == s[s.size()-1 -i]) {
                p = max(0, pc);
                break;
            }
            else {
                pc++;
                post = s[s.size()-1 - i];
            }
        }
        res = max(res, min(fc + pc, (int)s.size()));
    }
    cout << res << endl;
    return 0;
}
