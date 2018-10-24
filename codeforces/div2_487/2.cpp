#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n,p;
    cin >> n >> p;
    string s; cin >> s;
    bool flag = false;
    REP(i, n - p) {
        if(s[i] == '.' || s[i + p] == '.') {
            flag = true;
            if (s[i] == '.') {
                if (s[i + p] == '1') s[i] = 0;
                else {
                    s[i] = '1';
                    s[i + p] = '0';
                }
            }
            else if (s[i] == '0') s[i + p] = '1';
            else s[i + p] = '0';
            break; 
        }
    }
    if (flag) {
        REP(i, n) {
            if (s[i] == '.') s[i] = '0';
        } 
        cout << s << '\n';
    }
    else cout << "No\n";
    return 0;
}
