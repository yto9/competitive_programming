#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int s[3],e[3];
    int sum = 0;
    REP(i, 3) {
        cin >> s[i] >> e[i];
        sum += s[i] * e[i] / 10;
    }
    cout << sum << endl;
    return 0;
}
