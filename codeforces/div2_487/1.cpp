#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string s;cin >> s;
    int dx[3] = {-1 , 0 , 1};
    FOR(i, 1, s.size() -1) {
        int a = 0;
        int b = 0;
        int c = 0;
        for(auto x: dx) {
            if (s[i + x] == 'A') a++;
            if (s[i + x] == 'B') b++;
            if (s[i + x] == 'C') c++;
        }
        if (a*b*c > 0) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
