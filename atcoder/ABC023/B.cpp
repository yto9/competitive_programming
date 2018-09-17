#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    string S; cin >> S;
    string ans = "b";
    int res = 0;
    for(res = 1; ans.size() < N; res++) {
        if (res % 3 == 1) ans = 'a' + ans + 'c';
        else if (res % 3 == 2) ans = 'c' + ans + 'a';
        else ans = 'b' + ans + 'b';
    }
    if (ans == S) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}
