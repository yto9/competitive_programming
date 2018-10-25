#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string w; cin >> w;
    for (auto x: w) {
        if (x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o') continue;
        else cout << x;
    }
    cout << endl;
    return 0;
}
