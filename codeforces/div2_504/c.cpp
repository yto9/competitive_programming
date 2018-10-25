#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n,k; cin >> n >> k;
    string s; cin >> s;
    string ans = "";
    int num_del = (n - k)/2;
    REP(i, n) {
        ans += s[i];
        if(num_del > 0 && s[i] == ')'){
            ans.pop_back();
            ans.pop_back();
            num_del--;
        }
    }
    cout << ans << endl;
    return 0;
}
